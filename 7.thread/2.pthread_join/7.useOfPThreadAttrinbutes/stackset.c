#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/mman.h>
void *Proc(void *param){
sleep(2);
return 0;
}

int main(){
pthread_attr_t Attr; //1 //declaration of variable
pthread_t ID;
void *Stk;
size_t Siz; //siz_T int 
int err;

size_t my_stksize=0x300000;
void * my_stack;

pthread_attr_init(&Attr); //2.// initialization of varible using function // pthread_attr_init(pthread_attr_t *ptr)
pthread_attr_getstacksize(&Attr, &Siz);//this function going to attr obj, fetching the size and storing in Siz int variable
//defalt stack size is 8mm ..pthd lib
pthread_attr_getstackaddr(&Attr, &Stk);//this function will go to attr object and fetch adress and store in Stk pointer

printf("Default Addr=%08x default size=%d\n",Stk,Siz);//we wont get thred address as thread not created out-siz=8 Stk addr=00
														 
my_stack=(void*)malloc(my_stksize); //ptr = malloc(100) is allocating memory of size my_stksize=0x3000000,and returning address to ptr my_stack 

//set function for setting address and size of stack
pthread_attr_setstack(&Attr, my_stack, my_stksize);//this time setting our new stack address and new stack size to out stack Attr

                       
 			//check //
//creating thread to confirm whether changes are reflected or not
pthread_create(&ID,&Attr,Proc,NULL); //creating thread

//gets stack Address & stack size
pthread_attr_getstack(&Attr,&Stk,&Siz);//going to stack Attr and fetching address and size and give print in next line

printf("newly defined stack : Addr=%08x and size=%d\n",Stk,Siz);
sleep(3);
return(0);
}
