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
void VernamDecode();							//Decryption with Vernam cipher
void AtbashDecode(int);							//Decryption with Atbash cipher
void SimpleTablePermutationDecode(int);			//Decryption with Simple Table Permutation
void VigenerDecode(vector<vector<char>>, int);	//Decryption with Vigener cipher
void BinaryDecode();							//Decryption with Binary cipher

bool checkIfNotANumber(string);			//The function of checking whether the entered string is a number

void funkTypeName(int);					//The function of writing the principle of action (print in consol what type of encryption your choose)
void funkPrinciple(int);				//The function of writing the encryption type (print in consol what your do(encryption or decription))