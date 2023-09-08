#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
int fd;
char buf[50]="this is sample code";

char read_buf[50];


fd=open("linux.txt",O_CREAT|O_RDWR, 777);

write(fd,buf,50);

read(fd,read_buf,50);
printf("%s",read_buf);
close(fd);
return 0;
}
