/*
============================================================================
Name : 7.c
Author : Dora Bhavya Rishitha
Description :7. Write a program to copy file1 into file2 ($cp file1 file2).
Date: 29th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char *argv[]){
	char buffer[1024];
	int r,w;
	if(argc!=2){
		fprintf(stderr,"Give sufficient arguments");
		return 0;
	}
	const char *file = "readFile6.txt";
	int fd1 = open(file,O_RDONLY);
	if(fd1 == -1){
		perror("ERROR:");
		close(fd1);
		return 0;
	}
	int fd2 = open(argv[1],O_CREAT|O_WRONLY|O_EXCL,0644);
	if(fd2 == -1){
		perror("ERROR");
		close(fd1);
		close(fd2);
		return 0;
	}
	while((r = read(fd1,buffer,1024)) > 0){
		w = write(fd2,buffer,r);
		if(w!=r){
		perror("Error writing data");
		close(fd1);
		close(fd2);
		return 0;
	}
	}
	if(r == -1){
		perror("Error reading data");
	}
	close(fd1);
	close(fd2);
	return 0;
}

/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 7.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out writeFile7.txt
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ cat writeFile7.txt
Hello..We are using this file to copy its contents to other file
This is used for 7.c
============================================================================
*/




	
