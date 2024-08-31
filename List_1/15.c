/*
============================================================================
Name : 15.c
Author : Dora Bhavya Rishitha
Description : Write a program to display the environmental variable of the user (use environ).
Date: 29th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<string.h>
extern char **environ;
int main(){
	char **env = environ;
	const char *key = "USER";
	while(*env){
		if(strncmp(*env,key,strlen(key)) == 0 && ((*env)[strlen(key)]) == '=')
			printf("%s\n",*env);
		env++;
	}
	return 0;
}

/*
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 15.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
USER=bhavya
============================================================================
*/
