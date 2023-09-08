#include<stdio.h>
#include<string.h>
int main(){
int fds[2],ii,n;   //file descriptors for pipe 
char readbuf[100]; //to store data
char writebuf[100]; //to write data 

if(pipe(fds) <0) //here pipe is created, a pipe needs a 2 element array,both elements are for fd of write and read.
{
perror("pipe creation failed\n");
}

//2.//child process
if(fork()==0)
{
close(fds[1]); //close of write fd because child is not having use of write fd of pipe,this fd is closed to increase performance.
while(1)
{
n=read(fds[0],readbuf,100); //reading data from read fd of pipe and  writing on char array readbuf
printf("Read from fds[0] and output to screen:\n");
// printing data of readbuf
for(ii=0;ii<n;ii++)
readbuf[ii]=toupper(readbuf[ii]);
puts(readbuf);
}
}

//1.//parent process
close(fds[0]); //close of read fd because parent is not having use of read fd of pipe,this fd is closed to increase performance.
while(1)
{
fgets(writebuf,100,stdin);//getting data from keayboad and eriting to writebuf
write(fds[1],writebuf,strlen(writebuf)+1); //write operation to pipe is done by parent process,getting data from writebuf and 
                                          //writing on write fd fds[1] of pipe
printf("Wrote to fds[1]:\n");             //msg of write  
}

}
