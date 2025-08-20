/*
============================================================================
Name : 26.c
Author : Dora Bhavya Rishitha
Description :26. Write a program to send messages to the message queue. Check $ipcs -q
Date: 20th Sep, 2024.
============================================================================
*/
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>

struct msgbuf {
    long mtype;
	char mtext [10];
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
    printf("Enter msg to Message Queue\n");
    scanf("%s",msg.mtext);
    msg.mtype = 1; 
    /*If insufficient space is available in the queue, then the  default  be‐
       havior  of  msgsnd()  is  to  block  until space becomes available.  If
       IPC_NOWAIT is specified in msgflg, then the call instead fails with the
       error EAGAIN.*/

    if (msgsnd(id, &msg, sizeof(msg.mtext),IPC_NOWAIT) == -1)
    {
        perror("msgsnd error");
        exit(EXIT_FAILURE);
    }
    printf("sent: %s\n", msg.mtext);
}


/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 26.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
Key generated is 17108538
Message Queue id is 0
Enter msg to Message Queue
bhavya
sent: bhavya
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x01050e3a 0          bhavya     666        10           1 
============================================================================
*/