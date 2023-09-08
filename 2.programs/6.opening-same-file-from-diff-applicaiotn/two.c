#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
int fd2;
fd2=open("file.txt",O_CREAT|O_RDWR,0777);
printf("this is from one.c %d\n",fd2);

while(1);
close(fd2);
return 0;
}
