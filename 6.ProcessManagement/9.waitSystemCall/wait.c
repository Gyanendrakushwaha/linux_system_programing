#include<stdio.h>
#include<stdlib.h>

int main(){
int pid, stat;
pid=fork();

if(pid==0){
printf("\n CHILD PROCESS\n");
exit(0);
}
pid=wait(&stat);

printf("%d\n",pid);
printf("%d\n",getpid());
printf("%d\n",getppid());

printf("%d\n",WEXITSTATUS(stat));
}
