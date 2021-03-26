FROM ubuntu
RUN apt-get update && apt-get upgrade -y
RUN apt install  build-essential -y
RUN apt install nasm -y
RUN apt-get install gcc-multilib -y
COPY matrix_with_asm.c .
COPY matrixfill.asm .
RUN nasm -felf matrixfill.asm
RUN gcc -m32 matrix_with_asm.c matrixfill.o -o matrix_exe
CMD ./matrix_exe
