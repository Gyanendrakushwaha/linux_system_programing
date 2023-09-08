#include<stdio.h>
#include<stdlib.h>
int main(){
char *args[3];
printf("I am going to exec an 'ls' program is current process\n");


args[0]="ls";
args[1]="-l";
args[2]=0;
execv("/bin/ls",args);
printf("I have run an execv program\n");
}
