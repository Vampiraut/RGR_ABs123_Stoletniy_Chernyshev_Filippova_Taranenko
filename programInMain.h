#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#define PASSWORD "1111"

using namespace std;

enum Ciphers
{
	Gronsfeld = 1,
	RSA,
	Morse,
	Vernam,
	SomeCip5,
	SomeCip6,
	Atbash,
	SimpleTablePermutation,
	SomeCip9,
	Vigener,
	Binary,
	Gibberish
};

enum Principle
{
	Encription = 1,
	Decription
};

void passwordCheñk();					//Password verification function

void inputStrToTxt();					//Entering a string and saving it to a file or copying and encrypting your file

int principleOfOperation();				//Choosing the principle of operation (encription or decryption)
int cryptoTypeSelect(int);				//Encryption type select (Gronsfeld, RSA etc.)

void encryptionStart(int, int);			//Conditions for performing encryption for the selected type and principle of operation
void encryptionCheck(int, int);			//The function of starting the encryption check

void funkPrinciple(int);				//The function of writing the encryption type (print in consol what your do(encryption or decription))

//encryption functions
void GronsfeldDecode(int);						//Decryption with the Gronsfeld cipher		
void GronsfeldCode(int);						//Encryption with the Gronsfeld cipher

void RSAKeyGeneration(int);						//Key generation function for RSA encryption
void RSACode();									//Encryption with RSA cipher
void RSADecode();								//Decryption with RSA cipher

//void MorseCode();								//Encryption with Morse cipher
//void MorseDecode();								//Decryption with Morse cipher

void VernamDecode();							//Decryption with Vernam cipher
void VernamCode();								//Encryption with Vernam cipher







void AtbashCode(int);
void AtbashDecode(int);

void SimpleTablePermutationCode(int);
void SimpleTablePermutationDecode(int);



vector<vector<char>> VigenerMatrixCreate();
void VigenerCode(vector<vector<char>>, int);	//Encryption with Vigener cipher
void VigenerDecode(vector<vector<char>>, int);	//Decryption with Vigener cipher

//void BinaryCode();								//Encryption with Binary cipher
//void BinaryDecode();							//Decryption with Binary cipher

//void GibberishCode();							//Encryption with Gibberish letter
//void GibberishDecode();							//Decryption with Gibberish letter