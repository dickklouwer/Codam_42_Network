#include "RequestProcessor.hpp"
#include "FileHandler.hpp"

std::string RequestProcessor::listDirectoryContent(const t_uri_comps &uri)
{
	std::string rootdir = uri.path;
	DIR *dir = SysCall::opendir(rootdir.c_str());
	std::vector<struct dirent *> dirent_list = SysCall::listdir(dir);
	std::string dirlist =  "<body>";

	std::string html =	"<!DOCTYPE html><html lang=\"en\"><head>"
						"<meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
						"<title>Document</title></head>";

	for (struct dirent *dir : dirent_list)
	{
		std::string dirname = dir->d_name;
		std::string fname = dir->d_name;

		std::string dir_abspath = joinPath({rootdir, dirname}, "/");
		if (fileHandler::isDirectory(dir_abspath))
		{
			fname = "📁 " + fname;
			dirname += "/";
		}
		else
		{
			fname = "📄" + fname;
		}
		dirlist += "<a href=\"" + dirname + "\">" + fname + "</a>" + "<br>\n";
	}
	dirlist += "</body>";

	html += dirlist;
	html += "</html>";
	return html;
}