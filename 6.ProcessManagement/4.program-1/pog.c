#include<stdio.h>
#include<stdlib.h>

void main(){
int pid;
//printf("%d",pid);
pid=fork();

printf("%d\n",pid);


//child process
if(pid==0){
printf("1\n");

printf("2\n");


}
//parent process
else{

printf("3\n");

printf("4\n");

}


while(1);
}
