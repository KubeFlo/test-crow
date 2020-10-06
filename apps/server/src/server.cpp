#include "third_party/crow/crow_all.h"
#include "third_party/getTimeOfDay/include/TimeStamp.h"
#include "third_party/Config/include/Config.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    crow::SimpleApp app;

    Config aConfig;

    aConfig.set(argv[1], argv[2]);
    TimeStamp atime;
    std::string aDate();
    CROW_ROUTE(app, "/")
    ([aConfig, atime]() {
        crow::json::wvalue aJson;
        aJson["Date"] = TimeStamp::process().c_str();
        aJson["ID"] = (rand() % 100);
        aJson["Message"] = aConfig.getMessage();
        return aJson;
    });

    if (aConfig.getPort() > 0)
    {
        app.port(aConfig.getPort()).multithreaded().run();
    }
    else
    {
        std::cout << "Init server pb : invalid port\n";
    }
}
