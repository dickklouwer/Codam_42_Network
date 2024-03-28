#ifndef REQUEST_HANDLER_HPP
#define REQUEST_HANDLER_HPP

/* Webserv */
#include "FileHandler.hpp"

void handleGetRequest(const HttpRequest *req, HttpResponse *res);
void handlePostRequest(const HttpRequest *req, HttpResponse *res);
void handleDeleteRequest(const HttpRequest *req, HttpResponse *res);

#endif