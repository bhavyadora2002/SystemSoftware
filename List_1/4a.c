/*
============================================================================
Name : 4a.c
Author : Dora Bhavya Rishitha
Description :4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 29th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>

int main(){
	const char *path = "creatFile_3.txt";
	int fd = open(path,O_RDWR);
	if(fd == -1){
	printf("Cannot open file with RDWR permission");
	}
	else{
	printf("Successfully open file with read write mode and its file descriptor is %d",fd);
	}

}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ nano 4a.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 4a.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Successfully open file with read write mode and its file descriptor is 3
============================================================================
*/

