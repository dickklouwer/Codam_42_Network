#ifndef REQUESTPROCESSOR__HPP
#define REQUESTPROCESSOR__HPP

/* C/C++ Libs */
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <csignal>
#include <iostream>
#include <fstream>

/* Webserv */
#include "errors.hpp"
#include "consts.hpp"
#include "string_utils.hpp"
#include "SysCall.hpp"
#include "HttpRequest.hpp"
#include "errors.hpp"
#include "Config.hpp"
#include "Log.hpp"

class RequestProcessor
{
public:
	static std::string executeCgi(const t_uri_comps &uri);
	static void uploadFiles(const FormData &form_data);
	static std::string listDirectoryContent(const t_uri_comps &uri);
};

#endif
