#include "ClientSocket.hpp"

ClientSocket::ClientSocket(int fd, std::shared_ptr<ServerBlock> config) : request(config), response()
{
    this->fd = fd;
    this->pfd = (t_pollfd){fd, POLLIN | POLLOUT, 0};
    this->config = config;
    this->last_activity = std::chrono::steady_clock::now();
}

ClientSocket::~ClientSocket()
{
    ::close(fd);
}

void ClientSocket::updateLastActivity()
{
    last_activity = std::chrono::steady_clock::now();
}

bool ClientSocket::hasTimedOut()
{
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - last_activity);
    if (elapsed.count() > getRequest().getServerConfig()->getTimeOut())
    {
        Log::logMsg("Connection timed out", fd);
        return true;
    }
    return elapsed.count() > getRequest().getServerConfig()->getTimeOut();
}

void ClientSocket::recvRequest()
{
    char request_buff[10240]; // 10kb buffer size
    int bytes_received = SysCall::recv(fd, request_buff, sizeof(request_buff), 0);

    if (bytes_received == 0)
    {
        request.flushBuffers();
        Log::logMsg("Connection hung up", fd);
        throw ClientSocket::HungUpException();
    }
    is_request_parsed = request.parseRequest(request_buff, bytes_received);
    try {
        setConnection(request.getHeaderComp("Connection"));
    }
    catch (const std::out_of_range &e)
    {
        setConnection("close");
    }
    Log::logMsg("request received", fd);
    if (is_request_parsed)
    {
        request.printParsedContent();
        request.safeUserData();
        setState(State::Writing);
    }
}

void ClientSocket::sendResponse()
{
    if (!is_request_parsed)
    {
        return;
    }
    std::string _response = response.generateResponse(request);
    int bytes_sent = send(fd, _response.c_str(), _response.size(), 0);
    if (bytes_sent < 0)
    {
        request.flushBuffers();
        throw std::runtime_error("accept: " + STRERR);
    }
    request.flushBuffers();
    is_request_parsed = false;
    Log::logMsg("response sent", fd);
    setState(State::Reading);
}

void ClientSocket::sendErrResponse(std::string response)
{
    int bytes_sent = send(fd, response.c_str(), response.size(), 0);
    if (bytes_sent < 0)
    {
        request.flushBuffers();
        throw std::runtime_error("accept: " + STRERR);
    }
    request.flushBuffers();
    is_request_parsed = false;
    Log::logMsg("error response sent", fd);
    setState(State::Reading);
}
