#include "RSADecode.h"

//Decryption with RSA cipher
void RSADecode()
{
	string publicExponStr = "";
	string privateExponStr = "";
	string modulStr = "";
	string inputString = "";

	ifstream fout("Some_text.txt");
	getline(fout, publicExponStr, ' ');
	getline(fout, privateExponStr, ' ');
	getline(fout, modulStr);

	uint64_t publicExpon = 0;
	uint64_t privateExpon = 0;
	uint64_t modul = 0;
	for (int i = 0; publicExponStr[i] != '\0'; i++)
	{
		publicExpon = publicExpon * 10 + (publicExponStr[i] - 48);
	}
	for (int i = 0; privateExponStr[i] != '\0'; i++)
	{
		privateExpon = privateExpon * 10 + (privateExponStr[i] - 48);
	}
	for (int i = 0; modulStr[i] != '\0'; i++)
	{
		modul = modul * 10 + (modulStr[i] - 48);
	}

	ofstream fin("Str_aft_proc.txt");
	fin << publicExpon << " " << privateExpon << " " << modul << endl;
	funkPrinciple(2);
	funkTypeName(2);
	cout << "Decryption string: " << endl;
	uint64_t buferInt = 0;
	while (!fout.eof())
	{
		getline(fout, inputString);
		for (uint64_t i = 0; inputString[i] != '\0'; i++)
		{
			buferInt = 0;
			for (; inputString[i] != 'Î'; i++)
			{
				buferInt = buferInt * 10 + (inputString[i] - 48);
			}
			uint64_t smenaASKII = 1;
			for (uint64_t j = 0; j < privateExpon; j++)
			{
				smenaASKII = (smenaASKII * buferInt) % modul;
			}
			char ASKIICod = smenaASKII;
			fin << ASKIICod;
			cout << ASKIICod;
		}
		if (!fout.eof())
		{
			cout << '\n';
			fin << '\n';
		}
	}
	fout.close();
	fin.close();
	cout << endl << endl;
#ifndef Clear
	system("PAUSE");
	system("CLS");
#endif
}