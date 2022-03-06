# network-encrypter
👋 Welcome to a client/server (network) based text encryptor built in C++ through socket programming.

**Description**
  - Client has an option to encrypt or decrypt a message.
  - Encrypt: Client can send server a message to encrypt & the server will send client the encrypted message in 2 parts(vowels & non vowels) over the network.
  - Decrypt: Client can send server a valid encrypted message in 2 parts (vowels & non vowels) & the server will send client the decrypted message in 1 part over the network.
  - **NOTE:** Client/Server communication can be done in one local machine or over the internet, where the server and client are configured in different machines.
  - In process: Program supports multiple concurrent client connections through multiprocessing.


**How to Run Locally**
  - Clone this repository.
  - Set up 2 terminal windows(for client & server) and navigate (cd) to the directory with the repo files.
  - To compile server code, type **g++ -o s server.cpp** in terminal 1 & type **./s** to run.
  - To compile client code, type **g++ -o c client.cpp** in terminal 2 & type **./c** to run.
  - Server must be running before a client can run.
 
 **Sample Run 1**
<img width="1421" alt="Screen Shot 2022-03-05 at 7 35 34 PM" src="https://user-images.githubusercontent.com/80851741/156907067-0398f52a-f73b-448c-bea2-c6bc6b515f71.png">

 **Sample Run 2: Can we sucesfully encrypt & decrypt a long paragraph?**
 <img width="1423" alt="Screen Shot 2022-03-05 at 7 50 28 PM" src="https://user-images.githubusercontent.com/80851741/156907380-dc0c642a-b54d-4da1-9b13-366403a5afb1.png">

**What I Learnt**
  - Socket Programming Concepts.
  - Networking protocols of the Internet Protocol Stack.
  - Data transmission over a network through TCP & UDP protocols.
  - C++ Programming Basics.
  - Multiprocessing through fork() system call.

*Contact me if you would like me to demonstrate how to run this program over the internet and not just locally.*
