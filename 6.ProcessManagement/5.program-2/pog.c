#include<stdio.h>
#include<stdlib.h>

int main(){
int pid_1;

printf("current process pid=%d\n", getpid());
pid_1=fork();  //child id sent parent
		//0 return child pro

if(pid_1==0){
//sleep(5);
printf("new child process pid=%d\n", getpid());
printf("new child parent process ppid=%d\n", getppid());
printf("pid returnde to child %d\n",pid_1);
}
else{
sleep(3);
printf("parent process pid = %d\n", getpid());
printf("parents parent process ppid = %d\n", getppid());//bash
printf("pid returnde to parent %d\n",pid_1);
}
while(1);
return 0;


}
