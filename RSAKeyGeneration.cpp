#include "Header.h"

void RSAKeyGeneration()
{
	uint64_t first_prime = 0, se�ond_prime = 0, modul = 0, eiler = 0, publicExpon = 0, privateExpon = 0;

#ifndef FORTWOENTERS
	randPrimeSearch(first_prime, se�ond_prime);
#endif
#ifdef FORTWOENTERS
	first_prime = randPrimeSearch(1);
	se�ond_prime = randPrimeSearch(2);
#endif

	modul = first_prime * se�ond_prime;
	eiler = (first_prime - 1) * (se�ond_prime - 1);
#ifdef DEBUGRSA
	cout << "First prime number: " << first_prime << endl << "Second prime number: " << se�ond_prime << endl;
	cout << "Module (p*q): " << modul << endl;
	cout << "Eiler funktion: " << eiler << endl;
#endif
	publicExpon = publicExponSearch(eiler);
	cout << "PUBLIC KEY: {" << publicExpon << "," << modul << "}" << endl;
	privateExpon = privateExponSearch(publicExpon, eiler);
	cout << "PRIVATE KEY: {" << privateExpon << "," << modul << "}" << endl;
}