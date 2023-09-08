#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
int fd;
char buf[300];

fd=open("mxfds.c",O_CREAT|O_RDWR,664);
printf("%d\n",fd);

read(fd,buf,300);

printf("data from buffer =%s\n",buf);
close(fd);
return 0;
}
