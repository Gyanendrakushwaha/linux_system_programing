 #include<unistd.h>
 #include<fcntl.h>
   #include<stdio.h>
 int main(){
 int fd;
 char buf[100]="this is new text edited from practice";
 fd =open("linuxabc.txt",O_CREAT|O_RDWR,0777);
 write(fd,buf,100);
 
 close(fd);
 return 0;
 
 
 }

