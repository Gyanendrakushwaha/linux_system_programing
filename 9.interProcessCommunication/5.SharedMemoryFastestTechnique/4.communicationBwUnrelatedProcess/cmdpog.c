//if communication has to be performed bw unrelated process then mandatory id is required

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main(int argc,char *argv[]){
char *p;
int id;
id=shmget(48,250,IPC_CREAT|0644);  //
if(id<0){
perror("shmget");
return 0;
}

printf("id=%d\n",id);
p=shmat(id,0,0);   //PAS ---User Space
p=argv[1];
printf("%s\n",p);

return 0;
}
