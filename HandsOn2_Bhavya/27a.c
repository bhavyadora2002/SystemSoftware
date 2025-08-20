/*
============================================================================
Name : 27a.c
Author : Dora Bhavya Rishitha
Description :27. Write a program to receive messages from the message queue.
a. with 0 as a flag
Date: 20th Sep, 2024.
============================================================================
*/
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>

struct msgbuf {
    long mtype;
	char mtext [100];
}; 
int main(){
    struct msgbuf msg;
    int k = ftok(".",1);
    if(k==-1){
        perror("Error getting key for IPC");
        exit(0);
    }
    printf("Key generated is %d\n",k);
    int id = msgget(k,0666|IPC_CREAT);
    if(id == -1){
        perror("Error creating Message Queue");
        exit(0);
    }
    printf("Message Queue id is %d\n",id);
    msg.mtype = 1; 
    // 0 flag will wait for msg and give us warning if message of type is not in msg queue
    if (msgrcv(id, &msg, sizeof(msg.mtext),msg.mtype,0) == -1) 
    {
        perror("msgrcv error");
        exit(EXIT_FAILURE);
    }
    printf("received: %s\n", msg.mtext);
}


/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 27.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Key generated is 17108538
Message Queue id is 0
received: bhavya
============================================================================
*/