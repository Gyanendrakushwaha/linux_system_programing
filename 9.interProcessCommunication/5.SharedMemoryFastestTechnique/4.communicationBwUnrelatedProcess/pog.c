//if communication has to be performed bw unrelated process then mandatory id is required

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main(){
char *p;
int id;
id=shmget(48,250,IPC_CREAT|0644);  //
if(id<0){
perror("shmget");
return 0;
}

printf("id=%d\n",id);
p=shmat(id,0,0);   //PAS ---User Space
scanf("%s",p);
printf("%s",p);
while(1);
return 0;
}
