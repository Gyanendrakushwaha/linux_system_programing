#include<stdio.h>
#include<fcntl.h>

int main(){
int fd1;
int fd2;


fd1= creat("this1.txt",777);
printf("fd returned by kernel is%d\n",fd1);

fd2= creat("this2.txt",777);
printf("fd returned by kernel is%d\n",fd2);


close(fd1);

close(fd2);
}
