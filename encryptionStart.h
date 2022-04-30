#pragma once
void encryptionStart(int, int);			//Conditions for performing encryption for the selected type and principle of operation

void GronsfeldDecode(int);										//Decryption with the Gronsfeld cipher		
void GronsfeldCode(int);										//Encryption with the Gronsfeld cipher

void RSAKeyGeneration(int);										//Key generation function for RSA encryption
void RSACode();													//Encryption with the Gronsfeld cipher
void RSADecode();												//Decryption with the Gronsfeld cipher

void VernamDecode();											//Decryption with the Vernam cipher
void VernamCode();												//Encryption with the Vernam cipher