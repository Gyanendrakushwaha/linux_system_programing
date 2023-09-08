#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>

struct msgbuf{
long mtype;
char data[512];
};

int main(int argc,char **argv){
int id;
struct msgbuf v;

if(argc!=2){
printf("usage: ./msg_rx type \n");
printf("Example: mq_rx 5\n");
return 0;
}
id-msgget(55,IPC_CREAT|0644);//msgget(key,perm);
if(id<0){
perror("msgget");
return 0;
}
msgrcv(id,&v,sizeof(v),atoi(argv[1]),0); 
//4th argument is typefield specifies which message to fetch from the message queue.
//typefield = 0 if typefiled is 0 while executing will fetch message in first in first out order.
//iftypefiled >0 will fetch the msg with given type field

//if the typefilds are repeated will fetch the message with first occurance typecase
printf("Data %s\n",v.data);
return 0;
}
