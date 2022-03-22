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
/* The macro is necessary to change the type of bit value input
(if FORTWOENTERS exists, then the bit size for each prime number will be asked,
if not, a one - time request and two primes will be generated of the same bit size) */
#define FORTWOENTERS1
#define DEBUGRSA


using namespace std;

//RSA encryption components
#ifdef FORTWOENTERS
uint64_t randPrimeSearch(int);
#endif
#ifndef FORTWOENTERS
void randPrimeSearch(uint64_t&, uint64_t&);
#endif
uint64_t stepen(uint64_t, int);
uint64_t greatestCommonDivisor(uint64_t, uint64_t);
uint64_t publicExponSearch(uint64_t);
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

void CaesarDecode();
void CaesarCode();
void GronsfeldDecode();
void GronsfeldCode();