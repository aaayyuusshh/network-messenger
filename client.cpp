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
    - https://en.cppreference.com/w/ 
*/

/* GLOBAL VARIABLES & CONSTANTS */

/**
 * the SERVER_IP constant determines which machine the server code is running on.
 * change this constant accordingly based on the IP address of the machine you want the server code to run on.
 **/
const char *SERVER_IP = "127.0.0.1";                //local host
//const char *SERVER_IP = "136.159.5.25";           //csx.cpsc.ucalgary.ca (uofc server)
//const char *SERVER_IP = "136.159.5.27";           //csx3.cpsc.ucalgary.ca (uofc server)

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

    memset(&udpServerAddr, 0, sizeof(udpServerAddr));

    //address initialization for the UDP client
    udpServerAddr.sin_family= AF_INET;  
    udpServerAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    udpServerAddr.sin_port= htons(8000);
}

void printIntro(){
    sleep(1);
    printf("\n              \\ (•◡•) /\n\n");
    sleep(1);
    printf("𝘾𝙇𝙄𝙀𝙉𝙏 𝙎𝙄𝘿𝙀 𝙊𝙁 𝙏𝙃𝙀 𝙉𝙀𝙏𝙒𝙊𝙍𝙆𝙄𝙉𝙂 𝘼𝙋𝙋𝙇𝙄𝘾𝘼𝙏𝙄𝙊𝙉 \n"); 
    sleep(1);
    printf("-----------------------------------------\n");
    sleep(1);
}

void



int main(){

    printIntro();

    setupTCP();
    setupUDP();

    /* SEND // RECIEVE */
    while(1){
        //recieve user input regarding options
        char sendMsg[1000];
        printf("\n𝙿𝚕𝚎𝚊𝚜𝚎 𝚌𝚑𝚘𝚘𝚜𝚎 𝚏𝚛𝚘𝚖 𝚝𝚑𝚎 𝚏𝚘𝚕𝚕𝚘𝚠𝚒𝚗𝚐 𝚜𝚎𝚕𝚎𝚌𝚝𝚒𝚘𝚗𝚜:\n");
        printf("(1) ᴍᴇꜱꜱᴀɢɪɴɢ?\n(2) ᴇɴᴄʀʏᴘᴛ?\n(3) ᴅᴇᴄʀʏᴘᴛ?\n(4) Qᴜɪᴛ?\n\n");
        printf("𝙴𝚗𝚝𝚎𝚛 𝚢𝚘𝚞𝚛 𝚍𝚎𝚜𝚒𝚛𝚎𝚍 𝚖𝚎𝚗𝚞 𝚜𝚎𝚕𝚎𝚌𝚝𝚒𝚘𝚗: ");
        fgets(sendMsg, sizeof(sendMsg), stdin);
        sendMsg[strcspn(sendMsg, "\n")] = 0; //removes the \n character that fgets adds to sendMsg
        int option = sendMsg[0] - '0';
        printf("\n");

        //send desired user option to client
        int sendStatus= send(clientSocket, sendMsg, strlen(sendMsg), 0);
        if(sendStatus== -1){
            perror("Client cannot send to server!");
            return 1;
        }

        //messenger option
        if (option ==1 ){
            sleep(1);
            printf("..........                       ..........\n\n");
            sleep(1);
            printf("   𝘞𝘌𝘓𝘊𝘖𝘔𝘌 𝘛𝘖 𝘛𝘏𝘌 𝘛𝘌𝘙𝘔𝘐𝘕𝘈𝘓 𝘔𝘌𝘚𝘚𝘌𝘕𝘎𝘌𝘙 !\n");
            printf("       𝚃𝚢𝚙𝚎 \"𝚚𝚞𝚒𝚝\" 𝚝𝚘 𝚎𝚗𝚍 𝚜𝚎𝚜𝚜𝚒𝚘𝚗.\n\n");
            sleep(1);
            printf("..........                       ..........\n\n");
            sleep(1);
    
            while(1){
                //parsing & sending message to server
                char sendToServer[1000];
                printf("𝚂𝚎𝚗𝚍 𝚝𝚘 𝚜𝚎𝚛𝚟𝚎𝚛 ⇒ ");
                fgets(sendToServer, sizeof(sendToServer), stdin);
                sendToServer[strcspn(sendToServer, "\n")] = 0;

                //send message from client to server using TCP
                send(clientSocket, sendToServer, strlen(sendToServer), 0);

                if(strcmp(sendToServer, "quit") == 0){
                    printf("\n𝚀𝚄𝙸𝚃𝚃𝙸𝙽𝙶 𝙼𝙴𝚂𝚂𝙴𝙽𝙶𝙴𝚁 ... 𝙱𝙰𝙲𝙺 𝚃𝙾 𝙼𝙴𝙽𝚄 𝙾𝙿𝚃𝙸𝙾𝙽𝚂\n");
                    break;
                }

                //recieiving message from server 
                char recievedFromServer[1000] = "";
                recv(clientSocket, recievedFromServer, sizeof(recievedFromServer), 0);
                printf("𝙵𝚛𝚘𝚖 𝚂𝚎𝚛𝚟𝚎𝚛 ⇐ %s\n", recievedFromServer);
            }
        }

        //encrypt
        else if(option == 2){
            char toDevowel[1000];
            printf("𝙴𝚗𝚝𝚎𝚛 𝚢𝚘𝚞𝚛 𝚖𝚎𝚜𝚜𝚊𝚐𝚎 𝚝𝚘 𝚎𝚗𝚌𝚛𝚢𝚙𝚝: ");
            fgets(toDevowel, sizeof(toDevowel), stdin);
            toDevowel[strcspn(toDevowel, "\n")] = 0;

            //sending word to devowel to the server using TCP
            send(clientSocket, toDevowel, strlen(toDevowel), 0);

            usleep(10);

            //first send jiberrish to server so it can identify the client address to send messages to
            char jibb[] = "For address identification purposes";
            sendto(udpSocket, (const char *)jibb, strlen(jibb),0, (const struct sockaddr *) &udpServerAddr, sizeof(udpServerAddr));

            char recieveMsg[1000]="";
            
            //recieve non vowels through tcp
            recv(clientSocket, recieveMsg, 1000,0 );
            printf("𝚂𝚎𝚛𝚟𝚎𝚛 𝚜𝚎𝚗𝚝 %lu 𝚋𝚢𝚝𝚎𝚜 𝚘𝚏 𝚗𝚘𝚗-𝚟𝚘𝚠𝚎𝚕𝚜 𝚞𝚜𝚒𝚗𝚐 𝚃𝙲𝙿: \'%s\'\n", strlen(recieveMsg),recieveMsg);

            bzero(recieveMsg, sizeof(recieveMsg));

            //recieve vowels through upd
            /* recv(clientSocket, recieveMsg, 1000,0 ); */ //TCP way
            int len;
            recvfrom(udpSocket, (char *)recieveMsg, 1000, 0, (struct sockaddr *)&udpServerAddr, (socklen_t *)&len);
            printf("𝚂𝚎𝚛𝚟𝚎𝚛 𝚜𝚎𝚗𝚝 %lu 𝚋𝚢𝚝𝚎𝚜 𝚘𝚏 𝚟𝚘𝚠𝚎𝚕𝚜 𝚞𝚜𝚒𝚗𝚐 𝚄𝙳𝙿:     \'%s\'\n", strlen(recieveMsg), recieveMsg);
        }

        //decrypt
        else if(option ==3){
            //get and send non-vowels 
            char nonVowels[1000];
            printf("𝙴𝚗𝚝𝚎𝚛 𝚝𝚑𝚎 𝚗𝚘𝚗-𝚟𝚘𝚠𝚎𝚕𝚜: ");
            fgets(nonVowels, sizeof(nonVowels), stdin);
            nonVowels[strcspn(nonVowels, "\n")] = 0;

            //send non-vowels through TCP
            send(clientSocket, nonVowels, strlen(nonVowels),0);

            //get and send vowels
            char vowels[1000];
            printf("𝙴𝚗𝚝𝚎𝚛 𝚝𝚑𝚎 𝚟𝚘𝚠𝚎𝚕𝚜: ");
            fgets(vowels, sizeof(vowels), stdin);
            vowels[strcspn(vowels, "\n")] = 0;

            //send vowels through UDP
            /*send(clientSocket, vowels, strlen(vowels),0);*/ //TCP Way
            sendto(udpSocket, (const char *)vowels, strlen(vowels),0, (const struct sockaddr *) &udpServerAddr, sizeof(udpServerAddr));

            //recieve decrypted message from server
            char decryptedMsg[1000]="";
            recv(clientSocket,decryptedMsg , sizeof(decryptedMsg),0 );
            printf("𝚂𝚎𝚛𝚟𝚎𝚛 𝚜𝚎𝚗𝚝 %lu 𝚋𝚢𝚝𝚎𝚜 𝚘𝚏 𝚍𝚎𝚌𝚛𝚢𝚙𝚝𝚎𝚍 𝚖𝚎𝚜𝚜𝚊𝚐𝚎 𝚞𝚜𝚒𝚗𝚐 𝚃𝙲𝙿: \'%s\'\n",strlen(decryptedMsg),decryptedMsg);
        }
    
        //quit option
        else {
            printf("𝘾𝙇𝙄𝙀𝙉𝙏 𝙎𝘼𝙔𝙎 𝘽𝙔𝙀 𝘽𝙔𝙀 ! (•◡•) / \n");
            close(clientSocket);
            break;
        }
    }
        
    close(clientSocket); 

    return 0;
}