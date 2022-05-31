#include "SimpleTablePermutationDecode.h"

void SimpleTablePermutationDecode(int code){
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

		ofstream fin("Some_text.txt");	 //очищает файл Some_text.txt куда сначала записывается ключ, а затем исходный текст
		ifstream promegCopy("bufer.txt");//читает файл с копией нашего текста
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
	bool isEnd = false;
	ifstream fout1("Some_text.txt");
	ofstream fin2("Str_aft_proc.txt");
#ifndef Clear
	system("CLS");
#endif
	funkPrinciple(2);
	funkTypeName(8);
	getline(fout1, inputString);

	int strings = 1;
	int i, j, rez;
	for (i = 0; i < inputString.length(); i++)
	{
		if (inputString[i] == ' ')
		{
			strings++;
			inputString.erase(i, 1);
		}
	}
	int columns;
	columns = inputString.length() / strings;
	char** a = new char* [strings];
	for (int i = 0; i < strings; ++i)
		a[i] = new char[columns];
	rez = 0;
	for (i = 0; i < columns; i++)
	{
		for (j = 0; j < strings; j++)
		{
			a[i][j] = inputString[rez];
			rez++;
		}
	}
	rez = -1;
	for (i = 0; i < strings; i++)
	{
		for (j = 0; j < columns; j++)
		{
			rez++;
			if (rez == columns) {
				rez = 0;
				outputString+=" ";
			}
			outputString+=a[j][i];
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