# AES-Implementation---Scratch
## Overview
Advanced Encryption Standard is an encryption algorithm that is faster and has better security. It has application level implementation and the code is very simple and easy to understand. Here the implementation of the Advanced Encryption Standard - Encryption is coded in C++ language. The implementation is based on Deque Data Structure to reduce time complexity when shifting rows or columns. It takes Plaintext from the user as a 4 x 4 state matrix and a key as a 4 x 4 key matrix. Then it outputs the Ciphertext as a 4 x 4 matrix. The values within every matrix are hexadecimal values. The Plaintext and Key are of 16 bytes. Hence it the algorithm will take 10 rounds


## Functionalities
The AES Encryption algorithm contains 4 Major functionalities. There are:

  1. Add Round Key
  2. Substitute Bytes
  3. Shift Rows
  4. Mix Columns

It also has a “Key Expansion” functionality to expand the key. 

There are some supportive functions such as hexadecimal to decimal value converter, decimal to hexadecimal converter, a multiplication over the finite field GF(28).

There are some tables called “Recon Table”, “S-Box”, “Mix-Column Table”. They are implemented here with predefined values.

The implementation is based on 16byte key and plaintext. So changing byte won’t work here as the code is designed with limited functionalities for now. 

The code runs from the main function and start from system that is designed for choosing option. Then the encryption code is implemented separately on a function.

