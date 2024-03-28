#include "HttpResponse.hpp"

HttpResponse::HttpResponse(const HttpResponse &obj)
{
    (void)obj;
}

HttpResponse HttpResponse::operator=(const HttpResponse &obj)
{
    (void)obj;
    return *this;
};

HttpResponse::HttpResponse() : _httpVersion("HTTP/1.1"){};

HttpResponse::~HttpResponse() {}

void HttpResponse::setBody(const std::string &body)
{
    _body = body;
}

void HttpResponse::setHeaders(const std::string &key, const std::string &value)
{
    _headers[key] = value;
}

void HttpResponse::setStatusLine(const std::string &statusline)
{
    _statusLine = statusline;
}

void HttpResponse::setStatusLineAndBody(const std::string &statusline, const std::string &body)
{
    setStatusLine(statusline);
    setBody(body);
}

std::string HttpResponse::getHeader(const std::string &headerName) const
{
    return _headers.at(headerName);
}

std::string setCookie(const std::string &cookie_name, const std::string &cookie_value, const std::string &path, int lifetimeMinutes = 0)
{
    std::string cookie = "Set-Cookie: " + cookie_name + "=" + cookie_value;
    if (path != "")
        cookie += "; Path=" + path;
    cookie += "; Secure; HttpOnly; ";
    if (lifetimeMinutes > 0)
    {
        std::time_t now = std::time(nullptr);
        std::time_t expiration = now + lifetimeMinutes * 60;
        std::string expirationStr = std::asctime(std::gmtime(&expiration));
        expirationStr.pop_back();
        cookie += "Expires=" + expirationStr + " GMT";
    }
    return cookie + CRLF;
}

std::string generateSessionID(int length)
{
    std::string result;

    srand(time(nullptr));
    result.reserve(length);
    for (int i = 0; i < length; ++i)
    {
        result += CHARSET[rand() % CHARSET.length()];
    }
    return result;
}

std::string HttpResponse::generateResponse(HttpRequest &request)
{
    Log::logMsg("Response generated, ready to sent");
    std::string response;

    if (request.getRedirectLocation() != "")
    {
        Log::logMsg("Redirecting to " + request.getRedirectLocation());
        response = "HTTP/1.1 301 Moved Permanently" + CRLF;
        response += "Location: " + request.getRedirectLocation() + TWO_CRLF;
        std::cout << CGRY << response << NC << std::endl;
        return response;
    }
    response += _statusLine;
    if (!request.hadSessionId())
        response += setCookie("sessionID", generateSessionID(64), "/", 2);
    setHeaders("Content-Length", std::to_string(_body.size()));
    for (const auto &header : _headers)
    {
        response += header.first + ": " + header.second + CRLF;
    }
    response += CRLF;
    std::cout << CGRY << response << NC << std::endl;
    response += _body;
    try
    {
        if (getHeader("Content-Type").find("text/html") != std::string::npos)
            std::cout << CGRY << _body << NC << std::endl;
        else
            std::cout << CGRY << "[Raw bits]" << NC << std::endl;
    }
    catch (const std::exception &e)
    {
        (void)e;
    }
    return response;
}