#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
int fd,len;
char write_buf[50]="hi , how are you";
char read_buf[50];

fd=open("linux.txt",O_CREAT | O_RDWR, 777);   //CFO

len=write(fd, write_buf,50); //50 return ,curr file off moved 50 h location
							////here in write operation the offset has moved to 50 th location
printf("return value from write optn=%d\n", len); //50


read(fd,read_buf,len);    //as the current file offset has moved to 50th location so now read operation will not return anything as nothing is there to read after the 50th 							  //location. so we are reading garbage and storig that garbage in empty read_buf
printf("data from buffer(read optn)=%s\n",read_buf); // we are printfing read_buf garbage
														//printf("%d\n",len);											
close(fd);
return 0;

}
