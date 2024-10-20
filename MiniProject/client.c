#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>


#define PORT 5052
struct{
        int id;
        char username[15];
        int balance;
        int loan;
        int transaction_count;
        char transaction[1024];
        int eid;
        char eusername[15];
        char status[15];
        int active;
}ac,sender_ac,receiver_ac;

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
void add_feedback(int sock){
    char fb[1024];
    read(sock, buf, sizeof(buf));
    printf("%s", buf);
    scanf(" %[^\n]", fb); 
    write(sock, fb, strlen(fb));
}
void add_emp_cust(int sock){   
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
    printf("%s\n", buf);
    scanf("%s", unamenew);
    write(sock, unamenew, sizeof(unamenew));

    read(sock, buf, sizeof(buf));
    printf("%s", buf);
    scanf("%s", unamenew1);
    write(sock, unamenew1, sizeof(unamenew1));
}
void account_status(int sock){
    char unamenew[1024];
    read(sock, buf, sizeof(buf));
    printf("%s\n", buf);
    scanf("%s", unamenew);
    write(sock, unamenew, sizeof(unamenew));
}
void review_feedback(int sock){
    char buffer[1024];
    int bytes_received;
    while ((bytes_received = read(sock, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_received] = '\0'; 
        write(1, buffer, bytes_received); 
    }
    if (bytes_received < 0) {
        perror("Error reading from server");
    }
}
void apply_loan(int sock,char *uname){
    char loan[1024];
    int fd_ac = open("account.txt", O_RDONLY,0744);
    int i = read(fd_ac, &ac, sizeof(ac));
    
    while (i > 0) {
        if (strcmp(ac.username, uname) == 0 ) {
            if(ac.active == 1){
                read(sock, buf, sizeof(buf));
                printf("%s\n", buf);
                scanf("%s", loan);
                write(sock, loan, sizeof(loan));
            }
        }
        i = read(fd_ac, &ac, sizeof(ac));
    }
    return;
}

void assign_employee(int sock) {
    char buf[1024];
    char cust_id[1024];
    char emp_id[1024];
    char emp_uname[1024];

    read(sock, buf, sizeof(buf));
    printf("%s\n", buf);
    scanf("%s", cust_id);
    write(sock, cust_id, sizeof(cust_id));

    read(sock, buf, sizeof(buf));
    printf("%s\n", buf);
    scanf("%s", emp_id);
    write(sock, emp_id, sizeof(emp_id));

    read(sock, buf, sizeof(buf));
    printf("%s\n", buf);
    scanf("%s", emp_uname);
    write(sock, emp_uname, sizeof(emp_uname));
}

void view_loans(int sock) {
    char server_reply[4096];  // Larger buffer to receive all customer information

    memset(server_reply, 0, sizeof(server_reply));
    int reply_received = recv(sock, server_reply, sizeof(server_reply), 0);  // Receive in one operation

    if (reply_received > 0) {
        printf("Bytes received: %d\n", reply_received);
        printf("%s\n", server_reply);  // Print all received data at once
    } else {
        printf("Error receiving data or no data received.\n");
    }
}

void aporrej_loan(int sock){
    char c_id[1024];
    char stat[1024];
    char buf[1024];
    read(sock, buf, sizeof(buf));
    printf("%s\n", buf);
    scanf("%s", c_id);
    write(sock, c_id, sizeof(c_id));

    read(sock, buf, sizeof(buf));
    printf("%s\n", buf);
    scanf("%s", stat);
    write(sock, stat, sizeof(stat));
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

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }

    server.sin_addr.s_addr = INADDR_ANY; 
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }
    printf("Connected to server.\n");
    
    read(sock, Menu, sizeof(Menu));
    printf("%s", Menu);

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
                add_emp_cust(sock);
                memset(server_reply, 0, sizeof(server_reply));
                recv(sock, server_reply, sizeof(server_reply), 0);
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 2){
                modify_customer(sock);
                memset(server_reply, 0, sizeof(server_reply));  
                recv(sock, server_reply, sizeof(server_reply), 0);  
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 3){
                modify_customer(sock);
                memset(server_reply, 0, sizeof(server_reply));  
                recv(sock, server_reply, sizeof(server_reply), 0);  
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 4){
                char mrole[1024];
                read(sock, buf, sizeof(buf));
                printf("%s", buf);
                scanf("%s", mrole);
                write(sock, mrole, sizeof(mrole));
                memset(server_reply, 0, sizeof(server_reply)); 
                recv(sock, server_reply, sizeof(server_reply), 0);  
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
                memset(server_reply, 0, sizeof(server_reply));  
                recv(sock, server_reply, sizeof(server_reply), 0);  
                printf("Server reply: %s\n", server_reply);
                break;
            }
        }
    }

    }else if(usertype == 2){
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
                account_status(sock);
                memset(server_reply, 0, sizeof(server_reply));  
                recv(sock, server_reply, sizeof(server_reply), 0); 
                printf("Server reply: %s\n", server_reply);
                
            }
            else if(choice == 2){
                account_status(sock);
                memset(server_reply, 0, sizeof(server_reply));  
                recv(sock, server_reply, sizeof(server_reply), 0); 
                printf("Server reply: %s\n", server_reply);
                
            }
            else if(choice == 3){
                assign_employee(sock);
                memset(server_reply, 0, sizeof(server_reply));  
                recv(sock, server_reply, sizeof(server_reply), 0); 
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 4){
                review_feedback(sock);
                memset(server_reply, 0, sizeof(server_reply));  
                recv(sock, server_reply, sizeof(server_reply), 0);  
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 5){
                send(sock,uname,strlen(uname)+1,0);
                change_password(sock,pass);
                memset(server_reply, 0, sizeof(server_reply));
                recv(sock, server_reply, sizeof(server_reply), 0);
                printf("%s\n", server_reply);
            }
            else if (choice == 6) {
                send(sock,uname,strlen(uname)+1,0);
                strcpy(uname,"");
                memset(server_reply, 0, sizeof(server_reply));  
                recv(sock, server_reply, sizeof(server_reply), 0); 
                printf("Server reply: %s\n", server_reply);
                break;
            }
        }
    }


    }else if(usertype == 3){
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
                add_emp_cust(sock);
                memset(server_reply, 0, sizeof(server_reply));
                recv(sock, server_reply, sizeof(server_reply), 0);
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 2){
                modify_customer(sock);
                memset(server_reply, 0, sizeof(server_reply));  
                recv(sock, server_reply, sizeof(server_reply), 0);  
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 3){
                send(sock,uname,strlen(uname)+1,0);
                char u_name[1024];
                read(sock, buf, sizeof(buf));
                printf("%s\n", buf);
                scanf("%s", u_name);
                write(sock, u_name, sizeof(u_name));
                memset(server_reply, 0, sizeof(server_reply));  
                recv(sock, server_reply, sizeof(server_reply), 0);  
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 4){
                send(sock,uname,strlen(uname)+1,0);
                aporrej_loan(sock);
                memset(server_reply, 0, sizeof(server_reply));  
                recv(sock, server_reply, sizeof(server_reply), 0);  
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 5){
                send(sock,uname,strlen(uname)+1,0);
                view_loans(sock);
            }else if(choice == 6){
                char u_name[1024];
                read(sock, buf, sizeof(buf));
                printf("%s\n", buf);
                scanf("%s", u_name);
                write(sock, u_name, sizeof(u_name));
                memset(server_reply, 0, sizeof(server_reply));  
                recv(sock, server_reply, sizeof(server_reply), 0);  
                printf("Server reply: %s\n", server_reply);
            }
            else if(choice == 7){
                send(sock,uname,strlen(uname)+1,0);
                change_password(sock,pass);
                memset(server_reply, 0, sizeof(server_reply));
                recv(sock, server_reply, sizeof(server_reply), 0);
                printf("%s\n", server_reply);
            }
            else if (choice == 8) {
                send(sock,uname,strlen(uname)+1,0);
                strcpy(uname,"");
                memset(server_reply, 0, sizeof(server_reply));  
                recv(sock, server_reply, sizeof(server_reply), 0); 
                printf("Server reply: %s\n", server_reply);
                break;
            }
        }
    }

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
            else if(choice == 5){
                send(sock,uname,strlen(uname)+1,0);
                apply_loan(sock,uname);
                memset(server_reply, 0, sizeof(server_reply));
                recv(sock, server_reply, sizeof(server_reply), 0);
                printf("Server reply: %s\n", server_reply); 
            }
            else if(choice == 7){
                add_feedback(sock);
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

            else if (choice == 9) {
                send(sock,uname,strlen(uname)+1,0);
                strcpy(uname,"");
                memset(server_reply, 0, sizeof(server_reply));  
                recv(sock, server_reply, sizeof(server_reply), 0); 
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

