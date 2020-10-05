# test-crow
``` bash
.
├── apps
│   ├── client
│   │   ├── BUILD
│   │   └── src
│   │       └── client.cpp
│   └── server
│       ├── BUILD
│       └── src
│           └── server.cpp
├── LICENSE
├── README.md
├── src
│   ├── crow_all.h
│   └── server.cpp
├── third_party
│   ├── boost.bzl
│   ├── BUILD
│   ├── BUILD.boost
│   ├── crow
│   │   ├── BUILD
│   │   └── crow_all.h
│   ├── deps.bzl
│   └── getTimeOfDay
│       ├── BUILD
│       ├── include
│       │   └── TimeStamp.h
│       └── src
│           └── TimeStamp.cpp
└── WORKSPACE

```
# setup
you need to install curl to build the client app
``` bash
sudo yum install libcurl-devel
``` 

# build
``` bash
git clone https://github.com/kubeCorn/test-crow.git
cd test-crow
bazel build //apps/server:crow_server_bin
bazel build //apps/client:crow_client_bin

```
# create image
``` bash
bazel run //apps/server:server_image
bazel run //apps/client:client_image


```
# push image
``` bash
bazel run //apps/server:server_push
bazel run //apps/client:client_push

```
## [optional] if you want to test from ssh tunnel make sure ssh is active on the host
``` bash
in VBox : Conf/network/NAT -> advanced port fowarding : ssh | TCP | 127.0.0.1  |  2522 | <IP_VM> | 22
systemctl ssh status // active(running) if not installed ( try sudo yum –y install openssh-server openssh-clients ) 
also verify response from ping 8.8.8.8 -> ok you are connected to the wwweb
```

# test on port 8080 with "hello world" message
``` bash
./crow_server 8080 "hello world" //terminal 1
./crow_client 8080 // terminal 2  
```
``` console
response in Terminal1 : {"Message":"hello world","ID":57,"Date":"Thu Oct  1 11:09:26 2020\n"}
```


```
```
# Test with image
``` bash 
for now the port is hard coded in the image
docker run -d -p 9080:9080 crow/apps/server:v1 9080 yourMessage
docker run --net=host --rm  crow/apps/client:v1 9080


