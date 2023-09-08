#include<sys/shm.h>
#include<stdio.h>
#include<string.h>

int main(){
char *ptr;
int shmid,pid;

//create shared memory segment read
shmid=shmget((key_t)1,20,IPC_CREAT|0666);

//attach pointer to shared memory area
ptr=(char*)shmat(shmid,(char*)0,0); //if flag not used then it is by default read and write

pid=fork();
if(pid==0){
//copy data in the child process
strcpy(ptr,"shared memory\n");
}
else{
wait(0); //wait child to execute
//
printf("parent reads  ....%c\n",*(ptr+2));
printf("parent reads  %s\n",ptr);

}
}
