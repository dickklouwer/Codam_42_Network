#ifndef CLIENTSOCKET_HPP
#define CLIENTSOCKET_HPP

/* C/C++ Libs */
#include <stdexcept>
#include <exception>
#include <chrono>

/* Webserv */
#include "Socket.hpp"
#include "HttpRequest.hpp"
#include "HttpResponse.hpp"
#include "errors.hpp"
#include "Log.hpp"
#include "SysCall.hpp"

class ClientSocket : public Socket
{

public:
    class HungUpException : public std::exception
    {
        std::string exc;

    public:
        HungUpException(){};
        HungUpException(std::string what_arg) : exc(what_arg){};
        const char *what() const throw() { return exc.c_str(); };
        ~HungUpException() throw(){};
    };

private:
    bool is_request_parsed;
    HttpRequest request;
    HttpResponse response;

private:
    std::string _request_buff;
    std::string connection;
    std::chrono::steady_clock::time_point last_activity;

public:
    enum class State
    {
        Reading,
        Writing
    } state = State::Reading;

    ClientSocket(int fd, std::shared_ptr<ServerBlock> config);
    ~ClientSocket(void);

    void updateLastActivity();
    bool hasTimedOut();
    void setConnection(std::string status) { connection = status; }
    void setState(State newState) { state = newState; }
    State getState() const { return state; }
    std::string getConnection() const { return connection; }
    const HttpRequest &getRequest() const { return request; }
    HttpResponse &getResponse() { return response; }
    std::string getRequestBuff() const { return this->_request_buff; }
    bool getIsParsed() const { return this->is_request_parsed; }

    void recvRequest();
    void sendResponse();
    void sendErrResponse(std::string response);
};

#endif