#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){

pid_t chpid ,chpid2 , child1,child2;
int ii,stat;

printf("I am a processs my process id %d\n",getpid());
printf("I am creating two child processes & make them to run some code\n");

child1 = fork();
if(child1 == 0){

printf("I am first child, my pid is %d\n", getpid());
printf("I am tired, sleepig for 10 sec\n");

sleep(10);
exit(10);

}

child2 = fork();
if(child2 == 0){

printf("I am second child, my pid is %d\n",getpid());
printf("I am tired, sleeping for 5 sec.\n");
sleep(5);
exit(5);
}

printf("I am parernt, my childern are working & sleeping, i wait for them\n");
chpid = wait(&stat);

if(chpid == child1){
printf("child 1 terminate %d\n",WEXITSTATUS(stat));

}
if(chpid == child2){
printf("child 2 terminate %d\n",WEXITSTATUS(stat));
}

/*
chpid = wait(&stat);

if(chpid == child1){
        printf("child 1 terminate %d\n",WEXITSTATUS(stat));

}
if(chpid == child2){
        printf("child 2 terminate %d\n",WEXITSTATUS(stat));
}
*/

printf("Both children got terminate, now i will the same\n");

}
