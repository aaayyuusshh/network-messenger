/* CLIENT SIDE CODE */

//Socket programming imports & more!
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>	


int main(){

    //address initialization
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family= AF_INET;
    address.sin_port= htons(7000);
    address.sin_addr.s_addr = INADDR_ANY;

    //socket creation
    int clientSocket;
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocket == -1){
        perror("Client socket creation failed!");
    }

    //send connection request to the server 
    int connectionRequest;
    connectionRequest= connect(clientSocket, (struct sockaddr*)&address, sizeof(address));
    if(connectionRequest == -1){
        perror("Connection request failed!");
        return 1;
    }

    //send message to server & recieve message from server

    //send
    char sendMsg[1000];
    printf("Enter your message to server: ");
    scanf("%s", sendMsg);

    int sendStatus= send(clientSocket, sendMsg, strlen(sendMsg), 0);
    if(sendStatus== -1){
        perror("Client cannot send to server!");
        return 1;
    }

    //recieve
    char recieveMsg[1000]="";
    int recieveStatus= recv(clientSocket, recieveMsg, 1000,0 );
    if(recieveStatus == -1){
        perror("Client cannot recieve from server!");
        //break;
    }
    printf("Server says: %s\n", recieveMsg);


    return 0;
}