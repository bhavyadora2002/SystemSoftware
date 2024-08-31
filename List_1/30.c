/*
============================================================================
Name : 30.c
Author : Dora Bhavya Rishitha
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(){
	if(!fork()){
	setsid();
	chdir("/");
	umask(0);
	int count = 5;
	while(count){
        char cmd[256];
        snprintf(cmd, sizeof(cmd), "notify-send 'Daemon Process Notification' 'Hello, I am a demonstration of a DAEMON process..... %d'", getpid());

        // show notification
        system(cmd);
        sleep(30);
        printf("child pid: %d\n",getpid());
        printf("Daemon process is running..");
        count--;
	}
	}
	else{
    exit(0);
}
}
