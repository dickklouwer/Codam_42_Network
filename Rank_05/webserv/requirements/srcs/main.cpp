#include "WebServer.hpp"

int main(int argc, char *argv[])
{
    try
    {
        Config config(argc, argv);
        WebServer server(config);
        server.startService();
    }
    catch (const std::exception &e)
    {
        Log::logMsg(e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
