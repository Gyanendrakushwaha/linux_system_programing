#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
int fd3;
fd3=open("file.txt",O_CREAT|O_RDWR,0777);
printf("this is from one.c %d\n",fd3);

while(1);
close(fd3);
return 0;
}
