#include<stdio.h>
#include<fcntl.h>


int main(){
int fd;
char read_buf[50];
char buf[50]="this is test text to be kept";
fd=open("linux_kernel2.txt",O_CREAT|O_RDWR,777);

int len=write(fd,buf,50); //this write function will return 50 the last offset position

printf("the offset position %d\n",len); 

read(fd,read_buf,50);
printf("\n %s",read_buf);
}
