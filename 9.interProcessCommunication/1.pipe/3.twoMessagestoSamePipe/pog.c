#include<unistd.h>
int main(){
int fds[2];
int res,i;
char *buf1="aaaaaaaaaaaaaaaaaaaa";
char *buf="bbbbbbbbbbbbbbbbbbbb";
char buf2[40];
res =pipe(fds);

//fds[0] for reading and fds[1] for writting
if(res == -1){
perror("pipe");
exit(1);
}
write(fds[1],buf1,20);
write(fds[1],buf,20);

read(fds[0],buf2,40);

for(i=0;i<40;i++)
printf("%c",buf2[i]);
printf("\n");

}
