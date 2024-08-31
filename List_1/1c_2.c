/*
============================================================================
Name : 1c_2.c
Author : Dora Bhavya Rishitha
Description :Create the following types of a files using (i) shell command (ii) system call
c. FIFO (mkfifo Library Function or mknod system call)
Date: 29th Aug, 2024.
============================================================================
*/

#include<sys/stat.h>
#include<stdio.h>
void main(){
	int errno;
	const char *path = "fifomknod.txt";
	mode_t mode = 0666;
	errno = mknod(path,mode|S_IFIFO,0);
	if(errno == 0){
	printf("SUCCESS");
	}else{
	perror("Error:");
	printf("FAILURE");
	}
}
/*
 * =========================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 1c_2.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
SUCCESS
============================================================================
*/
