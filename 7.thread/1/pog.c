#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
pthread_t tid;

void *thread1(void *arg){
sleep(1);
printf("newly created thread is executing\n");
return NULL;
}

int main(void){						//pthread_t *ptr
int ret=pthread_create(&tid,NULL, thread1, NULL);       //addr
if(ret)
{
printf("Thread is not created\n");
}
else{
printf("Thread is created\n");
}


pthread_join(tid,NULL);   //this function waits for termination of thread with id tid
return 0;
}
