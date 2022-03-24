#include "Header.h"

void RSACode()
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
	//cout << publicExpon << "!\n" << privateExpon << "!\n" << modul << "!\n";
	while (!fout.eof())
	{
		getline(fout, bufer);
		inputString = inputString + bufer;
		if (!fout.eof())
		{
			inputString = inputString + '\n';
		}
	}
	fout.close();

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
	//cout << publicExpon << "!\n" << privateExpon << "!\n" << modul << "!\n";

	ofstream fin("Str_aft_proc.txt");
	fin << publicExpon << " " << privateExpon << " " << modul << endl;
	//string outputString = "";
	for (int i = 0; inputString[i] != '\0'; i++)
	{
		uint64_t charASKII = inputString[i];
		uint64_t smenaASKII = 1;
		for (int j = 0; j < publicExpon; j++)
		{
			smenaASKII = (smenaASKII * charASKII) % modul;
		}
		fin << smenaASKII << ' ';
	}
	fin.close();
}

/*
for (long int i = 0; i < msg.length(); i++)
{
	encryptedText[i] = encrypt(msg[i], e, n);
}

std::cout << "\nTHE ENCRYPTED MESSAGE IS:" << std::endl;

for (long int i = 0; i < msg.length(); i++)
{
	printf("%c", (char)encryptedText[i]);
}


long int encrypt(long int i, long int e, long int n) //i - элемент строки, e - открытая экспонета, n - произведение простых(модуль)
{
	long int current, result;

	current = i - 97;
	result = 1;

	for (long int j = 0; j < e; j++)
	{
		result = result * current;
		result = result % n;
	}

	return result;
}*/