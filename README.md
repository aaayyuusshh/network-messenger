# network-encrypter
👋 Welcome to a client/server (network) based application built in C++ through socket programming & algorithmic knowledge.

🧟 **Motivation:** Imagine there was an apocalypse where all the messaging apps in the world were destroyed and only the terminal remained. Well, no problem, I've got you covered! Run the server code in one of your friends computer & run the client code in your computer, and have a two way communication (just like your favourite text messaging app) through the terminal using the messenger feature. 
(Yes, this really works! just change the IP address in line 18 of the client code to your friends local machine's IP.)

**In progress**
  - Two way terminal based text messaging messenger ✅
  - Two way terminal based Tic-Tac-Toe game 
  
**Description**
  - Client has an option to use the messenger, encryption, & decryption feature.
  - Messenger: Simulates a text messaging environment which allows a two way communication between client and server through syncronized text messages. 
  - Encryption: Client can send server a message to encrypt & the server will use encryption algorithm & send client the encrypted message in 2 parts(vowels & non vowels) over the network.
  - Decryption: Client can send server a valid encrypted message in 2 parts (vowels & non vowels) & the server will use decyption algorithm & send client the decrypted message in 1 part over the network.
  - **NOTE:** Client/Server communication can be done in one **local machine** or over the **internet**, where the server and client are configured in different machines.


**How to Run Locally**
  - Clone this repository.
  - Set up 2 terminal windows(for client & server) and navigate (cd) to the directory with the repo files.
  - To compile server code, type **g++ -o s server.cpp** in terminal 1 & type **./s** to run.
  - To compile client code, type **g++ -o c client.cpp** in terminal 2 & type **./c** to run.
  - Server must be running before a client can run.
 
 **Messaging Feature:**

<img width="1437" alt="Screen Shot 2022-05-05 at 9 29 32 PM" src="https://user-images.githubusercontent.com/80851741/167062606-9e0f8c67-8737-4b1d-8f28-e146b4747ffc.png">

**Encryption Feature:**

<img width="1440" alt="Screen Shot 2022-05-05 at 9 37 27 PM" src="https://user-images.githubusercontent.com/80851741/167062995-883f4879-a1ff-42b0-b326-4f725a701df0.png">


**Decryption Feature:**

<img width="1440" alt="Screen Shot 2022-05-05 at 9 40 25 PM" src="https://user-images.githubusercontent.com/80851741/167063237-698bbcd2-a4d9-42a0-b98c-24854daa639d.png">

**What I Learnt**
  - Socket Programming Concepts.
  - Networking protocols of the Internet Protocol Stack.
  - Data transmission over a network through TCP & UDP protocols.
  - C++ Programming Basics.
  - Multiprocessing through fork() system call.

*Contact me if you would like me to demonstrate how to run this program over the internet and not just locally.*
