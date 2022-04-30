#include "randPrimeSearch.h"

//Random prime number generation function (Erastophene sieve)
void randPrimeSearch(uint64_t& first_prime, uint64_t& second_prime, int& memoryBit)
{
	srand(time(0));
	bool isNumber = false;
	string memoryBitStr = "";
	while ((isNumber == false) || (memoryBit < 3 || memoryBit > 14))
	{
		isNumber = false;
		cout << "Enter bit memory for prime numbers in range from 3 to 14 (recommended no more than 12(in 14 slow))" << endl << ": ";	//may 30 for prime but in encrypt don't work
		getline(cin, memoryBitStr);																										//max - 32
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
		isNumber = checkIfNotANumber(memoryBitStr);
		memoryBit = 0;
		if (isNumber == false)
		{
			continue;
		}
		else
		{
			for (int i = 0; memoryBitStr[i] != '\0'; i++)  //convert from string to uint64_t
			{
				char askii = '0';
				for (int j = 48; j < 58; j++)
				{
					askii = j;
					if (memoryBitStr[i] == askii)
					{
						memoryBit = (memoryBit * 10) + (memoryBitStr[i] - 48);
						break;
					}
				}
			}
		}
	}
#ifndef Clear
	system("CLS");
#endif
	cout << "Wait, there are complex calculations going on..." << endl;

	uint64_t mayPrimeMin = stepen(2, memoryBit - 1) + 1;  //Calculating the maximum and minimum numbers in a given size value
	uint64_t mayPrimeMax = stepen(2, memoryBit);

	vector <int16_t> primeNumErast(mayPrimeMax, 0);
	vector <uint64_t> primeNum;

	for (uint64_t i = 2; i < mayPrimeMax; i++)
	{
		if (primeNumErast[i] == 0)
		{
			for (uint64_t j = i * i; ((i*i) < mayPrimeMax) && (j < mayPrimeMax); j = j + i)
			{
				primeNumErast[j] = 1;
			}
			if (i >= mayPrimeMin)
			{
				primeNum.push_back(i);
			}
		}
	}
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
	//Returning a random prime number from a range
	first_prime = primeNum[rand() % primeNum.size()];
	second_prime = primeNum[rand() % primeNum.size()];
	while (first_prime == second_prime)
	{
		second_prime = primeNum[rand() % primeNum.size()];
	}
}