#include "Header.h"

void RSAKeyGeneration()
{
	uint64_t first_prime = 0, seсond_prime = 0, modul = 0, eiler = 0, publicExpon = 0, privateExpon = 0;
	int memoryBit = 0;

	randPrimeSearch(first_prime, seсond_prime, memoryBit);

	modul = first_prime * seсond_prime;
	eiler = (first_prime - 1) * (seсond_prime - 1);
#ifdef DEBUGRSA
	cout << "First prime number: " << first_prime << endl << "Second prime number: " << seсond_prime << endl;
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

	//[PUBLIC KEY: {publicExpon , modul}
	//[PRIVATE KEY: {privateExpon , modul}

	string bufer = "";
	ifstream fout("Some_text.txt");//читает файл с нашим текстом
	ofstream promeg("Bufer.txt");  //очищает файл bufer.txt и копирует туда наш текст
	while (!fout.eof())
	{
		getline(fout, bufer);
		promeg << bufer;
		if (!fout.eof())
		{
			promeg << '\n';
		}
	}
	fout.close();
	promeg.close();

	ofstream fin("Some_text.txt");	 //очищает файл Some_text.txt куда сначала записывается ключ, а затем исходный текст
	ifstream promegCopy("bufer.txt");//читает файл с копией нашего текста
	fin << publicExpon << " " << privateExpon << " " << modul << endl;
	while (!promegCopy.eof())
	{
		getline(promegCopy, bufer);
		fin << bufer;
		if (!promegCopy.eof())
		{
			fin << '\n';
		}
	}
	fin.close();
	promegCopy.close();
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
}