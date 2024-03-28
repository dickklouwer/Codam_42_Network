#include "HttpRequest.hpp"

t_uri_comps HttpRequest::getUriComps() const
{
	return uri_comps;
}

std::string HttpRequest::getRequestLineComp(const std::string &key) const
{
	return request_line.at(key);
}

std::string HttpRequest::getHeaderComp(const std::string &key) const
{
	return request_headers.at(key);
}

bool HttpRequest::isParsed() const
{
	return (request_line_parse_status == COMPLETE &&
			request_headers_parse_status == COMPLETE &&
			(request_msg_body_parse_status == NA ||
			 request_msg_body_parse_status == COMPLETE));
}

const FormData &HttpRequest::getFormDataObj() const
{
	return form_data;
}

e_request_type HttpRequest::getType() const
{
	return request_type;
}

std::shared_ptr<ServerBlock> HttpRequest::getServerConfig() const
{
	return config;
}

std::shared_ptr<LocationBlock> HttpRequest::getServerLocation() const
{
	return _location;
}
