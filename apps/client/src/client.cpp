#include <curl/curl.h> 
#include <string>
#include <iostream>
#include <stdio.h> 
int main(int argc, char *argv[])
{
    std::string url = "http://localhost:";
    if(argc == 2){
       url.append(argv[1]); 
    } else {
        std::cout << "please provide a valide port\n" ;
        exit(0);

    }
    std::cout << "query send on " << url << std::endl;
    auto curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_perform(curl);
}