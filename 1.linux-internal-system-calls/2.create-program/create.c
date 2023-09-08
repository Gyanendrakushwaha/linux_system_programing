#include<stdio.h>
#include<fcntl.h>
 int main(){

	int fd1, fd2, fd3;
	fd1=creat("linux1.txt",777);
	fd2=creat("linux2.txt",777);
	fd3=creat("linux3.txt",777);
	////fd3=open("linux_xyz.txt",O_WRONLY,777); //OPEN() API// SYSYTEM CALLS
	printf("fd returned by kernel for linux111.txt =%d\n",fd1);//3
	printf("fd returned by kernel for linux111.txt =%d\n",fd2);//4
	printf("fd returned by kernel for linux111.txt =%d\n",fd3);//5
	close(fd1);
	close(fd2);
	close(fd3);
 }
