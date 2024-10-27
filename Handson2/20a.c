/*
============================================================================
Name :20a.c
Author : Hymavathi Jayaramappa
Description : Write two programs so that both can communicate by FIFO -Use one way communication
Date: 13th sept, 2024.
============================================================================
*/



#include <sys/types.h> // Import for `mkfifo` & `open`
#include <sys/stat.h>  // Import for `mkfifo` & `open`
#include <fcntl.h>     // Import for `open`
#include <unistd.h>    // Import for `write`
#include <stdio.h>     // Import for `perror`

void main()
{
    char *s; // Data to be sent through the buffer
    int fd;  // File descriptor of the FIFO file
    long int size = 100;
    char *file = "./20-fifo";
    mkfifo(file, S_IRWXU);
    while (1)
    {
        fd = open(file, O_WRONLY);
        if (fd == -1)
            perror("Error");
        else
        {
            printf("enter message:\n");
            int l = getline(&s, &size, stdin);
            write(fd, s, l);
            close(fd);
        }
    }
}

/*output:
input:hyma@hyma-Latitude-7390:~/Handson2$ cc 20a.c
hyma@hyma-Latitude-7390:~/Handson2$ ./a.out
hello hyma
how are you doing

*/