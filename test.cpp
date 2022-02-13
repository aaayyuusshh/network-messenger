/* File used for testing and trying things out and all that good stuff */

#include<stdio.h>
#include<string.h>
#include<unistd.h>	

int main(){

    //get input
    char sendMsg[1000];
    printf("Enter your message to server: ");
    fgets(sendMsg, sizeof(sendMsg), stdin);
    printf("size of sendMsg= %lu \n", sizeof(sendMsg));
    printf("sendMsg: %s \n", sendMsg);
    printf("sizeof of sendMsg= %lu \n", sizeof(sendMsg));
    printf("strlen of sendMsg= %lu \n", strlen(sendMsg));
    
}