# network-encrypter
👋 Welcome to a client/server (network) based text encryptor built in C++ through socket programming.

**Quick Description**
  - Client has an option to encrypt or decrypt a message.
  - Encrypt: Client can send server a message to encrypt & the server will send client the encrypted message in 2 parts(vowels & non vowels) over the network.
  - Decrypt: Client can send server a valid encrypted message in 2 parts (vowels & non vowels) & the server will send client the decrypted message in 1 part over the network.
  - **NOTE:** Client/Server communication can be done in one local machine or over the internet, where the server and client are configured in different machines.


**How to Run**
  - Clone this repository.
  - Set up 2 terminal windows(for client & server) and navigate to the directory with the repo files.
  - To compile server code, type **g++ -o s server.cpp** in terminal 1 & type **./s** to run.
  - To compile client code, type **g++ -o c client.cpp** in terminal 2 & type **./c** to run.
  - Server must be running before a client can run.
 
 
