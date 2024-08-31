#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	struct{
		int trainNumber;
		int ticketCount;
	}data[3];
	for(int i =0;i<3;i++){
		data[i].trainNumber = i+1;
		data[i].ticketCount = 0;
	}
	int fd = open("ticketBooking.txt",O_RDWR|O_CREAT,0744);
	write(fd,&data,sizeof(data));
	close(fd);

}
