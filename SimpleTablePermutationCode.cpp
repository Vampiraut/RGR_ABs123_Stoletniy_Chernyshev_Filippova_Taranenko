#include "SimpleTablePermutationCode.h"

void SimpleTablePermutationCode(int code){
	if (code != 1)
	{
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

		string someKey1 = "";
		string someKey2 = "";
		cout << "Enter the KEYS" << endl << ":";
		cout << "KEY1:";
		getline(cin, someKey1);
		cout << endl;

		bool isNumber = checkIfNotANumber(someKey1);
		while (isNumber != true)
		{
#ifndef Clear
			system("CLS");
#endif
#ifdef Clear
			cout << endl;
#endif
			cout << "Wrong KEY!" << endl << "Enter the KEY" << endl << ":";
			getline(cin, someKey1);
			isNumber = checkIfNotANumber(someKey1);
		}

		cout << "KEY2:";
		getline(cin, someKey2);

		isNumber = checkIfNotANumber(someKey2);
		while (isNumber != true)
		{
#ifndef Clear
			system("CLS");
#endif
#ifdef Clear
			cout << endl;
#endif
			cout << "Wrong KEY!" << endl << "Enter the KEY" << endl << ":";
			getline(cin, someKey2);
			isNumber = checkIfNotANumber(someKey2);
		}

		ofstream fin("Some_text.txt");	 //очищает файл Some_text.txt куда сначала записывается ключ, а затем исходный текст
		ifstream promegCopy("bufer.txt");//читает файл с копией нашего текста
		fin << someKey1 << endl;
		fin << someKey2 << endl;
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
	string inputString = "";
	string outputString = "";
	bool isEnd = false;                                                   //cheсk-flag for continue
	string Sstrings = "";
	string Scolumns = "";

	ifstream fout1("Some_text.txt"); //читает файл с ключом и нашим текстом
	getline(fout1, Sstrings);
	getline(fout1, Scolumns);
	ofstream fin2("Str_aft_proc.txt");
#ifndef Clear
	system("CLS");
#endif
	funkPrinciple(1);
	funkTypeName(10);
	int columns = stoi(Scolumns);
	int strings = stoi(Sstrings);
	getline(fout1, inputString);
	int i, j, rez;
	for (i = 0; inputString[i] != '\0'; i++)
	{
		if (inputString[i] == ' ')
		{
			inputString.erase(i, 1);
		}
	}
	char** a = new char* [strings];
	for (int i = 0; i < strings; ++i)
		a[i] = new char[columns];
	rez = 0;
	for (i = 0; i < columns; i++)
	{
		for (j = 0; j < strings; j++)
		{
			a[j][i] = inputString[rez];
			rez++;
		}
	}
	rez = -1;
	for (i = 0; i < strings; i++)
	{
		for (j = 0; j < columns; j++)
		{
			rez++;
			if (rez == strings)
			{
				rez = 0;
				outputString += " ";
			}
			outputString += a[i][j];
		}
	}
	cout << outputString << endl;
	fin2 << outputString;
	fout1.close();
	fin2.close();
	cout << endl;
#ifndef Clear
	system("PAUSE");
	system("CLS");
#endif
}