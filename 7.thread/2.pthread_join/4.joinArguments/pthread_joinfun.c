#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *thr_fn1(void *arg){
printf("thrd1 returning\n");
printf("THD ID=%u\n",pthread_self());

return ((void*)1);

}

void *thr_fn2(void *arg)
{
printf("thread 2 existing\n");
printf("THD ID= %u\n",pthread_self());
pthread_exit((void*)2);
}


int main(void){
int err;
pthread_t tid1,tid2; //here var create
void *tret;
pthread_create(&tid1,NULL,thr_fn1,NULL); //this will create 1st thread using fun thr_fn1 and store the thread id in tid, with NULL arguments

pthread_create(&tid2,NULL,thr_fn2,NULL);//this will create 2nd thread using fun thr_fn1 and store the thread id in tid, with NULL arguments
pthread_join(tid1,&tret);                        //this will wait for thread with thread id tid1 to complete and store the status in tret that is passed from the thr_fn1 that is 1
printf("thread1 exit code %d\n",(int)tret);   //print the tret status 
 
pthread_join(tid2,&tret);                        //this will wait for thread with thread id tid2 to complete and store the status in tret
sleep(10);									//sleep for 40 sec
printf("thread2 exit code %d\n",(int)tret);
exit(0);
}
