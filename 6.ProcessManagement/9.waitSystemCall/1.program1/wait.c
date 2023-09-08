//wait is usually used in parent process so that wait parent to terminate child process first.
//if wait is used in child then it will wait for its own child
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
int pid, stat;
printf(" parent pid %d\n",getpid());
pid=fork();

if(pid==0){
sleep(3);
printf("\n CHILD PROCESS is executing before parent due to wait\n");
printf("child pid is %d\n",getpid());
printf("childs parent pid is %d\n",getppid());
exit(0);
}
else{

pid=wait(&stat);

printf("%d\n",pid);

printf("%d\n",getpid());
printf("%d\n",getppid());
}
printf("%d\n",WEXITSTATUS(stat));
}
