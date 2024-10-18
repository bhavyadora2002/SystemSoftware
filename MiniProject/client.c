#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
// #include "clientFunc.h"


#define PORT 5053

char buf[1024];
char rid[1024];
char amt[1024];
void login(int sock,char *uname,char *pass){   

    read(sock, buf, sizeof(buf));
    printf("%s", buf);
    scanf("%s", uname);
    write(sock, uname, sizeof(uname));

    read(sock, buf, sizeof(buf));
    printf("%s", buf);
    scanf("%s", pass);
    write(sock, pass, sizeof(pass));
}

void change_password(int sock,char *pass){
    read(sock, buf, sizeof(buf));
    printf("%s", buf);
    scanf("%s", pass);
    write(sock, pass, sizeof(pass));
}

void transfer_funds(int sock){
    read(sock, buf, sizeof(buf));
    printf("%s", buf);
    scanf("%s", rid);
    write(sock, rid, sizeof(rid));

    read(sock, buf, sizeof(buf));
    printf("%s", buf);
    scanf("%s", amt);
    write(sock, amt, sizeof(amt));
}
void add_employee(int sock){   
    char unamenew[1024];
    char passnew[1024];
    char idnew[1024];
    read(sock, buf, sizeof(buf));
    printf("%s", buf);
    scanf("%s", unamenew);
    write(sock, unamenew, sizeof(unamenew));

    read(sock, buf, sizeof(buf));
    printf("%s", buf);
    scanf("%s", passnew);
    write(sock, passnew, sizeof(passnew));

    read(sock, buf, sizeof(buf));
    printf("%s", buf);
    scanf("%s", idnew);
    write(sock, idnew, sizeof(idnew));
}

void modify_customer(int sock){
    char unamenew[1024];
    char unamenew1[1024];
    read(sock, buf, sizeof(buf));
    printf("%s", buf);
    scanf("%s", unamenew);
    write(sock, unamenew, sizeof(unamenew));

    read(sock, buf, sizeof(buf));
    printf("%s", buf);
    scanf("%s", unamenew1);
    write(sock, unamenew1, sizeof(unamenew1));
}
int main() {
    char Menu[1024];
    char bal[1024];
    char uname[1024];
    char pass[1024];
    int choice;
    
    char server_reply[1024];
    int sock;
    struct sockaddr_in server;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    server.sin_addr.s_addr = INADDR_ANY;  // Localhost
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    // Connect to remote server
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }
    printf("Connected to server.\n");
    
    // Receive and print the menu
    read(sock, Menu, sizeof(Menu));
    printf("%s", Menu);

    // Get user choice and send to server
    scanf("%s", buf);
    write(sock, buf, sizeof(buf));

    int usertype = atoi(buf);
    if(usertype == 1){
        login(sock,uname,pass);  
        memset(server_reply, 0, sizeof(server_reply));
        recv(sock, server_reply, sizeof(server_reply), 0);
        printf("Server reply: %s\n", server_reply);

        if(strcmp(server_reply,"Login successful\n")==0){
        while(1) {
            memset(Menu, 0, sizeof(Menu)); 
            recv(sock, Menu, sizeof(Menu)+1,0); 
            printf("%s\n", Menu); 

            memset(buf, 0, sizeof(buf));  
            scanf("%s", buf);
            write(sock, &buf, sizeof(buf));

            choice = atoi(buf);
            printf("choice is %d\n",choice);

            if(choice == 1){
                add_employee(sock);
                memset(server_reply, 0, sizeof(server_reply));
                recv(sock, server_reply, sizeof(server_reply), 0);
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 2){
                modify_customer(sock);
                memset(server_reply, 0, sizeof(server_reply));  // Clear buffer
                recv(sock, server_reply, sizeof(server_reply), 0);  // Receive response
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 3){
                modify_customer(sock);
                memset(server_reply, 0, sizeof(server_reply));  // Clear buffer
                recv(sock, server_reply, sizeof(server_reply), 0);  // Receive response
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 5){
                send(sock,uname,strlen(uname)+1,0);
                change_password(sock,pass);
                memset(server_reply, 0, sizeof(server_reply));
                recv(sock, server_reply, sizeof(server_reply), 0);
                printf("%s\n", server_reply);
            }
            else if(choice == 6){
                send(sock,uname,strlen(uname)+1,0);
                strcpy(uname,"");
                memset(server_reply, 0, sizeof(server_reply));  // Clear buffer
                recv(sock, server_reply, sizeof(server_reply), 0);  // Receive response
                printf("Server reply: %s\n", server_reply);
                break;
            }
        }
    }

    }else if(usertype == 2){

    }else if(usertype == 3){

    }else if(usertype == 4){
        login(sock,uname,pass);  
        memset(server_reply, 0, sizeof(server_reply));
        recv(sock, server_reply, sizeof(server_reply), 0);
        printf("Server reply: %s\n", server_reply);

        if(strcmp(server_reply,"Login successful\n")==0){
        while(1) {
            memset(Menu, 0, sizeof(Menu)); 
            // printf("Menu is %s\n",Menu); 
            recv(sock, Menu, sizeof(Menu)+1,0); 
            printf("%s\n", Menu); 

            memset(buf, 0, sizeof(buf));  
            scanf("%s", buf);
            write(sock, &buf, sizeof(buf));

            choice = atoi(buf);
            printf("choice is %d\n",choice);

            if(choice == 1){
                send(sock,uname,strlen(uname)+1,0);
                memset(server_reply, 0, sizeof(server_reply));
                recv(sock, server_reply, sizeof(server_reply), 0);
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 2){
                send(sock,uname,strlen(uname)+1,0);
                if(strlen(uname)>0){
                read(sock, buf, sizeof(buf));
                printf("%s", buf);
                scanf("%s", bal);
                write(sock, bal, sizeof(bal));
                }
                memset(server_reply, 0, sizeof(server_reply));
                recv(sock, server_reply, sizeof(server_reply), 0);
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 3){
                send(sock,uname,strlen(uname)+1,0);
                if(strlen(uname)>0){
                read(sock, buf, sizeof(buf));
                printf("%s", buf);
                scanf("%s", bal);
                write(sock, bal, sizeof(bal));
                }
                memset(server_reply, 0, sizeof(server_reply));
                recv(sock, server_reply, sizeof(server_reply), 0);
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 4){
                send(sock,uname,strlen(uname)+1,0);
                transfer_funds(sock);
                memset(server_reply, 0, sizeof(server_reply));
                recv(sock, server_reply, sizeof(server_reply), 0);
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 7){
                // add_feedback();
                memset(server_reply, 0, sizeof(server_reply));
                recv(sock, server_reply, sizeof(server_reply), 0);
                printf("Server reply: %s\n", server_reply);               
            }
            else if(choice == 6){
                send(sock,uname,strlen(uname)+1,0);
                change_password(sock,pass);
                memset(server_reply, 0, sizeof(server_reply));
                recv(sock, server_reply, sizeof(server_reply), 0);
                printf("%s\n", server_reply);
            }
            else if(choice == 8){
                send(sock,uname,strlen(uname)+1,0);
                memset(server_reply, 0, sizeof(server_reply));
                recv(sock, server_reply, sizeof(server_reply), 0);
                printf("%s\n", server_reply);  
            }

            // Handle logout
            else if (choice == 9) {
                send(sock,uname,strlen(uname)+1,0);
                strcpy(uname,"");
                memset(server_reply, 0, sizeof(server_reply));  // Clear buffer
                recv(sock, server_reply, sizeof(server_reply), 0);  // Receive response
                printf("Server reply: %s\n", server_reply);
                break;
            }

          
        }   
        }

    }else{

    }

    close(sock);
    return 0;
}

