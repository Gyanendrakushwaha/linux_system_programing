#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
char buff[30];
int n;
write(1,"this is written to fd number 1",31);

write(1,"enter text",31);
n=read(0,buff,80);

write(1,"following is the result of read\n",40);
write(1,buff,n);
}
