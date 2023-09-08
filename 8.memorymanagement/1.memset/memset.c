#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
const char str[]="linuxkernel.com";
const char ch='#';

printf("String before set/initialization is %s \n",str);
memset(str,ch,5); 			//memset is used to initialize or fill  a block of memory 
							//with particular given value for a given size.

printf("String after set is %s\n",str);

return(0);

}
