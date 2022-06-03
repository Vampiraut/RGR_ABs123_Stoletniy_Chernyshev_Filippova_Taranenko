#include "Encryption.h"

//Encryption with the Gronsfeld cipher
void GronsfeldCode(int codeCheck)
{
	if (codeCheck != 1)
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

		string someKey = "";
		cout << "Enter the KEY" << endl << ":";
		getline(cin, someKey);

		bool isNumber = checkIfNotANumber(someKey);
		while (isNumber != true)
		{
#ifndef Clear
			system("CLS");
#endif
#ifdef Clear
			cout << endl;
#endif
			cout << "Wrong KEY!" << endl << "Enter the KEY" << endl << ":";
			getline(cin, someKey);
			isNumber = checkIfNotANumber(someKey);
		}

		ofstream fin("Some_text.txt");	 //очищает файл Some_text.txt куда сначала записывается ключ, а затем исходный текст
		ifstream promegCopy("bufer.txt");//читает файл с копией нашего текста
		fin << someKey << endl;
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
	string inputString = "";                                         //input string
	string outputString = "";										//output string
	bool isEnd = false;                                                   //cheсk-flag for continue
	string key = "";

	ifstream fout1("Some_text.txt"); //читает файл с ключом и нашим текстом
	getline(fout1, key);
	ofstream fin2("Str_aft_proc.txt");
	fin2 << key << endl;
#ifndef Clear
	system("CLS");
#endif
	funkPrinciple(1);
	funkTypeName(1);
	if (codeCheck == 1)
	{
		cout << "Your KEY: " << key << endl;
	}
	cout << "Encrypted string: " << endl;

	int p = -1;
	while (!fout1.eof())
	{
		inputString = "";
		outputString = "";
		getline(fout1, inputString);

		for (int i = 0; inputString[i] != '\0'; i++)                //input string check
		{
			if (inputString[i] == ' ')
			{
				outputString += inputString[i];
				continue;
			}
			p++;
			int smehenie = 0;
			for (int k = 48; k < 58; k++)
			{
				if (key[p] == '\0')
				{
					p = 0;
				}
				char ASKIIkey = k;
				if (ASKIIkey == key[p])
				{
					smehenie = k - 48;
				}
			}
			isEnd = false;												//set check-flag to false
			for (int j = 33; j < 127; j++)								//ASKII 33 -> 126 check in input string
			{
				char ASCIICod = j;											//int-dek to ASKII-symbol															
				if (inputString[i] == ASCIICod)								//comparison of the symbol of the input string and the ASKII character
				{
					int smena = j + smehenie;									//shift by ASKII table (smehenie (default = 5))
					for (int h = 127; h < (127 + smehenie); h++)				//exclusion of unreadable characters from the ASKII table module
					{
						if (smena == h)
						{
							smena = smena + 65;
						}
					}
					char ASCIICod_smena = smena;                                //changing a character and saving it to the output array
					outputString += ASCIICod_smena;
					isEnd = true;													//set check-flag to true
					break;														//break the cycle
				}
			}
			if (isEnd == true)											//check check-flag (if true -> do not check symbols further)
			{
				continue;
			}

			for (int j = 192; j < 256; j++)								//ASKII 192 -> 255 check in input string
			{
				char ASCIICod = j;											//int-dek to ASKII-symbol
				if (inputString[i] == ASCIICod)								//comparison of the symbol of the input string and the ASKII character
				{
					int smena = j + smehenie;									//shift by ASKII table (smehenie (defalt = 5))
					for (int h = 256; h < (256 + smehenie); h++)				//exclusion of unreadable characters from the ASKII table module
					{
						if (smena == h)
						{
							smena = smena - 256 + 33;
						}
					}
					char ASCIICod_smena = smena;								//changing a character and saving it to the output array
					outputString += ASCIICod_smena;
					isEnd = true;													//set check-flag to true
					break;														//break the cycle
				}
			}
			if (isEnd == true)											//check check-flag (if true -> do not check symbols further)
			{
				continue;
			}
			outputString += inputString[i];								//if there is no ASKII in the range -> copy them to the output array without modification
		}
		fin2 << outputString;											//output of encrypted string
		cout << outputString << endl;
		if (!fout1.eof())
		{
			fin2 << endl;
		}
	}
	fout1.close();
	fin2.close();
	cout << endl;
#ifndef Clear
	system("PAUSE");
	system("CLS");
#endif
}

//Encryption with RSA cipher
void RSACode()
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
	funkPrinciple(1);
	funkTypeName(2);
	cout << "Encryption string: " << endl;

	while (!fout.eof())
	{
		getline(fout, inputString);
		for (uint64_t i = 0; inputString[i] != '\0'; i++)
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

//Encryption with Morse cipher
void MorseCode()
{
	string inputString = "";                                         //input string
	string outputString = "";										//output string
	ifstream fout1("Some_text.txt"); //читает файл с ключом и нашим текстом
	ofstream fin2("Str_aft_proc.txt");
	map <char, string> alfForCode = { {'A',"._"}, {'B',"_..."}, {'C',"_._."}, {'D',"_.."}, {'E',"."}, {'F',".._."}, {'G',"__."}, {'H',"...."}, {'I',".."}, {'J',".___"},{'K',"_._"}, {'L',"._.."}, {'M',"__"},
									  {'N',"_."}, {'O',"___"}, {'P',".__."}, {'Q',"__._"}, {'R',"._."}, {'S',"..."}, {'T',"_"}, {'U',".._"}, {'V',"..._"}, {'W',".__"}, {'X',"_.._"}, {'Y',"_.__"}, {'Z',"__.."},
									  {'a',"._"}, {'b',"_..."}, {'c',"_._."}, {'d',"_.."}, {'e',"."}, {'f',".._."}, {'g',"__."}, {'h',"...."}, {'i',".."}, {'j',".___"},{'k',"_._"}, {'l',"._.."}, {'m',"__"},
									  {'n',"_."}, {'o',"___"}, {'p',".__."}, {'q',"__._"}, {'r',"._."}, {'s',"..."}, {'t',"_"}, {'u',".._"}, {'v',"..._"}, {'w',".__"}, {'x',"_.._"}, {'y',"_.__"}, {'z',"__.."},
									  {'1',".____"}, {'2',"..___"}, {'3',"...__"}, {'4',"...._"}, {'5',"....."}, {'6',"_...."}, {'7',"__..."}, {'8',"___.."}, {'9',"____."}, {'0',"_____"}, {' ',"______"} };

	funkPrinciple(1);
	funkTypeName(3);
	cout << "Encrypted string: " << endl;
	while (!fout1.eof())
	{
		inputString = "";
		outputString = "";
		getline(fout1, inputString);
		for (int i = 0; i < inputString.length(); i++)
		{
			outputString = outputString + alfForCode[inputString[i]] + ' ';
		}
		fin2 << outputString;
		cout << outputString << endl;
		if (!fout1.eof())
		{
			fin2 << endl;
		}
	}
	fout1.close();
	fin2.close();
	cout << endl;
#ifndef Clear
	system("PAUSE");
	system("CLS");
#endif
}

//Encryption with Vernam cipher
void VernamCode()
{
	srand(0);

	ifstream fout("Some_text.txt");
	ofstream fin("Str_aft_proc.txt");

	funkPrinciple(1);
	funkTypeName(4);

	cout << "Encrypted string:" << endl;
	while (!fout.eof())
	{
		string oStr = "";
		getline(fout, oStr);

		string key = "";
		int i = 0;
		for (i = 0; oStr[i] != '\0'; i++)
		{
			key += (char)(rand() % 127);
		}

		string shStr = "";
		for (i = 0; oStr[i] != '\0'; i++)
		{
			shStr += (oStr[i] ^ key[i]);
		}

		fin << shStr;
		cout << shStr << endl;
		if (!fout.eof())
		{
			fin << endl;
		}
	}
	fout.close();
	fin.close();
	cout << endl;
#ifndef Clear
	system("PAUSE");
	system("CLS");
#endif
}

//Encryption with Atbash cipher
void AtbashCode(int code) {
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
	bool isEnd = false;                                                   //cheсk-flag for continue

	ifstream fout1("Some_text.txt"); //читает файл с ключом и нашим текстом
	ofstream fin2("Str_aft_proc.txt");
#ifndef Clear
	system("CLS");
#endif
	funkPrinciple(1);
	funkTypeName(7);
	cout << "Encrypted string: " << endl;

	getline(fout1, inputString);
	const char seng[27] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	const char beng[27] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	const char srus[34] = { 'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'э', 'ю', 'я' };
	const char brus[34] = { 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Э', 'Ю', 'Я' };
	char c;
	bool flag;
	for (int i = 0; inputString[i] != '\0'; i++) {
		flag = false;
		for (int j = 0; j < 26; j++) {
			if (inputString[i] == beng[j]) {
				c = beng[25 - j];
				flag = true;
				outputString += c;
			}
			if (inputString[i] == seng[j]) {
				c = seng[25 - j];
				flag = true;
				outputString += c;
			}
		}
		for (int j = 0; j < 33; j++) {
			if (inputString[i] == brus[j]) {
				c = brus[32 - j];
				flag = true;
				outputString += c;
			}
			if (inputString[i] == srus[j]) {
				c = srus[32 - j];
				flag = true;
				outputString += c;
			}
		}
		if (flag == false) {
			outputString += inputString[i];
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

//Encryption with Simple Table Permutation
void SimpleTablePermutationCode(int code) {
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
		cout << "Enter the KEY1" << endl << ":";
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
			cout << "Wrong KEY!" << endl << "Enter the KEY1" << endl << ":";
			getline(cin, someKey1);
			isNumber = checkIfNotANumber(someKey1);
		}

		cout << "Enter the KEY2" << endl << ":";
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
			cout << "Wrong KEY!" << endl << "Enter the KEY2" << endl << ":";
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
	funkTypeName(8);
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

//Encryption with Vigener cipher
void VigenerCode(vector<vector<char>> vigenerTable, int codeCheck)
{
	vector<char> alfForCod = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
							   'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
							   '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
	if (codeCheck != 1)
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

		string someKey = "";
		cout << "Enter code word" << endl << ": ";
		getline(cin, someKey);

		ofstream fin("Some_text.txt");	 //очищает файл Some_text.txt куда сначала записывается ключ, а затем исходный текст
		ifstream promegCopy("bufer.txt");//читает файл с копией нашего текста
		fin << someKey << endl;
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

	string inputString = "";                                         //input string
	string outputString = "";										//output string
	string key = "";

	ifstream fout1("Some_text.txt"); //читает файл с ключом и нашим текстом
	getline(fout1, key);
	ofstream fin2("Str_aft_proc.txt");
	fin2 << key << endl;
#ifndef Clear
	system("CLS");
#endif
	funkPrinciple(1);
	funkTypeName(10);

	if (codeCheck == 1)
	{
		cout << "Your KEY: " << key << endl;
	}
	cout << "Encrypted string: " << endl;

	int p = 0;
	while (!fout1.eof())
	{
		inputString = "";
		outputString = "";
		getline(fout1, inputString);

		for (int i = 0; i < inputString.size(); i++)
		{
			char codInpStr = inputString[i];
			if (codInpStr == ' ')
			{
				outputString += codInpStr;
				continue;
			}

			char codKey = key[p];
			p++;
			if (p >= key.size())
			{
				p = 0;
			}

			int y = 0;
			for (int k = 0; k < alfForCod.size(); k++)
			{
				if (codKey == alfForCod[k])
				{
					y = k;
				}
			}

			int x = 0;
			for (int k = 0; k < alfForCod.size(); k++)
			{
				if (codInpStr == alfForCod[k])
				{
					x = k;
				}
			}
			outputString += vigenerTable[y][x];
		}
		fin2 << outputString;											//output of encrypted string
		cout << outputString << endl;
		if (!fout1.eof())
		{
			fin2 << endl;
		}
	}
	fout1.close();
	fin2.close();
	cout << endl;
#ifndef Clear
	system("PAUSE");
	system("CLS");
#endif
}

//Encryption with Binary cipher
void BinaryCode()
{
	ifstream fout("Some_text.txt");
	ofstream fin("Str_aft_proc.txt");
	string inputString = "";
	string outputString = "";

	funkPrinciple(1);
	funkTypeName(11);

	cout << "Encrypted string:" << endl;
	while (!fout.eof())
	{
		inputString = "";
		outputString = "";
		getline(fout, inputString);
		int binCod = 0;
		int mnog = 1;

		for (int i = 0; i < inputString.length(); i++)
		{
			binCod = 0;
			mnog = 1;
			int simbCod = (int)inputString[i];
			while (simbCod > 0)
			{
				binCod = binCod + ((simbCod % 2) * mnog);
				mnog *= 10;
				simbCod /= 2;
			}
			outputString += to_string(binCod);
			outputString += ' ';
		}
		fin << outputString;											//output of encrypted string
		cout << outputString << endl;
		if (!fout.eof())
		{
			fin << endl;
		}
	}
	fout.close();
	fin.close();
	cout << endl;
#ifndef Clear
	system("PAUSE");
	system("CLS");
#endif
}