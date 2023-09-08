#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){

int fd1,fd2,fd3,fd4;

fd1=open("linux.txt",O_WRONLY,0777);
fd2=open("linuxnew.txt",O_WRONLY,0777);
printf("fd1=%d\n",fd1);
printf("fd2=%d\n",fd2);

fd3=dup(fd1);
printf("fd3 dup of fd1=%d\n",fd3);

fd4=dup2(fd1,10);
printf("%d",fd4);

}
