#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
int sharedVar;   //our shared variable
int i; 		
sem_t my_sem;	//create semaphore

void *thread_inc1(void *arg){
sem_wait(&my_sem); //takes semaphore
for(i=0;i<100000;i++){
sharedVar++;   //critical section
}
sem_post(&my_sem);  //release semaphore
}

void *thread_inc2(void *arg){
sem_wait(&my_sem);  //take semaphore
	           //take mutex
for(i=0;i<100000;i++){
sharedVar++;
}
sem_post(&my_sem);  //release semaphore
}

int main(){
pthread_t thread1,thread2;
sem_init(&my_sem,0,1); //initialize semaphore

pthread_create(&thread1,NULL,thread_inc1,NULL);
pthread_create(&thread2,NULL,thread_inc2,NULL);

pthread_join(thread1,NULL);
pthread_join(thread2,NULL);

printf("sharedVar =%d \n",sharedVar);
return 0;

}
