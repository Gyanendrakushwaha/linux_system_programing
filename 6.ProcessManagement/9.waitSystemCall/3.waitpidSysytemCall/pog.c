#include<sys/types.h> 
#include<sys/wait.h>


int main(){

pid_t chpid1 ,chpid2 , child1,child2;
int ii,stat;

printf("T am a processs my process id %d\n",getpid());
printf("I am creating two child processes & make them to run some code\n");


child1 = fork();
if(child1 == 0){

printf("I am first child, my pid is %d\n", getpid());
printf("I am tried, sleepig for 10 sec\n");

sleep(5);
exit(10);
}

child2 = fork();
if(child2 == 0){
printf("I am second child, my pid is %d\n",getpid());
printf("I am tired, sleeping for 5 sec.\n");
sleep(10);

exit(5);

}

printf("I am parernt, my childern are woreking & sleeping, i wait for them\n");
chpid2 = waitpid(child2,&stat,0);
printf("My 2nd child terminate satuts %d\n",WEXITSTATUS(stat));
printf("Terminat with child pid %d\n",chpid2);
/*if(chpid1 == child1){
      printf("child 1 terminate %d\n",WEXITSTATUS(stat));

}
if(chpid2 == child2){
      printf("child 2 terminate %d\n",WEXITSTATUS(stat));
}*/

chpid1 = waitpid(child1,&stat,0);

printf("My 1st child terminate satuts %d\n",WEXITSTATUS(stat));
printf("Terminat with child pid %d\n",chpid1);
/*if(chpid1 == child1){
        printf("child 1 terminate %d\n",WEXITSTATUS(stat));

}
if(chpid2 == child2){
        printf("child 2 terminate %d\n",WEXITSTATUS(stat));
}*/


printf("Both children got terminate, now i will the same\n");

}
