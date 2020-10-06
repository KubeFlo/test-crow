#include <curl/curl.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <thread>

int main(int argc, char *argv[])
{
      std::string url = "http://localhost:";
    bool isLooping = false;
    int aMsec = 1000;
    if (argv[1])
    {
        url.append(argv[1]);
    }
    else
    {
        std::cout << "please provide a valide port\n";
        exit(1);
    }
    if (argv[2])
    {
        isLooping = true;
        aMsec = atoi(argv[2]);
    }

    std::cout << "query send on " << url << std::endl;
    auto curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    do
    {
        curl_easy_perform(curl);
          std::this_thread::sleep_for(std::chrono::milliseconds(aMsec));
    } while (isLooping);
}