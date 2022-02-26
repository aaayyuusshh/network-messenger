/* CLIENT SIDE CODE */

//Socket programming imports & more!
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>	

#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>

/*
CREDITS: 
    - Bardia's tutorial notes + client/server code snippets
    - https://en.cppreference.com/w/ 
*/

/* GLOBAL VARIABLES & CONSTANTS */

const char *SERVER_IP = "127.0.0.1";        //local host
//const char *SERVERSERVER_IP = "136.159.5.25";  //csx.cpsc.ucalgary.ca
//const char *SERVER_IP = "136.159.5.27";  //csx3.cpsc.ucalgary.ca

struct sockaddr_in udpServerAddr;
int clientSocket, udpSocket;

void setupTCP(){

    //address initialization
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family= AF_INET;
    address.sin_port= htons(8000);
    address.sin_addr.s_addr = inet_addr(SERVER_IP);

    //creating tcp socket file descriptor
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocket == -1){
        perror("Client socket creation failed!");
    }

    //send connection request to the server 
    int connectionRequest;
    connectionRequest= connect(clientSocket, (struct sockaddr*)&address, sizeof(address));
    if(connectionRequest == -1){
        perror("Connection request failed!");
        exit(-1);
    }
}

void setupUDP(){

    //creating udp socket file descriptor
    if((udpSocket = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        perror("UPD socket creation failed!\n");
        exit(EXIT_FAILURE);
    }
    //printf("UDP socket created.\n");

    //memset to 0s
    memset(&udpServerAddr, 0, sizeof(udpServerAddr));

    //address initialization for the UDP client
    udpServerAddr.sin_family= AF_INET;  
    udpServerAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    udpServerAddr.sin_port= htons(8000);

}

int main(){

    printf("\n~~ WELCOME! I AM A CLIENT FOR THE VOWELIZER ~~ \n");

    setupTCP();
    setupUDP();

    /* SEND // RECIEVE */
    while(1){
        //recieve user input regarding options
        char sendMsg[1000];
        printf("\nPlease choose from the following selections:\n");
        printf("(1) Devowel?\n(2) Envowel?\n(3) Quit?\n");
        printf("Enter your desired menu selection: ");
        fgets(sendMsg, sizeof(sendMsg), stdin);
        sendMsg[strcspn(sendMsg, "\n")] = 0; //removes the \n character that fgets adds to sendMsg
        int option = sendMsg[0] - '0';

        //send desired user option to client
        int sendStatus= send(clientSocket, sendMsg, strlen(sendMsg), 0);
        if(sendStatus== -1){
            perror("Client cannot send to server!");
            return 1;
        }

       //1= encrypt (devowel)
        if(option == 1){
            char toDevowel[1000];
            printf("Enter your message to devowel: ");
            fgets(toDevowel, sizeof(toDevowel), stdin);
            toDevowel[strcspn(toDevowel, "\n")] = 0;

            //sending word to devowel to the server using TCP
            send(clientSocket, toDevowel, strlen(toDevowel), 0);

            usleep(10);

            //first send jiberrish to server so it can identify the client address to send messages to
            char *jibb = "For address identification purposes";
            sendto(udpSocket, (const char *)jibb, strlen(jibb),0, (const struct sockaddr *) &udpServerAddr, sizeof(udpServerAddr));

            char recieveMsg[1000]="";
            
            //recieve non vowels through tcp
            recv(clientSocket, recieveMsg, 1000,0 );
            printf("Server sent %lu bytes of non-vowels using TCP: \'%s\'\n", strlen(recieveMsg),recieveMsg);

            bzero(recieveMsg, sizeof(recieveMsg));

            //recieve vowels through upd
            /* recv(clientSocket, recieveMsg, 1000,0 ); */ //TCP way
            int len;
            recvfrom(udpSocket, (char *)recieveMsg, 1000, 0, (struct sockaddr *)&udpServerAddr, (socklen_t *)&len);
            printf("Server sent %lu bytes of vowels using UDP:     \'%s\'\n", strlen(recieveMsg), recieveMsg);
        }

       //2= decrypt (envowel)
        else if(option ==2){

            //get and send non-vowels 
            char nonVowels[1000];
            printf("Enter the non-vowels:");
            fgets(nonVowels, sizeof(nonVowels), stdin);
            nonVowels[strcspn(nonVowels, "\n")] = 0;

            //send non-vowels through UDP
            send(clientSocket, nonVowels, strlen(nonVowels),0);

            //get and send vowels
            char vowels[1000];
            printf("Enter the vowels:");
            fgets(vowels, sizeof(vowels), stdin);
            vowels[strcspn(vowels, "\n")] = 0;

            //send vowels through UDP
            /*send(clientSocket, vowels, strlen(vowels),0);*/ //TCP Way
            sendto(udpSocket, (const char *)vowels, strlen(vowels),0, (const struct sockaddr *) &udpServerAddr, sizeof(udpServerAddr));

            //recieve decrypted message from server
            char decryptedMsg[1000]="";
            recv(clientSocket,decryptedMsg , sizeof(decryptedMsg),0 );
            printf("Server sent %lu bytes of decrypted message using TCP: \'%s\'\n",strlen(decryptedMsg),decryptedMsg);
        

        }
        
        else {
            printf("Quitting Program...");
            close(clientSocket);
            break;
        }

    }
        
    close(clientSocket); //close socket

    return 0;
}

