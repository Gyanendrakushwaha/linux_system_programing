//in this program creating shared memory, creating and setting semaphores to acces shared memory
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<string.h>

#define MY_KEY 1992
#define SHM_SIZE 0x1000
//#define MSG_LEN 256
//#define RESP_MEG_START 256

int main(){
int semId, shmId;
char *pShm;
struct sembuf smop;

semId=semget(MY_KEY,1,0660|IPC_CREAT);

if(semId <0)
{
printf("Could not create semaphore\n");
return(1);
}
else{
printf("opened a semaphore ID is %d\n",semId);
}

//set initial token count of both semaphores to zeroes
semctl(semId,0,SETVAL,0);

shmId =shmget(MY_KEY,SHM_SIZE,0660|IPC_CREAT);
if(shmId<0)
{
printf("Could not create shared segment \n");
return (2);
}
pShm = shmat(shmId,NULL,0);
if(!pShm)
{
printf("Could not attach shared memory segment.\n");
return (3);
}
//wait for a token semaphore 0
smop.sem_num=0;
smop.sem_op=-1;
smop.sem_flg=0;

semop(semId,&smop,1); //server is blocked on semaphore
		      //once cli ecext semop(inc cntr by 1)
		      //server gets unblocked......
//process the message available in shared memory
printf("Got the semaphore\n");
printf("%s\n",pShm);
}
