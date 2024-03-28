#include "Router.hpp"

Router::Router() 
{
    registerRoute("GET", &handleGetRequest);
    registerRoute("POST", &handlePostRequest);
    registerRoute("DELETE", &handleDeleteRequest);
}

void    Router::registerRoute(std::string request_method,
            void (*callback)(const HttpRequest*, HttpResponse*))
{
    routes.push_back({request_method, callback});
}

void    Router::routeRequest(const HttpRequest& req, HttpResponse& res)
{
    Log::logMsg("Routing the request");
    std::string method = req.getRequestLineComp("method");    
    for (const auto& route : routes) 
    {
        if (method == route.request_method)
        {
            route.callback(&req, &res);
            return ;
        }
    }
    throw std::runtime_error("Unknown method: " + method);
}