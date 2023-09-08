#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[]){
long int page_size = sysconf(_SC_PAGESIZE);//sysconf provides details of system resources,_SC_PAGESIZE provides the pagesize

printf("My page size: %ld\n",page_size);

void* c1=sbrk(0);  //sbrk(0) will return current breakpoint
printf("program break address: %p\n",c1);//printing break point
printf("sizeof char: %lu\n",sizeof(char)); //print the size of char

c1=((char*) c1+1);  //we are increasing this pointer to next location,means now heap will increase
printf("c1: %p\n",c1);//now printing the brek ponit
int ret = brk(c1);
void* c2=sbrk(0); //againg calling sbrk(0) to access the break point
printf("program break address: %p\n",c2);//printing breakpoint
}
