#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *PrintHello(void *threadid){
printf("\n Hello world\n");

printf("\n I am writing\n");
while(1);    //here while loop is kept to make the thread in infinite mode


}

int main(){
pthread_t thread;
int rc,t=0;
printf("Creating thread %d\n",t);
rc=pthread_create(&thread, NULL, PrintHello,NULL); //here creating a thread to print hello
printf("\n Thread ID: %u",thread);

sleep(6);  //here the parent process is wainting for 6 sec
t=pthread_cancel(thread);  //here the thread cancel is called,to terminate infinite ongoing thread, it will return 0 on success and -1 on failure
if(t==0) printf("\n canceled thread \n");
printf("\n Thread ID: %u\n",thread);
}
