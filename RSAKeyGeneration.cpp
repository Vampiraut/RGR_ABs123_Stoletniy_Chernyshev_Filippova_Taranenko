#include "Header.h"

void RSAKeyGeneration()
{
	uint64_t first_prime = 0, señond_prime = 0, modul = 0, eiler = 0, publicExpon = 0, privateExpon = 0;
	int memoryBit = 0;

	randPrimeSearch(first_prime, señond_prime, memoryBit);

	modul = first_prime * señond_prime;
	eiler = (first_prime - 1) * (señond_prime - 1);
#ifdef DEBUGRSA
	cout << "First prime number: " << first_prime << endl << "Second prime number: " << señond_prime << endl;
	cout << "Module (p*q): " << modul << endl;
	cout << "Eiler funktion: " << eiler << endl;
#endif
	publicExpon = publicExponSearch(eiler, memoryBit);
	cout << "PUBLIC KEY: {" << publicExpon << "," << modul << "}" << endl;
	while (((privateExpon * publicExpon) % eiler != 1) || privateExpon == 0)
	{
		privateExpon = privateExponSearch(publicExpon, eiler);
	}
	cout << "PRIVATE KEY: {" << privateExpon << "," << modul << "}" << endl;

	ofstream fin("Some_text.txt", ios_base::out | ios_base::app);
	fin << endl << publicExpon << " " << modul;
	fin << endl << privateExpon << " " << modul;
	fin.close();
	//[PUBLIC KEY: {publicExpon , modul}
	//[PRIVATE KEY: {privateExpon , modul}
}