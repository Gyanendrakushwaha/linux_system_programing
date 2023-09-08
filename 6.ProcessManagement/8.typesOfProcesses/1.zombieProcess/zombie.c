#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
pid_t p;
p=fork();
if(p==0){
printf("I am child my pid is %d\n",getpid());
printf("I am child my parent pid id %d\n",getppid());
}
else{
sleep(3);
printf("I am parent my pid is %d",getpid());
printf("my child pid id %d",getppid());
}

//while(1);
}
