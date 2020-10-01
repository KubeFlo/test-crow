#include "third_party/crow/crow_all.h"
#include "third_party/getTimeOfDay/include/TimeStamp.h"
#include <stdlib.h>  
#include <stdio.h>
#include <time.h>      
int main(int argc, char *argv[])
{
     srand (time(NULL));
    crow::SimpleApp app;
    int aPort = atoi(argv[1]);
    const char * aMessage = "...";
     TimeStamp atime;
    std::string aDate();
    if(argc == 3){
    aMessage =argv[2];
    }
    CROW_ROUTE(app, "/")
    ([aMessage,atime]()   {
        crow::json::wvalue aJson;
        aJson["Date"] =TimeStamp::process().c_str();
        aJson["ID"] = (rand() % 100);
        aJson["Message"] = aMessage;
            return aJson;
    });

    if(aPort > 0){
    app.port(aPort).multithreaded().run();
    } else {
       std::cout << "Init server pb : invalid port\n";
    }
}