#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>

int main(){
char *c;
c=mmap(0,512,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_PRIVATE, -1,0); //msg success
perror("mmap");

strcpy(c,"linuxkernel"); //kernel region in u.s.
printf("%s\n",c);
/* deallocate all resources*/
munmap(c,50);//malloc after free

//printf("%s\n",c);
return 0;


}
