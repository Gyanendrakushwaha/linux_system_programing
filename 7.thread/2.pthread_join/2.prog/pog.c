#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

void *th_fn(void *p);

int fd;
int main(){
pthread_t t1,t2;
fd=open("/etc/passwd",O_RDONLY);    //1//file open
printf("File opened with fd: %d \n",fd);   //2//file created succesfully
pthread_create(&t1,NULL,th_fn,"Thread One");  //3// creating two thread  "Thread One" is the argument passed
pthread_create(&t2,NULL,th_fn,"Thread Two");  //4//creating thread

pthread_join(t1,NULL);							  //
pthread_join(t2,NULL);


}

void *th_fn(void *p){  //5 // "Thread One" is passed to void *p
char *str, buff[100];

int n,pid;
str=(char *)p;   //6  //void p is type casted to char 
pid=getpid();   // 7// getpid will have the process id which created thread
printf("%s: \t started Now: \t For process %d \n\n",str,pid);   

do{                         //this do will read from file passwd and write to terminal 
n=read(fd,buff,100);    //reading from password file, address in fd , and store data in buff, and return 100.  
printf("%s: \t Read: \t %d \n\n",str,pid);
printf("\n--------------\n");

write(1,buff,n);         // this will write buff data to terminal.

printf("\n-------------\n");
sleep(3);                //wait for 3 sec
}
while(n);                // as n value was 100 
printf("%s: \t Finished: \t For Process %d \n\n",str,pid);


}
