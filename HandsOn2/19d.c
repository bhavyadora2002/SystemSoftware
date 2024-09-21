/*
============================================================================
Name : 19d.c
Author : Dora Bhavya Rishitha
Description :19. Create a FIFO file by
d.mknod system call
Date: 21st Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/stat.h>
void main(){
	const char *path ="fifofile19"; 
	mode_t mode = 0666;
	int errno = mknod(path,__S_IFIFO,mode);
	if(errno == -1){
	perror("Error:");
	printf("FAILURE");
	}else{
	printf("SUCCESS");
	}
}

/*
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 19d.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
SUCCESS
*/