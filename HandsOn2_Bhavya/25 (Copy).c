/*
============================================================================
Name : 25.c
Author : Dora Bhavya Rishitha
Description :25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 20th Sep, 2024.
============================================================================
*/
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <time.h>

int main(){
    int k = ftok(".",1);
    if(k==-1){
        perror("Error getting key for IPC");
        exit(0);
    }
    int id = msgget(k,0666|IPC_CREAT);
    if(id == -1){
        perror("Error creating Message Queue");
        exit(0);
    }
    struct msqid_ds buf;
    /*Copy information from the kernel data structure associated  with
              msqid into the msqid_ds structure pointed to by buf.  The caller
              must have read permission on the message queue.*/
    msgctl(id, IPC_STAT, &buf);
    
    struct ipc_perm msg_perm = buf.msg_perm;   /* Ownership and permissions */
    time_t          msg_stime = buf.msg_stime;  /* Time of last msgsnd(2) */
    time_t          msg_rtime = buf.msg_rtime;  /* Time of last msgrcv(2) */
    time_t          msg_ctime = buf.msg_ctime;  /* Time of creation or last modification by msgctl() */
    unsigned long   msg_cbytes = buf.msg_cbytes; /* # of bytes in queue */
    msgqnum_t       msg_qnum = buf.msg_qnum;   /* # number of messages in queue */
    msglen_t        msg_qbytes = buf.msg_qbytes; /* Maximum # of bytes in queue */
    pid_t           msg_lspid = buf.msg_lspid;  /* PID of last msgsnd(2) */
    pid_t           msg_lrpid = buf.msg_lrpid; /* PID of last msgrcv(2) */
    
    printf("access permission %d\n", msg_perm.mode);
    printf("uid : %d gid : %d \n", msg_perm.uid, msg_perm.gid);
    printf("Time of last msgrcv(2) %ld\n", msg_rtime);
    printf("Time of last msgsnd(2) %ld\n", msg_stime);
    printf("Time of last msgrcv(2) %ld\n", msg_rtime);
    printf("Time of creation or last modification by msgctl() %ld\n", msg_ctime);
    printf("number of bytes in queue %ld\n", msg_cbytes);
    printf("number of messages in queue %ld\n", msg_qnum);
    printf("Maximum number of bytes in queue %ld\n", msg_qbytes);
    printf("PID of last msgsnd(2) %d\n", msg_lspid);
    printf("PID of last msgrcv(2) %d\n", msg_lrpid);
}
    
/*
OUTPUT:
============================================================================
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ gcc 25.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ./a.out
access permission 438
uid : 1000 gid : 1000 
Time of last msgrcv(2) 0
Time of last msgsnd(2) 0
Time of last msgrcv(2) 0
Time of creation or last modification by msgctl() 1726829954
number of bytes in queue 0
number of messages in queue 0
Maximum number of bytes in queue 16384
PID of last msgsnd(2) 0
PID of last msgrcv(2) 0
============================================================================
*/