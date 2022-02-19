/* CLIENT SIDE CODE */

//Socket programming imports & more!
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>	

int flag= 1;

int main(){

    //address initialization
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family= AF_INET;
    address.sin_port= htons(8000);
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

    /* SEND // RECIEVE */
    while(1){
        //recieve user input regarding options
        char sendMsg[1000];
        printf("1(Devowel) , 2(Envowel), 3(Quit)?: ");
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

            send(clientSocket, toDevowel, strlen(toDevowel), 0);


            char recieveMsg[1000]="";

            //recieve non vowels
            recv(clientSocket, recieveMsg, 1000,0 );
            printf("Server sent non-vowels:\'%s\'\n", recieveMsg);

            bzero(recieveMsg, sizeof(recieveMsg));

            //recieve vowels
            recv(clientSocket, recieveMsg, 1000,0 );
            printf("Server sent vowels:    \'%s\'\n", recieveMsg);
        }

       //2= decrypt (envowel)
        else if(option ==2){

            //get and send non-vowels
            char nonVowels[1000];
            printf("Enter the non-vowels:");
            fgets(nonVowels, sizeof(nonVowels), stdin);
            nonVowels[strcspn(nonVowels, "\n")] = 0;

            send(clientSocket, nonVowels, strlen(nonVowels),0);

            //get and send vowels
            char vowels[1000];
            printf("Enter the vowels:");
            fgets(vowels, sizeof(vowels), stdin);
            vowels[strcspn(vowels, "\n")] = 0;

            send(clientSocket, vowels, strlen(vowels),0);

            //recieve decrypted message from server
            char decryptedMsg[1000]="";
            recv(clientSocket,decryptedMsg , sizeof(decryptedMsg),0 );
            printf("Server sent decrypted message: \'%s\'\n", decryptedMsg);
            printf("Length: %lu\n",strlen(decryptedMsg));

        }

        //3= quit

    }
        
    close(clientSocket); //close socket

    return 0;
}

