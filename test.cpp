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
    //sleep(1);
    printf("\n              \\ (•◡•) /\n");
    //sleep(1);
    //printf("-----------------------------------------\n");
    //sleep(1);
    printf("𝘾𝙇𝙄𝙀𝙉𝙏 𝙎𝙄𝘿𝙀 𝙊𝙁 𝙏𝙃𝙀 𝙉𝙀𝙏𝙒𝙊𝙍𝙆𝙄𝙉𝙂 𝘼𝙋𝙋𝙇𝙄𝘾𝘼𝙏𝙄𝙊𝙉 \n"); 
    //sleep(1);
    printf("-----------------------------------------\n");
    //sleep(1);

    
    printf("\n                (◑‿◑)\n");
    //printf("-----------------------------------------");
    printf("𝙎𝙀𝙍𝙑𝙀𝙍 𝙎𝙄𝘿𝙀 𝙊𝙁 𝙏𝙃𝙀 𝙉𝙀𝙏𝙒𝙊𝙍𝙆𝙄𝙉𝙂 𝘼𝙋𝙋𝙇𝙄𝘾𝘼𝙏𝙄𝙊𝙉\n"); 
    printf("-----------------------------------------\n");

    // printf("𝙻𝚒𝚜𝚝𝚎𝚗𝚒𝚗𝚐 𝚏𝚘𝚛 𝚌𝚕𝚒𝚎𝚗𝚝𝚜...\n");
    printf("𝗟𝗶𝘀𝘁𝗲𝗻𝗶𝗻𝗴 𝗳𝗼𝗿 𝗰𝗹𝗶𝗲𝗻𝘁𝘀...\n");
    //printf("𝚃𝙲𝙿 𝙲𝚘𝚗𝚗𝚎𝚌𝚝𝚒𝚘𝚗 𝙰𝚌𝚌𝚎𝚙𝚝𝚎𝚍 !\n");
    printf("𝗧𝗖𝗣 𝗖𝗼𝗻𝗻𝗲𝗰𝘁𝗶𝗼𝗻 𝗔𝗰𝗰𝗲𝗽𝘁𝗲𝗱 !\n");
   


    //menu option
    printf("\n𝙿𝚕𝚎𝚊𝚜𝚎 𝚌𝚑𝚘𝚘𝚜𝚎 𝚏𝚛𝚘𝚖 𝚝𝚑𝚎 𝚏𝚘𝚕𝚕𝚘𝚠𝚒𝚗𝚐 𝚜𝚎𝚕𝚎𝚌𝚝𝚒𝚘𝚗𝚜:\n");
    //printf("\nᴘʟᴇᴀꜱᴇ ᴄʜᴏᴏꜱᴇ ꜰʀᴏᴍ ᴛʜᴇ ꜰᴏʟʟᴏᴡɪɴɢ ꜱᴇʟᴇᴄᴛɪᴏɴꜱ:\n");
    //printf("(𝟷) 𝙴𝚗𝚌𝚛𝚢𝚙𝚝?\n(𝟸) 𝙳𝚎𝚌𝚛𝚢𝚙𝚝?\n(𝟹) 𝙼𝚎𝚜𝚜𝚊𝚐𝚒𝚗𝚐?\n(𝟺) 𝚀𝚞𝚒𝚝?\n\n");
    printf("(1) ᴇɴᴄʀʏᴘᴛ?\n(2) ᴅᴇᴄʀʏᴘᴛ?\n(3) ᴍᴇꜱꜱᴀɢɪɴɢ?\n(4) Qᴜɪᴛ?\n\n");
    //printf("(1) ᴇɴᴄʀʏᴘᴛ? (2) ᴅᴇᴄʀʏᴘᴛ? (3) ᴍᴇꜱꜱᴀɢɪɴɢ? (4) Qᴜɪᴛ?\n\n");
    printf("𝙴𝚗𝚝𝚎𝚛 𝚢𝚘𝚞𝚛 𝚍𝚎𝚜𝚒𝚛𝚎𝚍 𝚖𝚎𝚗𝚞 𝚜𝚎𝚕𝚎𝚌𝚝𝚒𝚘𝚗:\n\n");
    //printf("ᴇɴᴛᴇʀ ʏᴏᴜʀ ᴅᴇꜱɪʀᴇᴅ ᴍᴇɴᴜ ꜱᴇʟᴇᴄᴛɪᴏɴ:\n\n");

    //messenger
 
    //sleep(1);
    printf("..........                       ..........\n\n");
    //sleep(1);
    printf("   𝘞𝘌𝘓𝘊𝘖𝘔𝘌 𝘛𝘖 𝘛𝘏𝘌 𝘛𝘌𝘙𝘔𝘐𝘕𝘈𝘓 𝘔𝘌𝘚𝘚𝘌𝘕𝘎𝘌𝘙 !\n");
    //printf("       ᴛʏᴘᴇ \"Qᴜɪᴛ\" ᴛᴏ ᴇɴᴅ ꜱᴇꜱꜱɪᴏɴ.\n");
    printf("       𝚃𝚢𝚙𝚎 \"𝚚𝚞𝚒𝚝\" 𝚝𝚘 𝚎𝚗𝚍 𝚜𝚎𝚜𝚜𝚒𝚘𝚗.\n\n");
    //sleep(1);
    printf("..........                       ..........\n\n");
    //sleep(1);
    
    
    //printf("𝘞𝘌𝘓𝘊𝘖𝘔𝘌 𝘛𝘖 𝘛𝘏𝘌 𝘔𝘌𝘚𝘚𝘌𝘕𝘎𝘌𝘙 𝘈𝘗𝘗𝘓𝘐𝘊𝘈𝘛𝘐𝘖𝘕 !\n");
  
    printf("𝚂𝚎𝚗𝚍 𝚝𝚘 𝚜𝚎𝚛𝚟𝚎𝚛 ⇒ \n");
    printf("𝙵𝚛𝚘𝚖 𝚂𝚎𝚛𝚟𝚎𝚛 ⇐ \n");

    printf("\n𝚀𝚄𝙸𝚃𝚃𝙸𝙽𝙶 𝙼𝙴𝚂𝚂𝙴𝙽𝙶𝙴𝚁 ... 𝙱𝙰𝙲𝙺 𝚃𝙾 𝙼𝙴𝙽𝚄 𝙾𝙿𝚃𝙸𝙾𝙽𝚂\n");

    printf("𝘾𝙇𝙄𝙀𝙉𝙏 𝙎𝘼𝙔𝙎 𝘽𝙔𝙀 𝘽𝙔𝙀 ! (•◡•) / \n");
    printf("𝙎𝙀𝙍𝙑𝙀𝙍 𝙎𝘼𝙔𝙎 𝘽𝙔𝙀 𝘽𝙔𝙀 ! (◑‿◑)ɔ \n");
    
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