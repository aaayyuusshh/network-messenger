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
void simpleDevowel(char clientMessage[]){ /* SIMPLE ENCRYPTION ALGORITHM */
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

    printf("Non Vowels:%s\n", nonVowels);
    printf("Vowels:    %s\n", vowels);



}


int main(){

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
        printf("Clients option %s\n", recieveMsg);


        // //send  
        // char sendMsg[1000]="";
        // sprintf(sendMsg, "Hey client, you said 1, %s", recieveMsg);
        // int sendStatus= send(serverSocket, sendMsg, strlen(sendMsg), 0);
        // if(sendStatus == -1){
        //     perror("Server cannot send to client!"); 

        // }

        int option = recieveMsg[0] - '0';

        //1= devowel
        if(option == 1){

            char toDevowel[1000]="";
            recv(serverSocket, toDevowel, 1000, 0);
            printf("You said %s\n", toDevowel);

            // send(serverSocket, "vowels", strlen("vowels"), 0);
            // send(serverSocket, "non-vowels", strlen("non-vowels"), 0);

            simpleDevowel(toDevowel);
        }

        //2= envowel
    }


    //closing sockets when done
    close(serverSocket);
    close(listeningSocket);

    return 0;
}