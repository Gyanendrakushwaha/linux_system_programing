#include<stdio.h>
#include<stdlib.h>
int main(){
int ret;
printf("I am going to exec an 'ls' program\n");
ret=execl("/bin/ps","ps","-elf",0);
printf("i executed is program %d\n",ret);

printf("i executed is program %d\n",ret);

printf("i executed is program %d\n",ret);


}
