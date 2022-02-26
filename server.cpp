/* SERVER SIDE CODE */

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

//reminder: non vowels: TCP, vowels: UDP

/* GLOBAL VARIABLES & CONSTANTS */

//const int ENCODING_TYPE_FLAG = 0;   //0: simple
const int ENCODING_TYPE_FLAG = 1;     //1: complex

const char *SERVER_IP = "127.0.0.1";    
// const char *SERVER_IP = "136.159.5.25";
// const char *SERVER_IP = "136.159.5.27";

int listeningSocket;
int serverSocket;
int udpSocket;
struct sockaddr_in udpServerAddr, udpClientAddr;

//simple encryption: devoweling
//paramerts: clientMessage[] = letter to devowel that the client sent
void simpleEncrypt(char clientMessage[]){ /* SIMPLE ENCRYPTION ALGORITHM */
    printf("-- SIMPLE ENCRYPTION ALGORITHM TRIGGERED --\n");
    int length= strlen(clientMessage);

    char vowels[length];                    
    char nonVowels[length];

    for(int i=0; i < length; i++){
        
        if(clientMessage[i] == 'a' || clientMessage[i] == 'e' || clientMessage[i] == 'i' || clientMessage[i] == 'o' || clientMessage[i] == 'u'
            || clientMessage[i] == 'A' || clientMessage[i] == 'E' || clientMessage[i] == 'I' || clientMessage[i] == 'O' || clientMessage[i] == 'U'){

            vowels[i] = clientMessage[i];
            nonVowels[i]= ' ';
        }

        else{
            nonVowels[i] = clientMessage[i];
            vowels[i] = ' ';
        }
    }

    vowels[length] = '\0';
    nonVowels[length]= '\0';

    printf("Sent %lu bytes of non-vowels \'%s\' using TCP\n", strlen(nonVowels), nonVowels);
    printf("Sent %lu bytes of vowels \'%s\' using UDP\n", strlen(vowels), vowels);
   

    //recieving dummy message through UDP for client address purposes
    char buffer[1000];
    bzero(buffer, 1000);
    int len= sizeof(udpClientAddr);
    recvfrom(udpSocket, buffer, 1000, 0, (struct sockaddr *)&udpClientAddr, (socklen_t*)&len);

    //send non-vowels to client through TCP
    send(serverSocket, nonVowels, strlen(nonVowels), 0);

    usleep(20);
    
    //send vowels to client through UDP
    //send(serverSocket, vowels, strlen(vowels), 0); //TCP way
    sendto(udpSocket, vowels, strlen(vowels), 0, (const struct sockaddr *)&udpClientAddr, len);

}

//simple decryption: envoweling
void simpleDecrypt(char nonVowels[], char vowels[]){
    printf("-- SIMPLE DECRYPTION ALGORITHM TRIGGERED --\n");

    int length= strlen(nonVowels);

    char decrypted[length];

    for(int j=0; j< length; j++){
        if(vowels[j] == ' '){
            decrypted[j] = nonVowels[j];
        }

        else if(vowels[j] != ' '){
            decrypted[j] = vowels[j];
        }
    }
    decrypted[length] ='\0';
    printf("Sent %lu bytes of decrypted message \'%s\' using TCP\n", strlen(decrypted),decrypted);

    //send decrypted message to server
    send(serverSocket, decrypted, strlen(decrypted), 0);

}

//advanced encryption: encryption
void complexEncrypt(char clientMessage[]){ /* SIMPLE ENCRYPTION ALGORITHM */
    printf("-- COMPLEX ENCRYPTION ALGORITHM TRIGGERED --\n");
    int length= strlen(clientMessage);

    char vowels[length];                    
    char nonVowels[length];

    for(int i=0; i < length; i++){
        
        if(clientMessage[i] == 'a' || clientMessage[i] == 'e' || clientMessage[i] == 'i' || clientMessage[i] == 'o' || clientMessage[i] == 'u'
            || clientMessage[i] == 'A' || clientMessage[i] == 'E' || clientMessage[i] == 'I' || clientMessage[i] == 'O' || clientMessage[i] == 'U'){

            vowels[i] = clientMessage[i];
            nonVowels[i]= ' ';
        }

        else{
            nonVowels[i] = clientMessage[i];
            vowels[i] = ' ';
        }
    }

    vowels[length] = '\0';
    nonVowels[length]= '\0';

    printf("Sent %lu bytes of non-vowels \'%s\' using TCP\n", strlen(nonVowels), nonVowels);
    printf("Sent %lu bytes of vowels \'%s\' using UDP\n", strlen(vowels), vowels);
   

    //recieving dummy message through UDP for client address purposes
    char buffer[1000];
    bzero(buffer, 1000);
    int len= sizeof(udpClientAddr);
    recvfrom(udpSocket, buffer, 1000, 0, (struct sockaddr *)&udpClientAddr, (socklen_t*)&len);

    //send non-vowels to client through TCP
    send(serverSocket, nonVowels, strlen(nonVowels), 0);

    usleep(20);
    
    //send vowels to client through UDP
    //send(serverSocket, vowels, strlen(vowels), 0); //TCP way
    sendto(udpSocket, vowels, strlen(vowels), 0, (const struct sockaddr *)&udpClientAddr, len);

}

//advanced encryption: devoweling
void advancedEncrypt(char clientMessage[]){

    int length = strlen(clientMessage);

    //for exact memory allocation
    int vowelCount, nonVowelCount;
    for(int i=0; i< length; i++){       
    }

    char vowels[length];
    char nonVowels[length];

    int nonVowelIndex = 0 , vowelIndex= 0;
    int recentVowel = -1;

    for(int i=0; i< length; i++){

        //vowels
        if(clientMessage[i] == 'a' || clientMessage[i] == 'e' || clientMessage[i] == 'i' || clientMessage[i] == 'o' || clientMessage[i] == 'u'
            || clientMessage[i] == 'A' || clientMessage[i] == 'E' || clientMessage[i] == 'I' || clientMessage[i] == 'O' || clientMessage[i] == 'U'){

                int gap = (i-1) - recentVowel;
                char charGap = gap +'0';

                vowels[vowelIndex++] = charGap;
                vowels[vowelIndex++] = clientMessage[i];

                recentVowel = i;
        }

        //non vowels
        else{

            nonVowels[nonVowelIndex++] = clientMessage[i];
        }
    }

    vowels[vowelIndex]= '\0';
    nonVowels[nonVowelIndex]='\0';
    
    printf("Sent %lu bytes of non-vowels \'%s\' using TCP\n", strlen(nonVowels), nonVowels);
    printf("Sent %lu bytes of vowels \'%s\' using UDP\n", strlen(vowels), vowels);
   

    //recieving dummy message through UDP for client address purposes
    char buffer[1000];
    bzero(buffer, 1000);
    int len= sizeof(udpClientAddr);
    recvfrom(udpSocket, buffer, 1000, 0, (struct sockaddr *)&udpClientAddr, (socklen_t*)&len);

    //send non-vowels to client through TCP
    send(serverSocket, nonVowels, strlen(nonVowels), 0);

    usleep(20);
    
    //send vowels to client through UDP
    //send(serverSocket, vowels, strlen(vowels), 0); //TCP way
    sendto(udpSocket, vowels, strlen(vowels), 0, (const struct sockaddr *)&udpClientAddr, len);

}

//advanced decryption: envoweling
void advancedDecrypt(char nonVowels[], char vowels[]){
    
    char decrypted[strlen(vowels) + (strlen(nonVowels)/2)];
    int toSkip = 0, decryptedIndex = 0, nonVowelsIndex = 0, vowelsIndex = 0;

    for (int i = 0; i < strlen(nonVowels) + strlen(vowels); i++){
        if (vowelsIndex < strlen(vowels)){
            toSkip = vowels[vowelsIndex++] - '0'; 

            for(int i=toSkip; i > 0; i--){
                decrypted[decryptedIndex++] = nonVowels[nonVowelsIndex++];

            }
            decrypted[decryptedIndex++] = vowels[vowelsIndex++]; 
        }
        else {
            decrypted[decryptedIndex++] = nonVowels[nonVowelsIndex++];
        }
    }

    printf("Sent %lu bytes of decrypted message \'%s\' using TCP\n", strlen(decrypted),decrypted);
   
    //send decrypted message to server
    send(serverSocket, decrypted, strlen(decrypted), 0);
}

//set up tcp socket
void setupTCP(){

    //address initialization
    struct sockaddr_in address;
    memset(&address,0, sizeof(address));
    address.sin_family= AF_INET;
    address.sin_port= htons(8000);
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
    }
    printf("Binding successful.\n");

    //server listening for clients
    int listenStatus;
    listenStatus = listen(listeningSocket, 5);
    if(listenStatus == -1){
        perror("Listening failed!");
    }

    printf("Waiting(Listening) for clients.....\n");

    //accept an incoming client connection
    serverSocket = accept(listeningSocket, NULL, NULL);
    if(serverSocket == -1){
        perror("accept() call failed!");
    }
    printf("TCP Connection Accepted!\n");
    
}

//set up udp socket (NOTE: UDP Is connectionless!)
void setupUDP(){

    //creating udp socket file descriptor
    if((udpSocket = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        perror("UPD socket creation failed!\n");
        exit(EXIT_FAILURE);
    }
    printf("UDP socket created.\n");

    //memset to 0s
    memset(&udpServerAddr, 0, sizeof(udpServerAddr));
    memset(&udpClientAddr, 0, sizeof(udpClientAddr));

    //address initialization for the UDP server
    udpServerAddr.sin_family= AF_INET;  
    udpServerAddr.sin_addr.s_addr = INADDR_ANY;
    udpServerAddr.sin_port= htons(8000);

    //bind the UDP socket with the UDP server address
    if(bind(udpSocket, (const struct sockaddr *)&udpServerAddr, sizeof(udpServerAddr)) < 0){
        printf("UDP binding failed!");
        exit(EXIT_FAILURE);

    }
}

int main(){

    printf("\n~~ WELCOME TO THE SUPER SECRET VOWELIZER SERVER shhh... ~~\n");
    printf("\n");
    

    setupTCP();
    setupUDP();

    /* SEND // RECIEVE MENU OPTIONS AND CALL FUNCTIONS ACCORDINGLY */
    int recieveStatus;
    char recieveMsg[1000]="";
    //recieving clients option: 1, 2 or 3

    while((recieveStatus =  recv(serverSocket, recieveMsg, 1000, 0)) > 0){
        printf("\nClient picked menu option: %s\n", recieveMsg);

        int option = recieveMsg[0] - '0';

        //1= encrypt (devowel)
        if(option == 1){

            char toDevowel[1000]="";
            recv(serverSocket, toDevowel, 1000, 0);
            printf("Client's message to devowel: \'%s\'\n", toDevowel);

            // send(serverSocket, "vowels", strlen("vowels"), 0);
            // send(serverSocket, "non-vowels", strlen("non-vowels"), 0);

            if(ENCODING_TYPE_FLAG == 0){
                simpleEncrypt(toDevowel);

            }
            else{
                advancedEncrypt(toDevowel);

            } 
        }

        //2= decrypt (envowel)
        else if(option ==2){

            char nonVowels[1000]="";
            char vowels[1000]="";
          
            //recieve nonvowels from client
            recv(serverSocket, nonVowels, 1000, 0);
            printf("Non Vowels from client: \'%s\'\n", nonVowels);

            usleep(20);

            //recieve vowels from client (through UPD)
            /* recv(serverSocket, vowels, 1000, 0);*/ //TCP WAY
            recvfrom(udpSocket, vowels, 1000, 0, 0, 0);
            printf("Vowels from client: \'%s\'\n", vowels);

             if(ENCODING_TYPE_FLAG == 0){
                simpleDecrypt(nonVowels, vowels);

            }
            else{
                advancedDecrypt(nonVowels, vowels);

            } 

           
        }

        else{
            printf("Server Ending...");
            close(serverSocket);
        }

    }

    //closing sockets when done
    close(serverSocket);
    close(listeningSocket);

    return 0;
}