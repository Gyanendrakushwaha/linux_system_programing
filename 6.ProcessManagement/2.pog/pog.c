#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
printf("my process pid =%d\n",getpid());

printf("my parent process pid =%d\n",getppid());

printf("linux kernel\n");
while(1);
return 0;

}
