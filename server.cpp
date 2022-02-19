/* SERVER SIDE CODE */

//Socket programming imports & more!
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>	

/* GLOBAL VARIABLES */

//constants
int ENCODING_TYPE_FlAG;

int listeningSocket;
int serverSocket;

//simple encryption: devoweling
//paramerts: clientMessage[] = letter to devowel that the client sent
void simpleEncrypt(char clientMessage[]){ /* SIMPLE ENCRYPTION ALGORITHM */
    printf("-- SIMPLE ENCRYPTION --\n");
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

    printf("Non Vowels:%s\n", nonVowels);
    printf("Vowels:    %s\n", vowels);

    send(serverSocket, nonVowels, strlen(nonVowels), 0);

    usleep(20);
    
    send(serverSocket, vowels, strlen(vowels), 0);

}

//simple decryption: envoweling
void simpleDecrypt(char nonVowels[], char vowels[]){

    


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

     /* SEND // RECIEVE */

    int recieveStatus;
    char recieveMsg[1000]="";
    //recieving clients option: 1, 2 or 3
    while((recieveStatus =  recv(serverSocket, recieveMsg, 1000, 0)) > 0){
        printf("Clients option: %s\n", recieveMsg);

        int option = recieveMsg[0] - '0';

        //1= encrypt (devowel)
        if(option == 1){

            char toDevowel[1000]="";
            recv(serverSocket, toDevowel, 1000, 0);
            printf("Client's message: %s\n", toDevowel);

            // send(serverSocket, "vowels", strlen("vowels"), 0);
            // send(serverSocket, "non-vowels", strlen("non-vowels"), 0);

            simpleEncrypt(toDevowel);
        }

        //2= decrypt (envowel)
        else if(option ==2){

            char nonVowels[1000]="";
            char vowels[1000]="";
          
            //recieve nonvowels from client
            recv(serverSocket, nonVowels, 1000, 0);
            printf("Non Vowels from client: %s\n", nonVowels);

            usleep(20);

            //recieve vowels from client
            recv(serverSocket, vowels, 1000, 0);
            printf("Vowels from client: %s\n", vowels);

            simpleDecrypt(nonVowels, vowels);


        }

        //3= quit

    }

    //closing sockets when done
    close(serverSocket);
    close(listeningSocket);

    return 0;
}