#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>

int main(){
int fd,i;
char *c;
struct stat file_info;
fd=open("kernel.txt", O_CREAT|O_RDWR,0777); //creting and opening a file kernel.txt
write(fd, "linux kernel Technology",25);    //writing on the file some string
fstat(fd,&file_info); //fstat used to access file information,stored in the object file_info
printf("File size is %d\n",file_info.st_size);//here file_info is object and st_size is member.


c=mmap(0,file_info.st_size,PROT_READ,MAP_PRIVATE,fd,0); 
//1st argument is address-where we want to map,here it is 0,as we are asking the kernel to map at free location on processor address space
//2. 2nd argument is the size that we want to map
//3. read or write operation
//4. nature of mapping
//5. fd
//6. file offset
//here mmap will map memory of size st_size on process address space and 
perror("mmap");
for(i=0;i<=16;i++)
printf("%s\n",c); //no need of accessing system call for file read write

/* deallocate all resources*/
munmap(c,file_info.st_size);  //munmap is used to free the memory
close(fd);
return 0;

}
