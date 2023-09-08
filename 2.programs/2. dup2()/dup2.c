#include<stdio.h>
#include<fcntl.h>

int main(){
int fd1,fd2,fd3,fd4;

fd1=open("linux.txt",O_WRONLY|O_CREAT|O_TRUNC, 0777); // here least available 3 will be alloacted to fd1
fd2=open("linuxnew.txt",O_WRONLY|O_CREAT|O_TRUNC, 0777); //4// here  next least available 4 will be alloacted to fd2
printf("fd1=%d\n",fd1);   //3
printf("fd2=%d\n",fd2);   //4

fd3=dup(fd1);  //5   //here normal dup will allocat next least available that is 5
printf("fd3_dup of fd1=%d\n",fd3);


//but if we want to allocate fd as of over choice the we need dup2() method

fd4=dup2(fd1,8); //8 // 
printf("fd4_dup of fd1=%d\n",fd4);


close(fd4);
close(fd3);
close(fd1);
close(fd2);
}
