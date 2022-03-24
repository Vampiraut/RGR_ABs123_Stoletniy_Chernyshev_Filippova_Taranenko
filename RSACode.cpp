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

	funkPrinciple(1);
	funkTypeName(5);
	ofstream fin("Str_aft_proc.txt");
	fin << publicExpon << " " << privateExpon << " " << modul << endl;
	cout << "Encryption string: " << endl;
	for (int i = 0; inputString[i] != '\0'; i++)
	{
		uint64_t charASKII = inputString[i];
		uint64_t smenaASKII = 1;
		for (uint64_t j = 0; j < publicExpon; j++)
		{
			smenaASKII = (smenaASKII * charASKII) % modul;
		}
		fin << smenaASKII << 'О';
		cout << smenaASKII << 'О';
	}
	/*Можно реализовать следующим образом: в начале полученное число smenaASKII делится на 256 нацело (получим некоторое число Y)
	и из этого же числа получаем остаток от деления на 256 (некоторое число X),
	тем самым мы можем получить некоторый код от 0 до 256 для X и закодировать его по АСКИИ. Для Y мы можем получить число в пределах 0<Y<256 или больше.
	Если больше => повторяем операцию пока Y не станет в пределах 0<Y<256, на каждом новом шаге получая новые коды Y1,Y2 ... Yn.
	Получив конечные значения для Yn ... Y2,Y1,Y записываем их таким образом(переведя их по АСКИИ: (n+1)Yn ... Y2,Y1,Y,X
	Полученная последовательность букв будет кодировать один исходный символ в исходном сообщении.
	Декодинг происходит обратным образом. Считывая первый символ программа должна понять, сколько символов за ней надо взять и перемножить.
	Добустим, раскодировав сообщение из АСКИИ: 3678*/
	fin.close();
	cout << endl;
#ifndef Clear
	system("PAUSE");
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
}