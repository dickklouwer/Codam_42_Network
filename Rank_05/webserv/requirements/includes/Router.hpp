#pragma once

/* C/C++ Libs */
#include <string>
#include <vector>
#include <regex>

/* Webserv */
#include "RequestHandler.hpp"

class Router
{

    struct Route
    {
        std::string request_method;
        void (*callback)(const HttpRequest *, HttpResponse *);
    };

    std::vector<Route> routes;

public:
    Router();
    ~Router(){};
    void registerRoute(std::string request_method, void (*callback)(const HttpRequest *, HttpResponse *));
    void routeRequest(const HttpRequest &req, HttpResponse &);
};
