#pragma once
#include <iostream>
#include <windows.h>

void passwordCheñk();					//Password verification function
void inputStrToTxt();					//Entering a string and saving it to a file or copying and encrypting your file
int principleOfOperation();				//Choosing the principle of operation (encription or decryption)
int cryptoTypeSelect(int);				//Encryption type select (Gronsfeld, RSA etc.)
void encryptionStart(int, int);			//Conditions for performing encryption for the selected type and principle of operation
void encryptionCheck(int, int);			//The function of starting the encryption check