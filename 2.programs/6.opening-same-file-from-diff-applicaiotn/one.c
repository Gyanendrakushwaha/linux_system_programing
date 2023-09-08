#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
int fd1;
fd1=open("file.txt",O_CREAT|O_RDWR,0777);
printf("this is from one.c %d\n",fd1);

while(1);
close(fd1);
return 0;
}
