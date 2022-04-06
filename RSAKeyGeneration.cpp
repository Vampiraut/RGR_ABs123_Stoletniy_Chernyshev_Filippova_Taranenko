#include "Header.h"

void RSAKeyGeneration(int mayDecode)
{
	uint64_t first_prime = 0, seсond_prime = 0, modul = 0, eiler = 0, publicExpon = 0, privateExpon = 0;
	string publicExponStr = "", privateExponStr = "", modulStr = "";
	int memoryBit = 0;
	if (mayDecode != 1)
	{
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

		uint64_t k = 1;
		while ((privateExpon * publicExpon) % eiler != 1)
		{
			privateExpon = privateExponSearch(publicExpon, eiler, k);
		}
		cout << "PRIVATE KEY: {" << privateExpon << "," << modul << "}" << endl;
	}
	else if (mayDecode == 1)
	{
		cout << "Enter public expon" << endl << ": ";
		getline(cin, publicExponStr);
		cout << "Enter private expon" << endl << ": ";
		getline(cin, privateExponStr);
		cout << "Enter module" << endl << ": ";
		getline(cin, modulStr);
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
		cout << "PUBLIC KEY: {" << publicExponStr << "," << modulStr << "}" << endl;
		cout << "PRIVATE KEY: {" << privateExponStr << "," << modulStr << "}" << endl;
	}
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
			promeg << endl;
		}
	}
	fout.close();
	promeg.close();

	ofstream fin("Some_text.txt");	 //очищает файл Some_text.txt куда сначала записывается ключ, а затем исходный текст
	ifstream promegCopy("bufer.txt");//читает файл с копией нашего текста

	if (mayDecode != 1)
	{
		fin << publicExpon << " " << privateExpon << " " << modul << endl;
	}
	else if (mayDecode == 1)
	{
		fin << publicExponStr << " " << privateExponStr << " " << modulStr << endl;
	}

	while (!promegCopy.eof())
	{
		getline(promegCopy, bufer);
		fin << bufer;
		if (!promegCopy.eof())
		{
			fin << endl;
		}
	}
	fin.close();
	promegCopy.close();
	cout << endl;
#ifndef Clear
	system("PAUSE");
	system("CLS");
#endif
}