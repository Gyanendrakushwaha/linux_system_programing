//atexit function causes the specified function to be caaled at the progeam termination. 

#include<stdio.h>
#include<stdlib.h>

void callback1(void){
printf("callback1 func called\n");

}
void callback2(void){
printf("callback2 func called\n");
}
void callback3(void){
printf("callback3 func called\n");
}

int main(){
printf("registering callback\n");
atexit(callback1);  //atexit();  //here the function caalled first int atexit will execute at extreme end

printf("registering callback\n");
atexit(callback2);

printf("registering callback3\n");
atexit(callback3);

printf("main()..exiting now\n");

exit(0);
}
 // here first callback3 execute 
 // then callback2 
 //then callback1

