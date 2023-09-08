#include<stdio.h>
#include<fcntl.h>
#define BUF_SIZE 1024

int main(){
int inputFD, outputFD, openFlags;
mode_t filePerms;
ssize_t numRead;
char buf[BUF_SIZE];

inputFD = open("fileA.txt",O_RDONLY);  //fileA opening in readonly operation

if(inputFD==-1){  //return -1 on failure //error checking
printf("open error\n");
return;
}

outputFD = open("fileB.txt",O_RDWR,777); //fileB opended in read and write
if(outputFD==-1){  //return -1 on failure
printf("opening file\n");
return;
}


//transfer data until we encounter end of input or an error
while((numRead = read(inputFD,buf,BUF_SIZE))>0){  //here 100 bytes will be copied from inputFD to buf and no of bytes read would be stord in numREad
if(write(outputFD, buf ,numRead)!=numRead){       // here buf data is copied from buf to outputFd location
printf("write error\n");
return;
}
printf("%d\n",numRead);
}


if(numRead==-1){
	printf("Read Error\n");
	return;
}
if(close(inputFD)==-1){
printf("close input\n");
return;
}
if(close(outputFD)==-1){
printf("close output\n");
return ;
}
return 0;
}
