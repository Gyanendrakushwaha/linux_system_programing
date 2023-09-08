#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
int p[2]; //p[0],p[1] indexex or subscripters of array p

pipe(p); //fd0 -- p[0]rd end and fd1---- p[1] wt end
printf("Read end of pipe=%d \t Write end of pipe =%d\n",p[0],p[1]); //3 ,4
if(fork()){
//parent
char s[20];
printf("in parent Enter Data...\n");
scanf("%s ",s); //wait user enter "15 +1"
write(p[1],s,strlen(s)+1); //parent send data on pipe.... write(fd,buf,20)
}
else{
//child -- 0
char buf[20];
printf("In Child...\n");
read(p[0],buf,sizeof(buf)); //block .... child collect data
printf("child pro printing... Data. of the parent process..%s\n",buf);
}
return 0;
}
