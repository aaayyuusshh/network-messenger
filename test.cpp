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

    /* TESTING OUT FONTS FOR THE TERMINAL GUI */

    //introduction message
    sleep(1);
    printf("\n              \\ (β’β‘β’) /\n");
    sleep(1);
    printf("-----------------------------------------\n");
    sleep(1);
    printf("πΎπππππ πππΏπ ππ πππ ππππππππππ πΌπππππΎπΌππππ \n"); 
    sleep(1);
    printf("-----------------------------------------\n");
    sleep(1);
 
    // printf("\n                (ββΏβ)\n");
    // //printf("-----------------------------------------");
    // printf("ππππππ πππΏπ ππ πππ ππππππππππ πΌπππππΎπΌππππ\n"); 
    // printf("-----------------------------------------\n");

    // printf("π»ππππππππ πππ πππππππ...\n");
    printf("ππΆπππ²π»πΆπ»π΄ π³πΌπΏ π°πΉπΆπ²π»ππ...\n");
    //printf("ππ²πΏ π²πππππππππ π°πππππππ !\n");
    printf("π§ππ£ ππΌπ»π»π²π°ππΆπΌπ» ππ°π°π²π½ππ²π± !\n");

    //menu options
    printf("\nπΏπππππ ππππππ ππππ πππ ππππππ πππ ππππππππππ:\n");
    //printf("\nα΄Κα΄α΄κ±α΄ α΄Κα΄α΄κ±α΄ κ°Κα΄α΄ α΄Κα΄ κ°α΄ΚΚα΄α΄‘ΙͺΙ΄Ι’ κ±α΄Κα΄α΄α΄Ιͺα΄Ι΄κ±:\n");
    //printf("(π·) π΄ππππ’ππ?\n(πΈ) π³ππππ’ππ?\n(πΉ) πΌππππππππ?\n(πΊ) ππππ?\n\n");
    printf("(1) α΄Ι΄α΄ΚΚα΄α΄?\n(2) α΄α΄α΄ΚΚα΄α΄?\n(3) α΄α΄κ±κ±α΄Ι’ΙͺΙ΄Ι’?\n(4) Qα΄Ιͺα΄?\n\n");
    //printf("(1) α΄Ι΄α΄ΚΚα΄α΄? (2) α΄α΄α΄ΚΚα΄α΄? (3) α΄α΄κ±κ±α΄Ι’ΙͺΙ΄Ι’? (4) Qα΄Ιͺα΄?\n\n");
    printf("π΄ππππ π’πππ πππππππ ππππ πππππππππ:\n\n");
    //printf("α΄Ι΄α΄α΄Κ Κα΄α΄Κ α΄α΄κ±ΙͺΚα΄α΄ α΄α΄Ι΄α΄ κ±α΄Κα΄α΄α΄Ιͺα΄Ι΄:\n\n");

    //messenger
    sleep(1);
    printf("..........                       ..........\n\n");
    sleep(1);
    printf("   πππππππ ππ πππ ππππππππ πππππππππ !\n");
    //printf("       α΄Κα΄α΄ \"Qα΄Ιͺα΄\" α΄α΄ α΄Ι΄α΄ κ±α΄κ±κ±Ιͺα΄Ι΄.\n");
    printf("       ππ’ππ \"ππππ\" ππ πππ πππππππ.\n\n");
    sleep(1);
    printf("..........                       ..........\n\n");
    sleep(1);
  
    printf("ππππ ππ ππππππ β \n");
    printf("π΅πππ ππππππ β \n");

    printf("\nπππΈπππΈπ½πΆ πΌπ΄πππ΄π½πΆπ΄π ... π±π°π²πΊ ππΎ πΌπ΄π½π πΎπΏππΈπΎπ½π\n");

    //quitting
    printf("πΎπππππ ππΌππ π½ππ π½ππ ! (β’β‘β’) / \n");
    printf("ππππππ ππΌππ π½ππ π½ππ ! (ββΏβ)Ι \n");

    /* ALOGORITHM TESTING */
    
    // int simple = 0;

    // //SIMPLE
    // while(simple == 1) {

    //     /* SIMPLE ENCRYPTION ALGORITHM */
    //     char input[1000] = "";

    //     printf("-- SIMPLE ENCRYPTION --\n");

    //     printf("Enter message you want to encrpt:");
    //     fgets(input, sizeof(input), stdin);
    //     input[strcspn(input, "\n")] = 0;

    //     int length= strlen(input);

    //     char vowels[length];                    
    //     char nonVowels[length];

    //     for(int i=0; i < length; i++){
            
    //         if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u'
    //            || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U'){

    //             vowels[i] = input[i];
    //             nonVowels[i]= ' ';
    //         }

    //         else{
    //             nonVowels[i] = input[i];
    //             vowels[i] = ' ';
    //         }
    //     }

    //     nonVowels[length]= '\0';
    //     vowels[length]='\0';

    //     printf("Non Vowels:\'%s\'\n", nonVowels);
    //     printf("Vowels:    \'%s\'\n", vowels);

    //     /* SIMPLE DECRYPTION ALGORITHM  */
    //     printf("\n-- SIMPLE DECRYPTION --\n");
    //     char nonVowels2[1000];
    //     printf("Enter the non-vowels:");
    //     fgets(nonVowels2, sizeof(nonVowels2), stdin);

    //     char vowels2[1000];
    //     printf("Enter the vowels:");
    //     fgets(vowels2, sizeof(vowels2), stdin);

    //     int len= strlen(nonVowels2);

    //     char decrypted[len];

    //     for(int j=0; j< len; j++){
    //         if(vowels2[j] == ' '){
    //             decrypted[j] = nonVowels2[j];
    //         }

    //         else if(vowels2[j] != ' '){
    //             decrypted[j] = vowels2[j];
    //         }
    //     }
    //     printf("Decrypted:%s\n", decrypted);
    // }

    // //ADVANCED
    // while(simple == 0){

    //     char input[1000] = "";

    //     printf("\n-- ADVANCED ENCRYPTION --\n");

    //     printf("Enter message you want to encrpt:");
    //     fgets(input, sizeof(input), stdin);
    //     input[strcspn(input, "\n")] = 0;

    //     /** ADVANCED ENCRYPTION ALGORITHM 
    //      * limitations:
    //      * - allocating too much space for vowel and non vowel arrays so the unused indexes will be filled w/ junk
    //      * - will not work if gap >= 10 (bc -"0" only works for 0-9 and i haven't implemented %10 trick)
    //      * */
    //     int length = strlen(input);

    //     //for exact memory allocation
    //     int vowelCount, nonVowelCount;
    //     for(int i=0; i< length; i++){       
    //     }

    //     char vowels[length];
    //     char nonVowels[length];

    //     int nonVowelIndex = 0 , vowelIndex= 0;
    //     int recentVowel = -1;

    //     for(int i=0; i< length; i++){

    //         //vowels
    //         if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u'
    //            || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U'){

    //                int gap = (i-1) - recentVowel;
    //                char charGap = gap +'0';

    //                vowels[vowelIndex++] = charGap;
    //                vowels[vowelIndex++] = input[i];

    //                recentVowel = i;
    //         }

    //         //non vowels
    //         else{

    //             nonVowels[nonVowelIndex++] = input[i];
    //         }
    //     }

    //     nonVowels[nonVowelIndex]='\0';
    //     vowels[vowelIndex]= '\0';
        
    //     printf("Non Vowels: \'%s\'\n", nonVowels);
    //     printf("Vowels:    \'%s\'\n", vowels);


    //     /* ADVANCED DECRYPTION ALGORITHM */
    //     /* Sample test:
    //     Non Vowels: 'Hll Thr!'
    //     Vowels:     '1e2o3e1e' 
    //     */

    //     printf("\n-- ADVANCED DECRYPTION --\n");
    //     char nonVowels2[1000];
    //     printf("Enter the non-vowels:");
    //     fgets(nonVowels2, sizeof(nonVowels2), stdin);
    //     nonVowels2[strcspn(nonVowels2, "\n")] = 0;

    //     char vowels2[1000];
    //     printf("Enter the vowels:");
    //     fgets(vowels2, sizeof(vowels2), stdin);
    //     vowels2[strcspn(vowels2, "\n")] = 0;

    //     char decrypted[1000];
    //     int vowelsLen= strlen(vowels2);
    //     int decryptedIndex= 0, nonVowelsIndex= 0;
    //     for(int i=0; i<vowelsLen; i++){
    //         int curr= vowels2[i] - '0';
    //         for(int j=0; j< curr; j++){
    //             decrypted[decryptedIndex++] = nonVowels2[nonVowelsIndex++]; //add non-vowels 
    //         }
    //         // printf("CHECK:%c, %d\n", vowels2[i+1], i);
    //         decrypted[decryptedIndex++]= vowels2[++i]; //add vowels
            
    //     }

    //     /**
    //      * in the case strlen(vowels) < strlen(nonvVowels
    //      * populating decrypted with remaining nonVowels*/
    //     int idx= nonVowelsIndex;
    //     for(int i=idx; i<strlen(nonVowels2);i++){
    //         decrypted[decryptedIndex++]= nonVowels2[nonVowelsIndex++];
    //     }

    //     decrypted[decryptedIndex] ='\0';
    //     printf("Decrypted: \'%s\'\n", decrypted);

    // }

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