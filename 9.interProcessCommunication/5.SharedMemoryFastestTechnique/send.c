#include<unistd.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
struct shmid_ds buf;
size_t s=20;
int sid;
sid=shmget(555,s,0666|IPC_CREAT); //create a shared memory and reurn shmid on succes and -1 on failure
printf("Sh mem ID : %d\n",sid);

int *atch;
atch=shmat(sid,0,0); //shmat function takes,shmid as first argument and attaches the specified shared memory segment to the process address space
printf("0x%x\n",atch);

int con;
con=shmctl(sid,IPC_STAT,&buf);//
			      //shmctl function on success return 0,and -1 on failure
printf("Control : %d\n",con); //con value would be 0

printf("size of shared memory : %d\n",buf.shm_segsz);
printf("\n\n");
exit(0);
}
