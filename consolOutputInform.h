#pragma once
#include <iostream>

using namespace std;

enum Ciphers
{
	Gronsfeld = 1,
	RSA,
	Morse,
	Vernam,
	ElGamal,
	Gibberish,
	Atbash,
	SimpleTablePermutation,
	Shamir,
	Vigener,
	Binary,
	Hil
};

enum Principle
{
	Encription = 1,
	Decription
};

void funkTypeName(int);					//The function of writing the encryption type (print in consol what your do(encryption or decription))
void funkPrinciple(int);				//The function of writing the principle of action (print in consol what type of encryption your choose)