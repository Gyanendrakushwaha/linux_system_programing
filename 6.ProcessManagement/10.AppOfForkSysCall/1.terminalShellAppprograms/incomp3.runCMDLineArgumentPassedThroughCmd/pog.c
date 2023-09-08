#include<stdio.h>
#include<stdlib.h>
int main(){
int ret;
printf("I am going to exec an Command line args\n");

ret=execl("/home/vboxuser/Desktop/linuxSystemProgramming/6.ProcessManagement/10.AppOfForkSysCall/2.terminalShellAppprograms/3.runCMDLineArgumentPassedThroughCmd","./cmd","linux","kernel","driver","program",0);

printf("i executed ls program %d\n",ret);

}
