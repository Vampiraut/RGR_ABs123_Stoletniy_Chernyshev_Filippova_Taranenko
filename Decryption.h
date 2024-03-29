#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

void GronsfeldDecode(int);						//Decryption with the Gronsfeld cipher
void RSADecode();								//Decryption with RSA cipher
void MorseDecode();								//Decryption with Morse cipher

void VernamDecode(int);							//Decryption with Vernam cipher
void ElGamalDecode();							//Decryption with ElGamal cipher
void GibberishDecode();							//Decryption with Gibberish letter

void AtbashDecode(int);							//Decryption with Atbash cipher
void SimpleTablePermutationDecode(int);			//Decryption with Simple Table Permutation
void ShamirDecode();							//Decryption with Shamir cipher

void VigenerDecode(vector<vector<char>>, int);	//Decryption with Vigener cipher
void BinaryDecode();							//Decryption with Binary cipher
void HillDecode(int);								//Decryption with Hila cipher

bool checkIfNotANumber(string);			//The function of checking whether the entered string is a number
int deg(int, int, int);
int mod(int, int, int);
int shamir(int, int, int);

void funkTypeName(int);					//The function of writing the principle of action (print in consol what type of encryption your choose)
void funkPrinciple(int);				//The function of writing the encryption type (print in consol what your do(encryption or decription))