#ifndef HTTPSTATUS_HPP
#define HTTPSTATUS_HPP

/* C/C++ Libs */
#include <string>
#include <exception>
#include <unordered_map>
#include <stdexcept>
#include <iostream>

/* Webserv */
#include "consts.hpp"

enum class statusCode
{
	OK = 200,
	created = 201,
	accepted = 202,
	no_content = 204,
	temp_redir = 302,
	not_modified = 304,
	bad_request = 400,
	unauthorized = 401,
	forbidden = 403,
	not_found = 404,
	method_not_allowed = 405,
	request_timeout = 408,
	length_required = 411,
	payload_too_large = 413,
	uri_too_long = 414,
	unsupported_type = 415,
	internal_server_error = 500,
	not_implemented = 501,
	bad_gateway = 502,
	service_unavailable = 503,
	gateway_timeout = 504
};

class httpStatus
{
private:
public:
	static statusCode errnoToStatusCode(int err);
	static std::unordered_map<statusCode, std::string> _message;
	static std::string getStatusLine(statusCode code);
	static std::string generateErrResponse(statusCode code);
};

#endif