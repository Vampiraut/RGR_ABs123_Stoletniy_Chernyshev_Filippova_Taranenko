#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void encryptionCheck(int, int);			//The function of starting the encryption check

void passwordChe�k();					//Password verification function

void GronsfeldDecode(int);				//Decryption with the Gronsfeld cipher
void GronsfeldCode(int);				//Encryption with the Gronsfeld cipher

void RSADecode();						//Decryption with RSA cipher
void RSACode();							//Encryption with RSA cipher

void VernamDecode();					//Decryption with Vernam cipher
void VernamCode();						//Encryption with Vernam cipher