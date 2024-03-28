#ifndef SERVERSOCKET_HPP
#define SERVERSOCKET_HPP

/* C/C++ Libs */
#include <netinet/in.h>
#include <stdexcept>
#include <memory>

/* Webserv */
#include "Socket.hpp"
#include "ClientSocket.hpp"
#include "Log.hpp"
#include "Config.hpp"
#include "SysCall.hpp"
#include "errors.hpp"

class ServerSocket : public Socket
{
public:
    ServerSocket();
    ServerSocket(std::shared_ptr<ServerBlock> config);
    ServerSocket(const ServerSocket &obj);
    ~ServerSocket();

public:
    void createSocket();
    void bindPort(int port);
    void listenPort(int backlog, int port);
    void recvRequest();
    void sendResponse();
    std::shared_ptr<ClientSocket> acceptConnection();
};

#endif