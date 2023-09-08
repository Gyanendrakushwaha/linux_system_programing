#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
int fd,len;
int x;
char write_buf[60]="new LINUX kernel new program?, wow";
											
fd=open("new LINUXabc.txt",O_CREAT | O_RDWR, 0777); 

write(fd,write_buf,60);
close(fd);
return 0;
}
