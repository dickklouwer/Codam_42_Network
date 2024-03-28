#ifndef HTTPREQUEST__HPP
#define HTTPREQUEST__HPP

/* C/C++ Libs */
#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <memory>
#include <algorithm>
#include "Log.hpp"
#include "consts.hpp"
#include "string_utils.hpp"
#include "FormData.hpp"
#include "Config.hpp"

enum e_parse_status
{
    INCOMPLETE,
    COMPLETE,
    NA,
};

enum e_request_type
{
    UNDEF,
    RESOURCE,
    DIRECTORY,
    EXECUTABLE,
};

typedef struct s_uri_comps
{
    std::string raw_path;
    std::string path;
    std::string query_str;
    std::string executable_name;
    std::string path_info;
    std::string rederection_path;
} t_uri_comps;

class HttpRequest
{
public:
    class RequestEntityTooLarge : public std::exception
    {
        std::string exc;

    public:
        RequestEntityTooLarge(){};
        RequestEntityTooLarge(std::string what_arg) : exc(what_arg){};
        const char *what() const throw() { return exc.c_str(); };
        ~RequestEntityTooLarge() throw(){};
    };

    class invalidRequest : public std::exception
    {
        std::string exc;

    public:
        invalidRequest(){};
        invalidRequest(std::string what_arg) : exc(what_arg){};
        const char *what() const throw() { return exc.c_str(); };
        ~invalidRequest() throw(){};
    };

public:
    class requestTimedOut : public std::exception
    {
        std::string exc;

    public:
        requestTimedOut(){};
        requestTimedOut(std::string what_arg) : exc(what_arg){};
        const char *what() const throw() { return exc.c_str(); };
        ~requestTimedOut() throw(){};
    };

public:
    class InvalidMethodException : public std::exception
    {
        std::string exc;

    public:
        InvalidMethodException(){};
        InvalidMethodException(std::string what_arg) : exc(what_arg){};
        const char *what() const throw() { return exc.c_str(); };
        ~InvalidMethodException() throw(){};
    };

private:
    std::shared_ptr<ServerBlock> config;
    std::shared_ptr<LocationBlock> _location;

private:
    e_parse_status request_line_parse_status;
    e_parse_status request_headers_parse_status;
    e_parse_status request_msg_body_parse_status;
    e_request_type request_type;

private:
    std::string raw_request;
    t_uri_comps uri_comps;
    std::map<std::string, std::string> cookies;
    std::map<std::string, std::string> request_line;
    std::map<std::string, std::string> request_headers;
    std::string request_message_body;
    FormData form_data;

private:
    std::shared_ptr<LocationBlock> getMatchingLocation(std::string path);
    std::string constructPath(std::string raw_path);

public:
    HttpRequest();
    HttpRequest(std::shared_ptr<ServerBlock> config);
    HttpRequest(const HttpRequest &obj);
    HttpRequest operator=(const HttpRequest &obj);
    ~HttpRequest();

public:
    bool parseRequest(char *request_buff, std::size_t parse_size);
    void flushBuffers();
    std::string getValueFormQueryStr(const std::string &key);
    void safeUserData();
    void printParsedContent() const;

private:
    void parseRequestLine(const std::string &raw_request);
    void parseRequestUri(const std::string &uri);
    void parseHeaders(const std::string &raw_request);
    void parseMessageBody(const std::string &raw_request);
    std::string getCgiExtension(const std::string &s);
    // bool isAcceptedCgiExt(LocationBlock &location, std::string ext);
    void parseRequestType();
    std::string getExecutableName(const std::string &file_extension, const std::string &path);

public:
    std::string getRequestLineComp(const std::string &request_line_el) const;
    t_uri_comps getUriComps() const;
    std::string getHeaderComp(const std::string &header_name) const;
    std::string getMessageBody() const;
    std::shared_ptr<ServerBlock> getServerConfig() const;
    std::shared_ptr<LocationBlock> getServerLocation() const;
    e_request_type getType() const;
    const FormData &getFormDataObj() const;
    bool isParsed() const;
    bool hadSessionId() const;
    std::string getRedirectLocation() const;
};

std::ostream &operator<<(std::ostream &os, const HttpRequest &obj);

#endif