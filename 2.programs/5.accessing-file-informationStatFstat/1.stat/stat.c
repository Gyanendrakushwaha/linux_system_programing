#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
struct stat st; //here a variable of struct stat is created to store the file informtion
int fd;   //fd is to store the location if file

stat("fcntl.c",&st);   //stat function is used to access the file information
					//this stat(), first goes to the file (fcntl.c) then it access the file information then it stores te file information in  the same type variable creted as (st)

printf("file size   =%lu\n",(st.st_size));

printf("file inode =%lu \n",st.st_ino);
printf("size disc of blocks =%lu \n",st.st_blksize);

printf("\n\n");
close(fd);
return 0;

}
