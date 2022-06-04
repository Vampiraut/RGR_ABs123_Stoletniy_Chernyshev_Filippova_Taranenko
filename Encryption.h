#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

void GronsfeldCode(int);						//Encryption with the Gronsfeld cipher
void RSACode();									//Encryption with RSA cipher
void MorseCode();								//Encryption with Morse cipher

void VernamCode();								//Encryption with Vernam cipher
void ElGamalCode();								//Encryption with ElGamal cipher
void GibberishCode();							//Encryption with Gibberish letter

void AtbashCode(int);							//Encryption with Atbash cipher
void SimpleTablePermutationCode(int);			//Encryption with Simple Table Permutation
void ShamirCode();								//Encryption with Shamir cipher

void VigenerCode(vector<vector<char>>, int);	//Encryption with Vigener cipher
void BinaryCode();								//Encryption with Binary cipher


bool checkIfNotANumber(string);					//The function of checking whether the entered string is a number
int deg(int, int, int);
int mod(int, int, int);
int shamir(int, int, int);

void funkTypeName(int);							//The function of writing the principle of action (print in consol what type of encryption your choose)
void funkPrinciple(int);						//The function of writing the encryption type (print in consol what your do(encryption or decription))