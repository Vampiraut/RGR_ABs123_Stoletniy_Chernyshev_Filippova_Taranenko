#pragma once
#include <iostream>
#include <cstdlib>

#include <string>
#include <locale>
#include <windows.h>

#include <fstream>

#include <cstdint>
#include <time.h>
#include <vector>


#define Clear
#define DEBUGRSA1


using namespace std;

//RSA encryption components
void randPrimeSearch(uint64_t&, uint64_t&, int&);
uint64_t stepen(uint64_t, int);
uint64_t greatestCommonDivisor(uint64_t, uint64_t);
uint64_t publicExponSearch(uint64_t, int);
uint64_t privateExponSearch(uint64_t, uint64_t);
void RSAKeyGeneration();
void RSACode();


void passwordCheñk();
int principleOfOperation();
int cryptoTypeSelect(int);

void inputStrToTxt();

void funkTypeName(int);
void funkPrinciple(int);

void encryptionStart(int, int);
void encryptionCheck(int, int);

void GronsfeldDecode(int);
void GronsfeldCode(int);