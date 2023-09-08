#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>


int main(){
char buff[30];
int n;

write(1,"this is written to fd number1\n",31);

write(1,"enter a line of text\n",21);
n=read(0,buff,80);  //here having doubt the string should move from buff to 0,but here moving 0 to buff
write(1,"Following is the line i read\n",29);
write(1,buff,n);
}
