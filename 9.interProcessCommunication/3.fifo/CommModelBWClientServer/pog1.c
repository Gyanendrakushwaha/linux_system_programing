
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>

if(cnt == 0)
break;
printf("Received message\n");
toggleCase(buf,cnt);
cliFd=open("clififo",O_WRONLY);
if(cliFd)
{
printf("Sent responses messages\n");
write(cliFd,buf,cnt);
close(cliFd);
}
else{
printf("Could not open client fifo\n");
}
}
close(srvFd);
}
}


void toggleCase(char *buf,int cnt)
{
int ii;
for(ii=0;ii<cnt;ii++){
if((buf[ii] >= 'A') && (buf[ii] <= 'Z'))
	buf[ii] += 0x20;
else if((buf[ii] >= 'a')&& (buf[ii] <= 'z'))
	buf[ii] -= 0x20;
}
}
