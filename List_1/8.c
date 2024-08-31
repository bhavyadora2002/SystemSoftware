/*
============================================================================
Name : 8.c
Author : Dora Bhavya Rishitha
Description :Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date :29th August,2024
===========================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fd = open("inputFile8.txt",O_RDONLY|O_CREAT,0644);
	char buff[1024];
	char line[1024];
	int j = 0;
	if(fd == -1)
		perror("ERROR:");
	else{
		int byte = read(fd,buff,sizeof(buff));
		if(byte>0){
			for(int i = 0;i<byte;i++){
				if(buff[i] == '\n' || buff[i] == '\0'){
					line[j] = '\0';
					printf("%s\n",line);
					sleep(2);
					j = 0;
				}
				else{
					line[j++] = buff[i];
				}
			}
		}else
			printf("No data is present\n");
	}
}

/*
===========================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 8.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
Line1
Line2
Line3
===========================================================================
*/
