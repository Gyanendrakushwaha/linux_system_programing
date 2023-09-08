#include<fcntl.h>

int main(){
int fd;
fd=open("dumpdemo.txt",O_RDWR|O_CREAT|O_TRUNC,0660);  //this will create and open dumpdemo.txt file and store address in least availbale fd -3


//error check if file is not opened
//fd=3
if(fd<0){
printf("could not open file\n");
exit(2);
}

//here fd 1 is by default used for terminal screen but in the next step we are storing file address of (dumpdemo.txt) in fd 1
//so that print statements would not be displayed on screen but would be stored in the file(dumpdemo.txt).
dup2(fd,1);

printf("sample string one\n");

printf("sample string two\n");

printf("sample string three\n");
}
