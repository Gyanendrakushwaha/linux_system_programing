#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<bits/local_lim.h>
main(){
pthread_attr_t tattr;
pthread_t tid;
int ret;
void *stackbase;
int size = PTHREAD_STACK_MIN + PTHREAD_STACK_MIN;
size_t size1;
stackbase = (void *)malloc(size);

//initialize with default attributes
ret = pthread_attr_init(&tattr);
ret = pthread_attr_getstacksize(&tattr,&size1);
printf("\n Default stack size %u :",size1);
printf("\n Thread Minimum stack size %u :\n",PTHREAD_STACK_MIN);
//seting ghe size of the stack also
ret = pthread_attr_setstacksize(&tattr,size);

ret = pthread_attr_setstacksize(&tattr,size);
printf("\n User Stack size %u :\n",size1);

}
