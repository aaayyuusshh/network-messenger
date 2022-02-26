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
 
 **Sample Run**
 
<img width="1423" alt="img" src="https://user-images.githubusercontent.com/80851741/155859349-90ba5ce7-64d2-40e4-b3c1-8abb449bf21c.png">

**What I Learnt**
  - Socket Programming Concepts.
  - Data transmission over a network through TCP & UDP protocols.
  - C++ Programming Basics.
  - Multiprocessing through fork() system call.
