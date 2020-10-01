# test-crow
``` bash
test-crow
├── LICENSE
├── README.md
├── src
│   ├── client.cpp
│   ├── crow_all.h
│   └── server.cpp
├── third-party
│   └── getTimeOfDay
│       ├── BUILD
│       ├── include
│       │   └── TimeStamp.h
│       └── src
│           └── TimeStamp.cpp
└── WORKSPACE
```
# setup
you need curl to build the client app
``` bash
sudo yum install libcurl-dev
``` 

# build
``` bash
git clone https://github.com/kubeCorn/test-crow.git
cd test-crow
bazel build --cxxopt=-std=c++11 //apps/server:crow_server
bazel build --cxxopt=-std=c++11 //apps/client:crow_client
```
## [optional] if you want to test from ssh tunnel make sure ssh is active on the host
``` bash
in VBox : Conf/network/NAT -> advanced port fowarding : ssh | TCP | 127.0.0.1  |  2522 | <IP_VM> | 22
systemctl ssh status // active(running)
also verify response from ping 8.8.8.8 -> ok you are connected to the wwweb
```

# test on port 8080 with "hello world" message
``` bash
./crow_server 8080 "hello world" //terminal 1
./crow_client 8080 // terminal 2  
```
``` console
response : {"Message":"hhello world","ID":57,"Date":"Thu Oct  1 11:09:26 2020\n"}
```
