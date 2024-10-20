#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include "serverFunc.h"
#include "adminFunc.h"
#include "managerFunc.h"
#include "employeeFunc.h"

#define PORT 5053


void* handler(void* arg) {
    char buf[1024];
    char customer_menu[1024];
    char admin_menu[1024];
    char manager_menu[1024];
    char employee_menu[1024];
    int choice;
    char uname[1024];
    char pass[1024];
    
    int sd = *(int*)arg;

    char menu[] = "Welcome to the Bank\n"
                  "1. Admin\n"
                  "2. Manager\n"
                  "3. Employee\n"
                  "4. Customer\n"
                  "Enter your Choice: ";
    write(sd, menu, sizeof(menu));
    read(sd, buf, sizeof(buf));

    int usertype = atoi(buf);
    if(usertype == 1){
        login(usertype, sd);
        send(sd, response, strlen(response) + 1, 0);
        if(strcmp(response,"Login successful\n")==0){
        strcpy(admin_menu,"1. Add Employee\n"
            "2. Modify Customer Details\n"
            "3. Modify Employee Details\n"
            "4. Manage Roles\n"
            "5. Change Password\n"
            "6. Logout\n"
            "Enter your Choice : \n"); 
        while(1){
                
            sleep(2);
            int wr = send(sd, admin_menu, strlen(admin_menu)+1,0);
                printf("Write is %d",wr);
                memset(buf, 0, sizeof(buf));
                read(sd, &buf, sizeof(buf));
                choice = atoi(buf);
                printf("choice is %d\n",choice);
                if(choice == 1){
                    add_employee(sd);
                    send(sd, response, strlen(response) + 1, 0);
                }
                else if(choice == 2){
                    modify_customer(sd);
                    send(sd, response, strlen(response) + 1, 0);
                }
                else if(choice == 3){
                    modify_employee(sd);
                    send(sd, response, strlen(response) + 1, 0);            
                }
                else if(choice == 4){
                    manage_roles(sd);
                    send(sd, response, strlen(response) + 1, 0);            
                }
                else if(choice == 5){
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    change_password_ad(sd,uname);
                    send(sd,response,strlen(response)+1,0);
                }
                else if(choice == 6){
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    logout(usertype, sd,uname);
                    send(sd, response, strlen(response) + 1, 0);
                    break;
                
                }
        }
    }
    }else if(usertype == 2){
    login(usertype, sd);
    send(sd, response, strlen(response) + 1, 0);

    if(strcmp(response,"Login successful\n")==0){
        strcpy(manager_menu,"1. Activate Account\n"
            "2. Deactivate Account\n"
            "3. Assign Employee\n"
            "4. Review Feedback\n"
            "5. Change Password\n"
            "6. Logout\n"
            "Enter your Choice : \n"); 
       while(1){
                
            sleep(2);
            int wr = send(sd, manager_menu, strlen(manager_menu)+1,0);
                printf("Write is %d",wr);
                memset(buf, 0, sizeof(buf));
                read(sd, &buf, sizeof(buf));
                choice = atoi(buf);
                printf("choice is %d\n",choice);
                if(choice == 1){
                    activate_account(sd);
                    send(sd, response, strlen(response) + 1, 0);
                }
                else if(choice == 2){
                    
                    deactivate_account(sd);
                    send(sd, response, strlen(response) + 1, 0);
                }
                else if(choice == 3){
                    assign_employee(sd);
                    send(sd, response, strlen(response) + 1, 0);
                }
                else if(choice == 4){
                    review_feedback(sd);
                    send(sd, response, strlen(response) + 1, 0);
                }
                else if(choice == 5){
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    change_password_man(sd,uname);
                    send(sd,response,strlen(response)+1,0);
                }
                else if(choice == 6){
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    logout(usertype, sd,uname);
                    send(sd, response, strlen(response) + 1, 0);
                    break;
                }
       }
    }


    }else if(usertype == 3){
    login(usertype, sd);
    send(sd, response, strlen(response) + 1, 0);

    if(strcmp(response,"Login successful\n")==0){
        strcpy(employee_menu,"1. Add Customer\n"
            "2. Modify Customer Details\n"
            "3. Process Loan Applications\n"
            "4. Approve/Reject Loan\n"
            "5. View Assign Loan Applications\n"
            "6. View Transactions\n"
            "7. Change Password\n"
            "8. Logout\n"
            "Enter your Choice : \n"); 
       while(1){
                
            sleep(2);
            int wr = send(sd, employee_menu, strlen(employee_menu)+1,0);
                printf("Write is %d",wr);
                memset(buf, 0, sizeof(buf));
                read(sd, &buf, sizeof(buf));
                choice = atoi(buf);
                printf("choice is %d\n",choice);
                if(choice == 1){
                    add_customer(sd);
                    send(sd, response, strlen(response) + 1, 0);
                }
                else if(choice == 2){
                    
                    modify_customer(sd);
                    send(sd, response, strlen(response) + 1, 0);
                }
                else if(choice == 4){
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    aporrej_loan(sd,uname);
                    send(sd, response, strlen(response) + 1, 0);
                }
                else if(choice == 5){
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    view_loans(sd,uname);
                }
                else if(choice == 7){
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    change_password_emp(sd,uname);
                    send(sd,response,strlen(response)+1,0);
                }
                else if(choice == 8){
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    logout(usertype, sd,uname);
                    send(sd, response, strlen(response) + 1, 0);
                    break;
                }
       }
    }

    }else if(usertype == 4){
    login(usertype, sd);
    send(sd, response, strlen(response) + 1, 0);

    if(strcmp(response,"Login successful\n")==0){
        strcpy(customer_menu,"1. View Balance\n"
            "2. Deposit Money\n"
            "3. Withdraw Money\n"
            "4. Transfer Funds\n"
            "5. Apply for loan\n"
            "6. Change Password\n"
            "7. Add feed back\n"
            "8. View Transaction history\n"
            "9. Logout\n"
            "Enter your Choice : "); 
        while(1){
                
            sleep(2);
            int wr = send(sd, customer_menu, strlen(customer_menu)+1,0);
                printf("Write is %d",wr);
                memset(buf, 0, sizeof(buf));
                read(sd, &buf, sizeof(buf));
                choice = atoi(buf);
                printf("choice is %d\n",choice);
                if(choice == 1){
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    view_balance(uname);
                    send(sd, response, strlen(response) + 1, 0);

                }
                else if(choice == 2){
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    deposit_money(sd,uname);
                    send(sd,response,strlen(response)+1,0);
                }
                else if(choice == 3){
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    withdraw_money(sd,uname);
                    send(sd,response,strlen(response)+1,0);
                }
                else if(choice == 4){
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    transfer_funds(sd,uname);
                    send(sd,response,strlen(response)+1,0);
                }
                else if(choice == 5){
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    apply_loan(sd,uname);
                    send(sd,response,strlen(response)+1,0);

                }
                else if(choice == 6){
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    change_password(sd,uname);
                    send(sd,response,strlen(response)+1,0);
                }
                else if(choice == 7){
                    add_feedback(sd); // else if(choice == 2){
                    send(sd,response,strlen(response)+1,0);

                }
     
                else if(choice == 8){
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    view_history(sd,uname);
                }
                else if (choice == 9) {  // Logout
                    memset(uname, 0, sizeof(uname));
                    recv(sd, uname, sizeof(uname), 0);
                    printf("Uname is: %s\n", uname);
                    logout(usertype, sd,uname);
                    send(sd, response, strlen(response) + 1, 0);
                    break;
                }
                
        }
    }
    }else{

    }
    
    close(sd);
    free(arg);

}
int main() {
    read_users_from_file();
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == -1) {
        perror("Socket creation error");
        exit(1);
    }

    struct sockaddr_in server, client;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(sd, (struct sockaddr*)&server, sizeof(server)) == -1) {
        perror("Unable to bind");
        exit(1);
    }

    if (listen(sd, 3) == -1) {
        perror("Unable to listen");
        exit(1);
    }

    while (1) {
        int client_len = sizeof(client);
        int conid = accept(sd, (struct sockaddr*)&client, (socklen_t*)&client_len);
        if (conid == -1) {
            perror("Unable to connect");
            exit(1);
        }

        pthread_t thread_id;
        int* new_sock = malloc(sizeof(int));
        *new_sock = conid;

        if (pthread_create(&thread_id, NULL, handler, (void*)new_sock) < 0) {
            perror("Could not create thread");
            return 1;
        }

        pthread_detach(thread_id);
    }

    close(sd);
    return 0;
}

