# AES-Implementation---Scratch
The implementation of the Advanced Encryption Standard - Encryption is coded in C++ language. It takes plaintext from user as a 4 x 4 state matrix and a key as a 4 x 4 matrix. Then it outputs the ciphertext as a 4 x 4 matrix. The values within the matrix are hexadecimal values.
It contains 4 Major functionalities. There are -
1. Add Round Key
2. Substitute Bytes
3. Shift Rows
4. Mix Columns
It also contain “Key Expansion” functionality to expand the key. 
There are some tables called “Recon Table”, “S-Box”, “Mix-Column Table”. They are implemented here with pre-defined value.
There are some supportive functions such as hexadecimal to decimal value converter, decimal to hexadecimal converter, hexadecimal value and a multiplication over the finite field GF(28).
The implementation is based on 16byte key and plaintext. So changing byte won’t work here as the code is designed with limited functionalities for now. 
