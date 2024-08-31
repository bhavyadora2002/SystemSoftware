/*
============================================================================
Name : 22.c
Author : Dora Bhavya Rishitha
Description :Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 29th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(){
	int fd = open("inputFile22.txt",O_RDWR|O_CREAT,0644);
        int t = fork();
        if(t == -1)
        {
                printf("Cannot create child process\n");
        }else if(t>0){
                char *s = "I am PARENT Process";
		write(fd,s,strlen(s));
        }else{
                char *s = "I am CHILD Process";
		write(fd,s,strlen(s));
        }
        return 0;
}
/*
============================================================================
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 22.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ cat inputFile22.txt
I am PARENT ProcessI am CHILD Process
============================================================================
*/
