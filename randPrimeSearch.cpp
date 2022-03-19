#include "Header.h"

//Prime number generator
#ifdef FORTWOENTERS
uint64_t randPrimeSearch(int num)
#endif

#ifndef FORTWOENTERS
void randPrimeSearch(uint64_t& first_prime, uint64_t& second_prime)
#endif
{
	bool isNumber = false;
	string memoryBitStr = "";
	int memoryBit = 0;
	while (isNumber == false)
	{
		memoryBit = 0;
		isNumber = true;

#ifndef FORTWOENTERS
		cout << "Enter bit memory for prime numbers(in range from 5 to 32 (recommended no more than 24)" << endl << ":";
#endif

#ifdef FORTWOENTERS
		cout << "Enter bit memory for ";
		if (num == 1)
		{
			cout << "first prime number(in range from 5 to 32 (recommended no more than 24)" << endl << ":";
		}
		else if (num == 2)
		{
			cout << "second prime number(in range from 5 to 32 (recommended no more than 24)" << endl << ":";
		}
#endif

		getline(cin, memoryBitStr);
		system("CLS");

		if (memoryBitStr == "")   //chek for empety string
		{
			cout << "Wrong bit memory!" << endl;
			isNumber = false;
			continue;
		}
		for (int i = 0; memoryBitStr[i] != '\0'; i++)  //chek for not a number
		{
			char askii = 0;
			for (int j = 48; j < 58; j++)
			{
				askii = j;
				if (memoryBitStr[i] != askii && j == 57)
				{
					cout << "Wrong bit memory!" << endl;
					isNumber = false;
					break;
				}
				else if (memoryBitStr[i] == askii)
				{
					memoryBit = memoryBit * 10 + (j - 48);
					break;
				}
			}
			if (isNumber == false)
			{
				break;
			}
		}
		if ((isNumber == true) && (memoryBit < 5 || memoryBit > 32))
		{
			cout << "Wrong bit memory!" << endl;
			isNumber = false;
		}
	}

	system("CLS");
	cout << "Wait, there are complex calculations going on...";

	uint64_t mayPrimeMin = stepen(2, memoryBit - 1) + 1;  //Calculating the maximum and minimum numbers in a given size value
	uint64_t mayPrimeMax = stepen(2, memoryBit);

	bool isPrime = true;
	vector <uint64_t> prime;

	for (uint64_t i = mayPrimeMin; i < mayPrimeMax; i = i + 2)  //Checking numbers from a range for simplicity
	{
		isPrime = true;
		for (uint64_t j = 2; j <= ((uint64_t)sqrt((uint64_t)i)); j++)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime == true)
		{
			prime.push_back(i);
		}
	}
	system("CLS");

	//Returning a random prime number from a range
#ifdef FORTWOENTERS
	if (num == 1)
	{
		uint64_t first_prime = prime[rand() % prime.size()];
		return first_prime;
	}
	else if (num == 2)
	{
		uint64_t second_prime = prime[rand() % prime.size()];
		return second_prime;
	}
#endif

#ifndef FORTWOENTERS
	first_prime = prime[rand() % prime.size()];
	second_prime = prime[rand() % prime.size()];
	while (first_prime == second_prime)
	{
		second_prime = prime[rand() % prime.size()];
	}
#endif
}
