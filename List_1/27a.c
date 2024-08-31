/*
============================================================================
Name : 27a.c
Author : Dora Bhavya Rishitha
Description :Write a program to execute ls -Rl by the following system calls
a. execl
Date: 29th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
int main(){
	execl("/bin/ls","ls","-Rl",NULL);
	perror("execl failed");
}
/*
OUTPUT:
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ gcc 27a.c
bhavya@bhavya-HP-Envy-x360-2-in-1-Laptop-14-fc0xxx:~/Desktop/List_1$ ./a.out
.:
total 276
-rw-rw-r-- 1 bhavya bhavya  1289 Aug 31 10:40 '\'
-rw-rw-r-- 1 bhavya bhavya  1770 Aug 31 01:34  10.c
-rw-rw-r-- 1 bhavya bhavya  1200 Aug 31 01:36  11a.c
-rw-rw-r-- 1 bhavya bhavya  1625 Aug 31 01:38  11b.c
-rw-rw-r-- 1 bhavya bhavya  1487 Aug 31 01:40  11c.c
-rw-rw-r-- 1 bhavya bhavya  1373 Aug 31 01:41  12.c
-rw-rw-r-- 1 bhavya bhavya  1464 Aug 31 01:43  13.c
-rw-rw-r-- 1 bhavya bhavya  1885 Aug 31 10:49  14.c
-rw-rw-r-- 1 bhavya bhavya   906 Aug 31 01:44  15.c
-rw-rw-r-- 1 bhavya bhavya  1835 Aug 31 01:44  16a.c
-rw-rw-r-- 1 bhavya bhavya  2087 Aug 31 01:44  16b.c
-rw-rw-r-- 1 bhavya bhavya  1054 Aug 31 01:45  17a.c
-rw-rw-r-- 1 bhavya bhavya  2331 Aug 31 01:45  17b.c
-rw-rw-r-- 1 bhavya bhavya   330 Aug 31 12:00  18a.c
-rw-rw-r-- 1 bhavya bhavya  2985 Aug 31 12:10  18b.c
-rw-rw-r-- 1 bhavya bhavya  1086 Aug 30 16:36  19.c
-rw-rw-r-- 1 bhavya bhavya   488 Aug 31 12:20  1a.c
-rw-rw-r-- 1 bhavya bhavya   236 Aug 27 18:37  1b.c
-rw-rw-r-- 1 bhavya bhavya   248 Aug 27 20:19  1c_2.c
-rw-rw-r-- 1 bhavya bhavya   289 Aug 27 19:16  1c.c
-rw-rw-r-- 1 bhavya bhavya  2419 Aug 30 15:45  20.c
-rw-rw-r-- 1 bhavya bhavya  1089 Aug 30 23:21  21.c
-rw-rw-r-- 1 bhavya bhavya  1300 Aug 30 11:06  22.c
-rw-rw-r-- 1 bhavya bhavya  1913 Aug 30 11:29  23.c
-rw-rw-r-- 1 bhavya bhavya  1674 Aug 30 12:47  24.c
-rw-rw-r-- 1 bhavya bhavya  1987 Aug 30 23:15  25.c
-rw-rw-r-- 1 bhavya bhavya   925 Aug 31 00:29  26a.c
-rw-rw-r-- 1 bhavya bhavya  1020 Aug 31 00:28  26b.c
-rw-rw-r-- 1 bhavya bhavya   112 Aug 31 12:25  27a.c
-rw-rw-r-- 1 bhavya bhavya  1530 Aug 30 16:59  28.c
-rw-rw-r-- 1 bhavya bhavya  1771 Aug 31 01:07  29.c
-rw-rw-r-- 1 bhavya bhavya  2491 Aug 31 01:10  2.c
-rw-rw-r-- 1 bhavya bhavya   903 Aug 31 01:21  3.c
-rw-rw-r-- 1 bhavya bhavya  1090 Aug 31 10:30  4a.c
-rw-rw-r-- 1 bhavya bhavya  1289 Aug 31 10:41  4b.c
-rw-rw-r-- 1 bhavya bhavya  2162 Aug 31 01:24  5.c
-rw-rw-r-- 1 bhavya bhavya   980 Aug 31 01:26  6.c
-rw-rw-r-- 1 bhavya bhavya  1526 Aug 31 01:28  7.c
-rw-rw-r-- 1 bhavya bhavya  1259 Aug 31 01:29  8.c
-rw-rw-r-- 1 bhavya bhavya  2011 Aug 31 01:31  9.c
-rwxrwxr-x 1 bhavya bhavya 15992 Aug 31 12:25  a.out
-rwxrwxr-x 1 bhavya bhavya     0 Aug 29 15:34  a.txt
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 16:35  creatFile_3.txt
-rw-rw-r-- 1 bhavya bhavya     0 Aug 31 10:33  creatFile_4.txt
-rw-r--r-- 1 bhavya bhavya    78 Aug 29 14:30  dupliateFile11.txt
prw-rw-r-- 1 bhavya bhavya     0 Aug 27 19:18  fifofile.txt
prw-rw-r-- 1 bhavya bhavya     0 Aug 27 20:23  fifomknod.txt
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 20:59  file1
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 21:31  file1.txt
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 20:59  file2
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 21:31  file2.txt
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 20:59  file3
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 21:31  file3.txt
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 20:59  file4
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 21:31  file4.txt
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 20:59  file5
-rw-rw-r-- 1 bhavya bhavya     0 Aug 28 21:31  file5.txt
-rw-rw-r-- 2 bhavya bhavya    40 Aug 26 23:55  hrdlinkSC.txt
-rw-rw-r-- 1 bhavya bhavya    31 Aug 26 23:43  hrd_link.txt
-rw-rw-r-- 1 bhavya bhavya    80 Aug 29 10:34  inputFile10.txt
-rw-r--r-- 1 bhavya bhavya    25 Aug 29 15:38  inputFile12.txt
-rw-r--r-- 1 bhavya bhavya    33 Aug 29 20:05  inputFile16.txt
-rw-r--r-- 1 bhavya bhavya    37 Aug 30 01:22  inputFile22.txt
-rw-rw-r-- 1 bhavya bhavya    18 Aug 30 11:40  inputFile8.txt
-rw-rw-r-- 2 bhavya bhavya    40 Aug 26 23:55  link.txt
-rw-r--r-- 1 bhavya bhavya    30 Aug 29 10:42  outputfile10.txt
-rw-rw-r-- 1 bhavya bhavya    86 Aug 28 22:56  readFile6.txt
lrwxrwxrwx 1 bhavya bhavya     8 Aug 27 17:08  symlink.txt -> link.txt
-rw-rw-r-- 1 bhavya bhavya   163 Aug 31 00:19  test26b.c
-rwxrwxr-x 1 bhavya bhavya 16000 Aug 31 00:19  test26b.out
-rw-rw-r-- 1 bhavya bhavya    88 Aug 30 23:52  test26.c
-rwxrwxr-x 1 bhavya bhavya 15952 Aug 30 23:55  test26.out
-rwxr--r-- 1 bhavya bhavya    48 Aug 31 12:08  ticketBooking.txt
-rwxr--r-- 1 bhavya bhavya     4 Aug 29 23:46  TicketList
-------r-x 1 bhavya bhavya    40 Aug 30 00:24  trainBooking.txt
-rw-r--r-- 1 bhavya bhavya    86 Aug 28 23:02  writeFile7.txt
*/
