#include<sys/shm.h>
#include<stdio.h>
#include<string.h>

#define SIZE 20
int main(){
char *ptr;
int shmid,pid,i;

//create shared memory segment ,id stored in shmid
shmid=shmget((key_t)1,20,IPC_CREAT|0666); //creation

//attach pointer to shared memory area
ptr=(char*)shmat(shmid,(char*)0,0); //if flag not used then it is by default read and write

pid=fork();

//check 
if(pid==0){
//read data to STDOUT
i=read(0,ptr,SIZE); //ptr is shared memory segment ,child dumping data here in ptr,and returning 
if(i==-1)
{
printf("\nRead failed");
}
else{
printf("child reads %s\n",ptr);
}
}
else{

wait(0); //wait child to execute
write(1,ptr,SIZE); //
printf("parent reads  ....%s\n",ptr);
//destroys the memory
shmctl(shmid,IPC_RMID,NULL); //finally removing shared memory id
}
}
