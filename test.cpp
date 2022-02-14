/* File used for testing and trying things out and all that good stuff */

#include<stdio.h>
#include<string.h>
#include<unistd.h>	

int main(){
 
    /**     
     *           0 1 2 3 4 5 6 7 8 9 10 11            
     *  input = "H e l l o  t h e r e   ! ""
     *
     *  vowels= " e  o   e e"
     *  non-vowels= "H ll  th r !"
     * */

    //will only work for inputs without a space!

    //SIMPLE ENCRYPTION ALGORITHM
    while(1) {
        char input[1000] = "";

        printf("Enter message you want to encrpt: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        /*          0123456789
            input= "HelloThere", length = 10

            vowels = " e  o  e e"
            nonv   = "H ll Th r !"

        */

        int length= strlen(input);

        char vowels[length];                    
        char nonVowels[length];

        for(int i=0; i < length; i++){
            
            if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u'
               || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U'){

                vowels[i] = input[i];
                nonVowels[i]= ' ';
            }

            else{
                nonVowels[i] = input[i];
                vowels[i] = ' ';
            }
        }

        printf("Non Vowels:%s\n", nonVowels);
        printf("Vowels:    %s\n", vowels);

    }

    //SIMPLE DECRYPTION ALGO

    char vowels2[]=     "H ll  th r !";
    char nonVowels2[]=  " e  o   e e "



    // //get input
    // char sendMsg[1000];
    // printf("Enter your message to server: ");
    // fgets(sendMsg, sizeof(sendMsg), stdin);
    // printf("size of sendMsg= %lu \n", sizeof(sendMsg));
    // printf("sendMsg: %s \n", sendMsg);
    // printf("sizeof of sendMsg= %lu \n", sizeof(sendMsg));
    // printf("strlen of sendMsg= %lu \n", strlen(sendMsg));
    
    return 0;
}