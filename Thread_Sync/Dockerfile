FROM ubuntu
RUN apt-get update && apt-get upgrade -y
RUN apt install build-essential -y
RUN apt-get install gcc-multilib -y
COPY Trigramms.cpp input.txt /
RUN g++ -pthread Trigramms.cpp -o trigramms
