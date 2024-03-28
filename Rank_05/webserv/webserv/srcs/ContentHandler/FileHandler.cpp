#include "FileHandler.hpp"

#define ERROR "<html><body><h1>404 Not Found</h1></body></html>"

bool fileHandler::isValidPath(std::string &file_path)
{
    return std::filesystem::exists(file_path);
}

std::filesystem::path fileHandler::getAbsolutePath(const std::string &file_path_input, const std::string &root_input)
{
    std::string file_path = file_path_input;
    if (!file_path.empty() && file_path[0] == '/')
        file_path.erase(0, 1);

    std::string root = root_input;
    if (!root.empty() && root.back() == '/')
        root.pop_back();

    if (file_path.substr(0, root.length()) == root)
    {
        file_path = file_path.substr(root.length());
        if (!file_path.empty() && file_path[0] == '/')
            file_path.erase(0, 1);
    }

    std::filesystem::path cwd = std::filesystem::current_path();
    std::filesystem::path absolute_path = cwd / root / file_path;

    return absolute_path;
}

bool fileHandler::deleteResource(const std::string &file_path)
{
    Log::logMsg("Handling DELETE request");

    try
    {
        std::filesystem::remove_all(file_path);
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        std::string error_message = "Filesystem error: " + std::string(e.what());
        Log::logMsg(error_message);
        throw std::runtime_error(error_message);
    }

    Log::logMsg("File(s) deleted from server: " + file_path);
    return true;
}

bool fileHandler::isDirectory(std::string &file_path)
{
    struct stat buffer;
    return (stat(file_path.c_str(), &buffer) == 0 && S_ISDIR(buffer.st_mode));
}

bool fileHandler::isFile(std::string &file_path)
{
    struct stat buffer;
    
    return (stat(file_path.c_str(), &buffer) == 0 && S_ISREG(buffer.st_mode));
}

std::string fileHandler::readFileContent(const std::string &file_path)
{
    std::ifstream file(file_path);
    if (!file.is_open())
    {
        Log::logMsg("Error opening file");
        throw std::runtime_error("Failed to open file " + file_path);
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

std::string getContentType(const std::string &file_path)
{
    std::string extension = file_path.substr(file_path.find_last_of(".") + 1);
    if (extension == "html")
        return "text/html";
    if (extension == "php")
        return "text/html";
    if (extension == "css")
        return "text/css";
    if (extension == "js")
        return "text/javascript";
    if (extension == "ico")
        return "image/x-icon";
    if (extension == "jpeg")
        return "image/jpeg";
    if (extension == "png")
        return "image/png";
    if (extension == "gif")
        return "image/gif";
    if (extension == "pdf")
        return "application/pdf";
    if (extension == "zip")
        return "application/zip";
    return "text/plain";
}

void fileHandler::serveDirectoryListing(const HttpRequest *req, HttpResponse *res)
{
    std::string content;
    res->setHeaders("Content-Type", "text/html");
    if (req->getServerLocation()->getAutoIndex() == "on")
        content = RequestProcessor::listDirectoryContent(req->getUriComps());
    else
        content = fileHandler::readFileContent("srv/www/auto_index_off.html");
    res->setStatusLineAndBody(httpStatus::getStatusLine(statusCode::OK), content);
}

void fileHandler::handleExecutableRequest(const HttpRequest *req, HttpResponse *res)
{
    res->setHeaders("Content-Type", "text/html");
    res->setStatusLineAndBody(httpStatus::getStatusLine(statusCode::OK),
                            RequestProcessor::executeCgi(req->getUriComps()));
}

void fileHandler::serveStaticFile(const std::string& file_path, HttpResponse *res)
{
    res->setHeaders("Content-Type", getContentType(file_path));
    std::string content = fileHandler::readFileContent(file_path);
    res->setStatusLineAndBody(httpStatus::getStatusLine(statusCode::OK), content);
}

void fileHandler::handleErrorResponse(int errorCode, const HttpRequest *req, HttpResponse *res)
{
    std::string root_dir = req->getServerConfig()->getRoot();
    std::string content_type = getContentType(req->getUriComps().path);
    if (content_type.find("image") != std::string::npos)
    {
        res->setHeaders("Content-Type", content_type);
        res->setStatusLineAndBody(httpStatus::getStatusLine(statusCode::not_found),
                                  fileHandler::readFileContent(root_dir + "www/404.jpg"));
    }
    else
    {
        Log::logMsg("File not found: " + req->getUriComps().path);
        res->setHeaders("Content-Type", "text/html");
        std::string error_page = req->getServerConfig()->getErrorPage(errorCode);
        Log::logMsg("Try to use the error page in config: '" + error_page + "'");
        if (isFile(error_page))
        {
            Log::logMsg("Error page found in config");
            res->setStatusLineAndBody(httpStatus::getStatusLine(statusCode::not_found),
                                    fileHandler::readFileContent(error_page));
        }
        else
        {
            Log::logMsg("Error page nog found, using default error page");
            res->setStatusLineAndBody(httpStatus::getStatusLine(statusCode::not_found), ERROR);
        }
    }
}
