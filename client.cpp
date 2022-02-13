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


    return 0;
}