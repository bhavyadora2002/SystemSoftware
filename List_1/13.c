/*
============================================================================
Name : 13.c
Author : Dora Bhavya Rishitha
Description :13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 29th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<sys/time.h>
#include<sys/select.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	fd_set readfds;
	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO,&readfds);
	struct timeval timeout;
	timeout.tv_sec = 10;
	timeout.tv_usec = 0;
	int val = select(STDIN_FILENO+1,&readfds,NULL,NULL,&timeout);
	if(val == -1)
		perror("ERROR:");
	else if(val == 0)
		printf("Cannot find data within 10 seconds");
	else{
		if(FD_ISSET(STDIN_FILENO,&readfds)){
		char buff[100];
		read(STDIN_FILENO,buff,sizeof(buff));
		printf("Data Entered is %s",buff);
		}
		}
	return 0;
}

/*
============================================================================
OUTPUT:bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 13.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Hii
Data Entered is Hii
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Cannot find data within 10 seconds
============================================================================
*/
