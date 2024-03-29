#pragma once
#include <iostream>
#include <cstdlib>

#include <string>
#include <locale>
#include <windows.h>

#include <fstream>

#include <cstdint>
#include <vector>

#define PASSWORD "1337"

#define Clear1
#define DEBUGRSA1

using namespace std;

//void passwordChe�k();					//Password verification function
//void inputStrToTxt();					//Entering a string and saving it to a file or copying and encrypting your file
//int principleOfOperation();				//Choosing the principle of operation (encription or decryption)
//int cryptoTypeSelect(int);				//Encryption type select (Gronsfeld, RSA etc.)

bool checkIfNotANumber(string);			//The function of checking whether the entered string is a number
uint64_t stepen(uint64_t, int);			//8 byte unsigned int exponentiation function

//void funkTypeName(int);					//The function of writing the principle of action (print in consol what type of encryption your choose)
//void funkPrinciple(int);				//The function of writing the encryption type (print in consol what your do(encryption or decription))

//void encryptionStart(int, int);			//Conditions for performing encryption for the selected type and principle of operation
//void encryptionCheck(int, int);			//The function of starting the encryption check

//RSA encryption components
void randPrimeSearch(uint64_t&, uint64_t&, int&);				//Random prime number generation function (Erastophene sieve)
uint64_t greatestCommonDivisor(uint64_t, uint64_t);				//Greatest common divisor search function
uint64_t publicExponSearch(uint64_t, int);						//Public exponentiation calculation function
uint64_t privateExponSearch(uint64_t, uint64_t, uint64_t&);		//Private exponentiation calculation function (privateExpon * publicExpon = 1 + k * eiler) => (privateExpon = (1 + k * eiler)/publicExpon) must be in integer!!!
void RSAKeyGeneration(int);										//Key generation function for RSA encryption
//

void GronsfeldDecode(int);										//Decryption with the Gronsfeld cipher		
void GronsfeldCode(int);										//Encryption with the Gronsfeld cipher

void RSACode();													//Encryption with the Gronsfeld cipher
void RSADecode();												//Decryption with the Gronsfeld cipher

void VernamDecode();
void VernamCode();

void AtbashCode(int);											//Encryption with the Atbash cipher
void AtbashDecode(int);											//Decryption with the Atbash cipher

void SimpleTablePermutationCode(int);							//Encryption with the SimpleTablePermutation cipher
void SimpleTablePermutationDecode(int);							//Decryption with the SimpleTablePermutation cipher

//Shamir encryption components
int shamir(int, int, int);										//
int gcd(int, int);												//
int Extendedgcd(int, int, int&, int&);							//
bool simplenumberFerma(long long);								//
void ShamirKeygen(int);											//Key generation function for Shamir encryption
//

void ShamirCode();												//Encryption with the Shamir cipher
void ShamirDecode()												//Decryption with the Shamir cipher