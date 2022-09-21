//Socket programming imports & more!
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>	
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>

/* GLOBAL VARIABLES & CONSTANTS */

//const int ENCODING_TYPE_FLAG = 0;   //0: simple encryption algo
const int ENCODING_TYPE_FLAG = 1;     //1: complex encryption algo

int listeningSocket;
int serverSocket;
int udpSocket;
struct sockaddr_in udpServerAddr, udpClientAddr;

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
    //printf("Listening socket created.\n");

    //binding address w/ listening socket
    int bindStatus;     
    bindStatus= bind(listeningSocket, (struct sockaddr *)&address, sizeof(address));
    if(bindStatus == -1){
        perror("Binding failed!");
    }
    //printf("Binding successful.\n");

    //server listening for clients
    int listenStatus;
    listenStatus = listen(listeningSocket, 5);
    if(listenStatus == -1){
        perror("Listening failed!");
    }
     printf("𝙻𝚒𝚜𝚝𝚎𝚗𝚒𝚗𝚐 𝚏𝚘𝚛 𝚌𝚕𝚒𝚎𝚗𝚝𝚜...\n");
    
    //accept an incoming client connection
    serverSocket = accept(listeningSocket, NULL, NULL);
    if(serverSocket == -1){
        perror("accept() call failed!");
    }
    printf("𝚃𝙲𝙿 𝙲𝚘𝚗𝚗𝚎𝚌𝚝𝚒𝚘𝚗 𝙰𝚌𝚌𝚎𝚙𝚝𝚎𝚍 !\n"); 
}

//NOTE: UDP Is connectionless!
void setupUDP(){

    //creating udp socket file descriptor
    if((udpSocket = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        perror("UPD socket creation failed!\n");
        exit(EXIT_FAILURE);
    }
    //printf("UDP socket created.\n");

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

    printf("𝚂𝚎𝚗𝚝 %lu 𝚋𝚢𝚝𝚎𝚜 𝚘𝚏 𝚗𝚘𝚗-𝚟𝚘𝚠𝚎𝚕𝚜 \'%s\' 𝚞𝚜𝚒𝚗𝚐 𝚃𝙲𝙿\n", strlen(nonVowels), nonVowels);
    printf("𝚂𝚎𝚗𝚝 %lu 𝚋𝚢𝚝𝚎𝚜 𝚘𝚏 𝚟𝚘𝚠𝚎𝚕𝚜 \'%s\' 𝚞𝚜𝚒𝚗𝚐 𝚄𝙳𝙿\n", strlen(vowels), vowels);
   
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

//paramenters: non vowels & vowels the client sent
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
    printf("𝚂𝚎𝚗𝚝 %lu 𝚋𝚢𝚝𝚎𝚜 𝚘𝚏 𝚍𝚎𝚌𝚛𝚢𝚙𝚝𝚎𝚍 𝚖𝚎𝚜𝚜𝚊𝚐𝚎 \'%s\' 𝚞𝚜𝚒𝚗𝚐 𝚃𝙲𝙿\n", strlen(decrypted),decrypted);

    //send decrypted message to server
    send(serverSocket, decrypted, strlen(decrypted), 0);
}

void complexEncrypt(char clientMessage[]){ 
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

    printf("𝚂𝚎𝚗𝚝 %lu 𝚋𝚢𝚝𝚎𝚜 𝚘𝚏 𝚗𝚘𝚗-𝚟𝚘𝚠𝚎𝚕𝚜 \'%s\' 𝚞𝚜𝚒𝚗𝚐 𝚃𝙲𝙿\n", strlen(nonVowels), nonVowels);
    printf("𝚂𝚎𝚗𝚝 %lu 𝚋𝚢𝚝𝚎𝚜 𝚘𝚏 𝚟𝚘𝚠𝚎𝚕𝚜 \'%s\' 𝚞𝚜𝚒𝚗𝚐 𝚄𝙳𝙿\n", strlen(vowels), vowels);
   
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

void advancedEncrypt(char clientMessage[]){

    int length = strlen(clientMessage);

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
    
    printf("𝚂𝚎𝚗𝚝 %lu 𝚋𝚢𝚝𝚎𝚜 𝚘𝚏 𝚗𝚘𝚗-𝚟𝚘𝚠𝚎𝚕𝚜 \'%s\' 𝚞𝚜𝚒𝚗𝚐 𝚃𝙲𝙿\n", strlen(nonVowels), nonVowels);
    printf("𝚂𝚎𝚗𝚝 %lu 𝚋𝚢𝚝𝚎𝚜 𝚘𝚏 𝚟𝚘𝚠𝚎𝚕𝚜 \'%s\' 𝚞𝚜𝚒𝚗𝚐 𝚄𝙳𝙿\n", strlen(vowels), vowels);
   

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
void advancedDecrypt(char nonVowels2[], char vowels2[]){
    
    char decrypted[1000];
    int vowelsLen= strlen(vowels2);
    int decryptedIndex= 0, nonVowelsIndex= 0;
    for(int i=0; i<vowelsLen; i++){
        int curr= vowels2[i] - '0';
        for(int j=0; j< curr; j++){
            decrypted[decryptedIndex++] = nonVowels2[nonVowelsIndex++]; //add non-vowels 
        }
        decrypted[decryptedIndex++]= vowels2[++i]; //add vowels
    }

    /**
     * in the case strlen(vowels) < strlen(nonvVowels.
     * populating decrypted with remaining nonVowels. */
    int idx= nonVowelsIndex;
    for(int i=idx; i<strlen(nonVowels2);i++){
        decrypted[decryptedIndex++]= nonVowels2[nonVowelsIndex++];
    }   

    decrypted[decryptedIndex] ='\0';

    printf("𝚂𝚎𝚗𝚝 %lu 𝚋𝚢𝚝𝚎𝚜 𝚘𝚏 𝚍𝚎𝚌𝚛𝚢𝚙𝚝𝚎𝚍 𝚖𝚎𝚜𝚜𝚊𝚐𝚎 \'%s\' 𝚞𝚜𝚒𝚗𝚐 𝚃𝙲𝙿\n", strlen(decrypted),decrypted);
   
    //send decrypted message to server
    send(serverSocket, decrypted, strlen(decrypted), 0);
}

void printIntro(){
    
    sleep(1);
    printf("\n                (◑‿◑)\n\n");
    sleep(1);
    printf("𝙎𝙀𝙍𝙑𝙀𝙍 𝙎𝙄𝘿𝙀 𝙊𝙁 𝙏𝙃𝙀 𝙉𝙀𝙏𝙒𝙊𝙍𝙆𝙄𝙉𝙂 𝘼𝙋𝙋𝙇𝙄𝘾𝘼𝙏𝙄𝙊𝙉\n"); 
    sleep(1);
    printf("-----------------------------------------\n");
    sleep(1);
}

void printMessengerIntro(){

    sleep(1);
    printf("..........                       ..........\n\n");
    sleep(1);
    printf("   𝘞𝘌𝘓𝘊𝘖𝘔𝘌 𝘛𝘖 𝘛𝘏𝘌 𝘛𝘌𝘙𝘔𝘐𝘕𝘈𝘓 𝘔𝘌𝘚𝘚𝘌𝘕𝘎𝘌𝘙 !\n");
    printf("       𝚃𝚢𝚙𝚎 \"𝚚𝚞𝚒𝚝\" 𝚝𝚘 𝚎𝚗𝚍 𝚜𝚎𝚜𝚜𝚒𝚘𝚗.\n\n");
    sleep(1);
    printf("..........                       ..........\n\n");
    sleep(1);
}

void messenger(){

    printMessengerIntro();

    while(1){
        //recieving message from client
        char recievedFromClient[1000] = "";
        recv(serverSocket, recievedFromClient, sizeof(recievedFromClient), 0);
        printf("𝙵𝚛𝚘𝚖 𝙲𝚕𝚒𝚎𝚗𝚝 ⇐ %s\n", recievedFromClient);  

        if(strcmp(recievedFromClient, "quit") == 0){
            printf("\nEXITED 𝙼𝙴𝚂𝚂𝙴𝙽𝙶𝙴𝚁 ...\n");
            break;
        }

        //parsing and sending message to client
        char sendToClient[1000];
        printf("𝚂𝚎𝚗𝚍 𝚝𝚘 𝙲𝚕𝚒𝚎𝚗𝚝 ⇒ ");
        fgets(sendToClient, sizeof(sendToClient), stdin);
        sendToClient[strcspn(sendToClient, "\n")] = 0;

        //send message from server to client using TCP... not using UDP atm for messaging
        send(serverSocket, sendToClient, sizeof(sendToClient), 0);         
    }
}

void encryption(){
    
    char toDevowel[1000]="";
    recv(serverSocket, toDevowel, 1000, 0);
    printf("𝙲𝚕𝚒𝚎𝚗𝚝'𝚜 𝚖𝚎𝚜𝚜𝚊𝚐𝚎 𝚝𝚘 𝚎𝚗𝚌𝚛𝚢𝚙𝚝: \'%s\'\n", toDevowel);

    // send(serverSocket, "vowels", strlen("vowels"), 0);
    // send(serverSocket, "non-vowels", strlen("non-vowels"), 0);

    if(ENCODING_TYPE_FLAG == 0){
        simpleEncrypt(toDevowel);
    }
    else{
        advancedEncrypt(toDevowel);
    } 
}

void decryption(){

    char nonVowels[1000]="";
    char vowels[1000]="";
    
    //recieve nonvowels from client
    recv(serverSocket, nonVowels, 1000, 0);
    printf("𝙽𝚘𝚗-𝚟𝚘𝚠𝚎𝚕𝚜 𝚏𝚛𝚘𝚖 𝚌𝚕𝚒𝚎𝚗𝚝:  \'%s\'\n", nonVowels);

    usleep(20);

    //recieve vowels from client (through UPD)
    /* recv(serverSocket, vowels, 1000, 0);*/ //TCP WAY
    recvfrom(udpSocket, vowels, 1000, 0, 0, 0);
    printf("𝚅𝚘𝚠𝚎𝚕𝚜 𝚏𝚛𝚘𝚖 𝚌𝚕𝚒𝚎𝚗𝚝: \'%s\'\n", vowels);

        if(ENCODING_TYPE_FLAG == 0){
        simpleDecrypt(nonVowels, vowels);
    }
    else{
        advancedDecrypt(nonVowels, vowels);
    } 
}

void closeSockets(){
    close(serverSocket);
    close(listeningSocket);
}

int main(){

    printIntro();

    setupTCP();
    setupUDP();

    int recieveStatus;
    char recieveCharOption[1000]="";

    //recieving clients option: 1, 2, 3, or 4
    while((recieveStatus =  recv(serverSocket, recieveCharOption, 1000, 0)) > 0){

        printf("\n𝙲𝚕𝚒𝚎𝚗𝚝 𝚙𝚒𝚌𝚔𝚎𝚍 𝚖𝚎𝚗𝚞 𝚘𝚙𝚝𝚒𝚘𝚗: %s\n\n", recieveCharOption);
        int option = atoi(recieveCharOption);

        if(option == 1){
            messenger();  
        }

        else if(option == 2){
            encryption();   
        }

        else if(option == 3){
            decryption();
        }

        else{
            printf("𝙎𝙀𝙍𝙑𝙀𝙍 𝙎𝘼𝙔𝙎 𝘽𝙔𝙀 𝘽𝙔𝙀 (◑‿◑)ɔ ! \n");
            close(serverSocket);
        }
    }

    //closing sockets when done
    closeSockets();

    return 0;
}