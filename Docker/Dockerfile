FROM centos
RUN yum check-update yum update -y
COPY mySH .
RUN touch test1.txt test2.txt test3.txt test4.txt
RUN chmod +x mySH
CMD ./mySH
