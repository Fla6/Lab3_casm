FROM ubuntu

COPY main.cpp /home/lab3/main.cpp

COPY script.sh /home/lab3/script.sh

RUN apt-get update -y

RUN apt-get install -y g++

RUN apt-get install -y nano

RUN apt-get install -y --reinstall binutils

RUN apt-get install -y gdb
