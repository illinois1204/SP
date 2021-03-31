FROM ubuntu
RUN apt-get update && apt-get upgrade -y
RUN apt install build-essential -y
RUN apt-get install gcc-multilib -y
COPY parent.cpp child.cpp input.txt /
RUN g++ child.cpp -o child; g++ parent.cpp -o parent
