#include "httpStatus.hpp"

std::unordered_map<statusCode, std::string> httpStatus::_message = {
	{statusCode::OK, "OK"},
	{statusCode::created, "Created"},
	{statusCode::accepted, "Accepted"},
	{statusCode::no_content, "No Content"},
	{statusCode::temp_redir, "Temporary Redirect"},
	{statusCode::not_modified, "Not Modified"},
	{statusCode::bad_request, "Bad Request"},
	{statusCode::unauthorized, "Unauthorized"},
	{statusCode::forbidden, "Forbidden"},
	{statusCode::not_found, "Not Found"},
	{statusCode::method_not_allowed, "Method Not Allowed"},
	{statusCode::request_timeout, "Request Timeout"},
	{statusCode::length_required, "Length Required"},
	{statusCode::payload_too_large, "Payload Too Large"},
	{statusCode::uri_too_long, "URI Too Long"},
	{statusCode::unsupported_type, "Unsupported Media Type"},
	{statusCode::internal_server_error, "Internal Server Error"},
	{statusCode::not_implemented, "Not Implemented"},
	{statusCode::bad_gateway, "Bad Gateway"},
	{statusCode::service_unavailable, "Service Unavailable"},
	{statusCode::gateway_timeout, "Gateway Timeout"}};

std::string httpStatus::getStatusLine(statusCode code)
{
	return (version + " " + std::to_string(static_cast<int>(code)) +
			" " + _message.at(code)) +
		   CRLF;
	return (version + " " + std::to_string(static_cast<int>(code)) +
			" " + _message.at(code)) +
		   CRLF;
}

std::string httpStatus::generateErrResponse(statusCode code)
{
	std::string response = httpStatus::getStatusLine(code);

	const auto &message = httpStatus::_message.at(code);

	std::string body = "<html><head><title>" + message +
					   "</title></head><body><h1>" + message + "</h1></body></html>";
	response += "Content-Type: text/html\r\n";
	response += "Content-Length: " + std::to_string(body.length()) + "\r\n";
	response += "Connection: close\r\n\r\n";

	response += body;
	std::cout << response << "\r\n\r\n";
	return response;
}

statusCode httpStatus::errnoToStatusCode(int err)
{
	switch (err)
	{
	case 0:
		return statusCode::OK;
	case EACCES:
	case EPERM:
		return statusCode::forbidden;
	case ENOENT:
		return statusCode::not_found;
	case ETIMEDOUT:
		return statusCode::request_timeout;
	case EOVERFLOW:
		return statusCode::payload_too_large;
	case ENAMETOOLONG:
		return statusCode::uri_too_long;
	case ENOSYS:
		return statusCode::not_implemented;
	case ECONNRESET:
	case EHOSTUNREACH:
	case ECONNREFUSED:
		return statusCode::bad_gateway;
	case EAGAIN:
		return statusCode::service_unavailable;
	default:
		return statusCode::internal_server_error;
	}
}