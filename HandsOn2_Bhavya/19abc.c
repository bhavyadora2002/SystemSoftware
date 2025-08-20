/*
============================================================================
Name : 19.c
Author : Dora Bhavya Rishitha
Description :19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
Date: 21st SEP,2024
============================================================================
*/

/*
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ mkfifo fifomkfifo
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ mknod fifomknod p
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/SystemSoftware/HandsOn2$ ls
''$'\023\277'   16.c      20a.c     24.c    30d.c          8a.c      fifo21b
''$'\023\300'   17a.c     20a.out   25.c    31.c           8b.c      fifo23
 10a.c          17b.c     20b.c     26.c    33client.c     8c.c      fifofile19
 10b.c          17c.c     20b.out   27a.c   33client.out   8d.c      fifomkfifo
 10c.c          18.c      21a.c     27b.c   33server.c     8e.c      fifomknod
 11.c           19abc.c   21a.out   28.c    33server.out   8f.c
 12.c           19d.c     21b.c     29.c    3.c            8g.c
 13a.c          19e.c     21b.out   2.c     4.c            9.c
 13b.c          1a.c      22a.out   30a.c   5.c            a.out
 14.c           1b.c      22b.out   30b.c   6.c            fifo20
 15.c           1c.c      22.c      30c.c   7.c            fifo21a
 */


