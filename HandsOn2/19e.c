/*
============================================================================
Name : 1c.c
Author : Dora Bhavya Rishitha
Description :19. Create a FIFO file by
e.mkfifo library function
Date: 21st Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
void main(){
	const char *path ="fifofile";
	mode_t mode = 0666;
	int errno = mkfifo(path,mode);
	if(errno == -1){
	perror("Error:");
	printf("FAILURE");
	}else{
	printf("SUCCESS");
	}
}

/*
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 19e.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
SUCCESS
*/