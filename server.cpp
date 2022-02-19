/* SERVER SIDE CODE */

//Socket programming imports & more!
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>	

int ENCODING_TYPE_FlAG;
int listeningSocket;
int serverSocket;

//simple devoweling
//paramerts: clientMessage[] = letter to devowel that the client sent
void simpleDevowel(char clientMessage[]){




}



int main(){

    //address initialization
    struct sockaddr_in address;
    memset(&address,0, sizeof(address));
    address.sin_family= AF_INET;
    address.sin_port= htons(7000);
    address.sin_addr.s_addr= INADDR_ANY;

     //listening socket creation
   
    listeningSocket= socket(AF_INET, SOCK_STREAM, 0);
    if(listeningSocket == -1){
        perror("Listening socket creation failed!");
    }
    printf("Listening socket created.\n");

    //binding address w/ listening socket
    int bindStatus;
    bindStatus= bind(listeningSocket, (struct sockaddr *)&address, sizeof(address));
    if(bindStatus == -1){
        perror("Binding failed!");
        return 1;
    }
    printf("Binding successful.\n");

    //server listening for clients
    int listenStatus;
    listenStatus = listen(listeningSocket, 5);
    if(listenStatus == -1){
        perror("Listening failed!");
    }

    printf("Waiting(Listening) for clients....\n");

    //accept an incoming client connection
    serverSocket = accept(listeningSocket, NULL, NULL);
    if(serverSocket == -1){
        perror("accept() call failed!");
    }
    printf("--- CONNECTION ACCEPTED ---\n");

    //recieve message from client & send message to client
    int recieveStatus;
    char recieveMsg[1000]="";
    //recieve
    while((recieveStatus =  recv(serverSocket, recieveMsg, 1000, 0)) > 0){
        printf("From Client: %s\n", recieveMsg);

        //send  
        char sendMsg[1000]="";
        sprintf(sendMsg, "Hey client, you said 1, %s", recieveMsg);
        int sendStatus= send(serverSocket, sendMsg, strlen(sendMsg), 0);
        if(sendStatus == -1){
            perror("Server cannot send to client!"); 

        }
    
    }
        
    //closing sockets when done
    close(serverSocket);
    close(listeningSocket);

    return 0;
}