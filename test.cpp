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

    int simple = 0;

    while(simple == 1) {

        /* SIMPLE ENCRYPTION ALGORITHM */
        char input[1000] = "";

        printf("-- SIMPLE ENCRYPTION --\n");

        printf("Enter message you want to encrpt:");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

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

        /* SIMPLE DECRYPTION ALGORITHM  */
        printf("\n-- SIMPLE DECRYPTION --\n");
        char nonVowels2[1000];
        printf("Enter the non-vowels:");
        fgets(nonVowels2, sizeof(nonVowels2), stdin);

        char vowels2[1000];
        printf("Enter the vowels:");
        fgets(vowels2, sizeof(vowels2), stdin);

        int len= strlen(nonVowels2);

        char decrypted[len];

        for(int j=0; j< len; j++){
            if(vowels2[j] == ' '){
                decrypted[j] = nonVowels2[j];
            }

            else if(vowels2[j] != ' '){
                decrypted[j] = vowels2[j];
            }
        }
        printf("Decrypted:%s\n", decrypted);
    }

    if(simple == 0){

        char input[] = "Hello There!";

        /** ADVANCED ENCRYPTION ALGORITHM 
         * limitations:
         * - allocating too much space for vowel and non vowel arrays so the unused indexes will be filled w/ junk
         * - will not work if gap >= 10 (bc -"0" only works for 0-9 and i haven't implemented %10 trick)
         * */
        int length = strlen(input);

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
            if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u'
               || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U'){

                   int gap = (i-1) - recentVowel;
                   char charGap = gap +'0';

                   vowels[vowelIndex++] = charGap;
                   vowels[vowelIndex++] = input[i];

                   recentVowel = i;
            }

            //non vowels
            else{

                nonVowels[nonVowelIndex++] = input[i];
            }
        }

        nonVowels[nonVowelIndex]='\0';
        vowels[vowelIndex]= '\0';
        
        printf("Non Vowels:%s\n", nonVowels);
        printf("Vowels:    %s\n", vowels);

    }

    /* GET INPUT */
    // char sendMsg[1000];
    // printf("Enter your message to server: ");
    // fgets( `sendMsg, sizeof(sendMsg), stdin);
    // printf("size of sendMsg= %lu \n", sizeof(sendMsg));
    // printf("sendMsg: %s \n", sendMsg);
    // printf("sizeof of sendMsg= %lu \n", sizeof(sendMsg));
    // printf("strlen of sendMsg= %lu \n", strlen(sendMsg));
    
    return 0;
}