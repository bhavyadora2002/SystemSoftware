/*
============================================================================
Name : 1c.c
Author : Dora Bhavya Rishitha
Description :1. Create the following types of a files using (i) shell command (ii) system call
c. FIFO (mkfifo Library Function or mknod system call)
Date: 29th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
void main(){
	const char *path ="fifofile.txt";
	mode_t mode = 0666;
	int errno = mkfifo(path,mode);
	printf("Error no is %d",errno);
	if(errno == -1){
	perror("Error:");
	printf("FAILURE");
	}else{
	printf("SUCCESS");
	}
}

/*
OUTPUT:
TERMINAL 1:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ cat > fifofile.txt
Hii
TERMINAL 2:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ cat < fifofile.txt
Hii
*/
