#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
int get_semaphore(void);
int release_semaphore(void);
int sem_id;

struct sembuf sem_op;

int main(){
int i;
sem_id=semget((key_t)1234,1,0666|IPC_CREAT);


if(semctl(sem_id,0,SETVAL,1)<0)
printf("error\n");

for(i=0;i<=5;i++){
get_semaphore();
printf("%d:got the semaphore\n",getpid());
sleep(1);
printf("%d:released the semaphore\n",getpid());
release_semaphore();
sleep(1);
}

if(semctl(sem_id,0,IPC_RMID,0)<0)
printf("Failed to delete the semaphore");

else
printf("Semaphore deleted");

}

int get_semaphore(void)
{
sem_op.sem_num=0;

//gets the nth no of segment specified in sem_num, here its 0,thatis the zeroth in the semaphore array 
sem_op.sem_op=-1;

//decrements the nth semaphore by one 
//the nth value is specified by the variable sem
sem_op.sem_flg=0;



if(semop(sem_id,&sem_op,1)<0)
{
printf("Failed to get the semaphore\n");
return -1;
}
return 0;
}


//giving the semaphore means +1 opearaiotn
int release_semaphore(void)
{
sem_op.sem_num=0;
sem_op.sem_op=1;//same as above but here instead of incrimenting we are decrementing the semaphore tomreleases it
sem_op.sem_flg=0;
if(semop(sem_id,&sem_op,1)<0)
{
printf("Failed to release semaphore\n");
return -1;
}

return 0;
}
