#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

struct msgbuf{ //user defined structure to pack data and type
//we are packaging msg data into struct type data
long mtype; //type field 
char data[512]; //actual data to send to process
};

int main(int argc,char *argv[]){
struct msgbuf v;  //v is variable to user defined structure object
int id;

id=msgget(55,IPC_CREAT|0644); //msgegt to create new msg queue ,if msg queue with this key 55 is not there it will create,if it present it just give the access to this queueu
                                            //on success it returns msg id
printf("id = %d\n",id);			    
v.mtype=atoi(argv[1]);   //as 11 will be stored in char argv[1] so converting to integer
strcpy(v.data,argv[2]);   // copy data field from cmd line to object v's data filld
msgsnd(id,&v,strlen(v.data)+1,0); //sending msg data in form of char array v, size of data is also given, 

return 0;	

}
