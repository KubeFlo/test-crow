# test-crow

# create a volume
``` bash
docker volume create <your_volume_name>
```
# run Centos7 with docker
``` bash
sudo docker run -it --name <your_container_name> -v <your_volume_name> centos:7 /bin/bash
```
## if your container stopped 
 ``` bash
docker container start <your_container_name>
docker exec -ti Centos7 /bin/bash
```
# setup your container (TODO create a DockerFile)
 ``` bash
 yum install git
 yum install boost-devel
 yum groupinstall 'Development Tools' // equivalent to 'build essential' on debian
```
# build
``` bash
git clone https://github.com/kubeCorn/test-crow.git
cd test-crow
mkdir dist
g++ -o ./dist/server ./src/server.cpp  -lboost_system -lpthread -std=c++11
```
# if you want to test from ssh make sure ssh is active on the host
``` bash
in VBox : Conf/network/NAT -> advanced port fowarding : ssh | TCP | 127.0.0.1  | <IP_VM> | 2522
systemctl ssh status // active(running)
also verify response from ping 8.8.8.8 -> ok you are connected to the wwweb
```
# test in docker
``` bash
dist/server &
curl http://localhost:18080
```
