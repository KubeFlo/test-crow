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
mkdir dist
g++ -o ./dist/server ./src/server.cpp  -lboost_system -lpthread -std=c++11
```
# test 
``` bash
dist/server &
curl http://localhost:18080
```
