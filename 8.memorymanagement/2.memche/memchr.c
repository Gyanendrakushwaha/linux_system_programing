#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
const char str[]="linuxkernel.com";
const char ch='.';
char *ret;

ret = memchr(str,ch,strlen(str));
printf("String after **%c** is - **%s**\n",ch,ret+1);

return 0;

}
