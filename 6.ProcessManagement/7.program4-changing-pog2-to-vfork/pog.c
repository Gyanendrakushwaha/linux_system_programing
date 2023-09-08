#include<stdio.h>
#include<stdlib.h>

int main(){
int pid_1;

printf("current process pid=%d\n", getpid());
pid_1=vfork();  //vfork will stop parents execution and first allow child to execute even if child is in sleep
				//0 return child pro

if(pid_1==0){

sleep(3);
printf("new child process pid=%d\n", getpid());
printf("new child parent process ppid=%d\n", getppid());
_exit(EXIT_SUCCESS);
}

else{
printf("parent process pid = %d\n", getpid());
printf("parents parent process ppid = %d\n", getppid());//bash
}
while(1);
return 0;
}
