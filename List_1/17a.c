/*
============================================================================
Name : 17a.c
Author : Dora Bhavya Rishitha
Description : 17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit.
Date: 29th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(){
	int fd;
	struct{
		int ticketno;
	}data;
	data.ticketno= 1;
	fd=open("TicketList",O_CREAT|O_RDWR,0744);
	write(fd,&data,sizeof(data));
	close(fd);
	fd = open("TicketList",O_RDONLY);
	read(fd,&data,sizeof(data));
	printf("Ticket Number is %d\n",data.ticketno);
	close(fd);
}

/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Ticket Number is 1
============================================================================
*/


