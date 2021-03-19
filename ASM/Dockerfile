FROM centos
RUN yum check-update yum update -y
copy nasm.rpm .
run dnf -y install nasm.rpm
run dnf -y install gcc
copy lr2c.c .
copy lr2s.asm .
run gcc -o execc lr2c.c -s
run nasm -g -f elf lr2s.asm; ld -m elf_i386 -s -o execs lr2s.o
