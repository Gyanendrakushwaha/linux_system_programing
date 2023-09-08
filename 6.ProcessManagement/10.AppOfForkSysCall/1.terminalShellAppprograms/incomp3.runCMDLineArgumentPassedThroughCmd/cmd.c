#include<stdio.h>
#include<stdlib.h>


int main(int argc,char *argv[]){

int i;
printf("\n File name: %s\n",argv[0]);

printf("\n Total number of arguments: %d",argc);
printf("Arguments passed\n");

for(i=1;i<argc;i++){
printf("%s",argv[i]);
printf("\n");
}

}
