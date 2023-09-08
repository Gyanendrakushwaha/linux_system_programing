#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
int fd;
char buf[300];
int res;
fd=open("mxfds.c", O_CREAT|O_RDWR, 664);
printf("%d\n",fd);		//3
if(fd<0)
	printf("File is not opened or created\n");
read(fd,buf,300);

printf("data from buffer =%s\n",buf);
close(fd);
return 0;
}
