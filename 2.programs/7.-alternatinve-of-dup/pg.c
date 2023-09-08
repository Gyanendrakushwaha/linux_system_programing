#include<stdio.h>
#include<fcntl.h>

int main(){

int fd1,fd2,fd3;

fd1=open("linux.txt",O_WRONLY|O_CREAT|O_TRUNC, 0777); //

fd3 = fcntl(fd1,F_DUPFD,55);

printf("duplicate value of fd1 is fd3= %d\n",fd3);

close(fd1);
close(fd3);

}
