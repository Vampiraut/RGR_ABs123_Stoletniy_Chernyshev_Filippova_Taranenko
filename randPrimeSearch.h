#pragma once
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

void randPrimeSearch(uint64_t&, uint64_t&, int&);				//Random prime number generation function (Erastophene sieve)

bool checkIfNotANumber(string);									//The function of checking whether the entered string is a number
uint64_t stepen(uint64_t, int);									//8 byte unsigned int exponentiation function