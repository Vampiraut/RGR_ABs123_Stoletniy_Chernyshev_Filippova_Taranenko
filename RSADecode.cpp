#include "Header.h"

void RSADecode()
{
	string publicExponStr = "";
	string privateExponStr = "";
	string modulStr = "";
	string bufer = "";
	string inputString = "";
	ifstream fout("Some_text.txt"); //читает файл с ключом и нашим текстом
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
	uint64_t buferInt = 0;
	while (!fout.eof())
	{
		buferInt = 0;
		getline(fout, bufer, ' ');
		for (int i = 0; bufer[i] != '\0'; i++)
		{
			buferInt = buferInt * 10 + (bufer[i] - 48);
		}

		uint64_t smenaASKII = 1;
		for (int j = 0; j < privateExpon; j++)
		{
			smenaASKII = (smenaASKII * buferInt) % modul;
		}
		char ASKIICod = smenaASKII;
		fin << ASKIICod;
	}
	fout.close();
	fin.close();
}