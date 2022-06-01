#include "Decryption.h"

//Decryption with the Gronsfeld cipher
void GronsfeldDecode(int codeCheck)
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
	funkPrinciple(2);
	funkTypeName(1);
	if (codeCheck == 1)
	{
		cout << "Your KEY: " << key << endl;
	}
	cout << "Decryption string: " << endl;

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
					int smena = j - smehenie;									//shift by ASKII table (smehenie (default = 5))
					for (int h = 33 - smehenie; h < 33; h++)					//exclusion of unreadable characters from the ASKII table module
					{
						if (smena == h)
						{
							smena = smena + 256 - 33;
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
					int smena = j - smehenie;									//shift by ASKII table (smehenie (default = 5))
					for (int h = 192 - smehenie; h < 192; h++)					//exclusion of unreadable characters from the ASKII table module
					{
						if (smena == h)
						{
							smena = smena - 65;
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
			for (; inputString[i] != 'О'; i++)
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

//Decryption with Morse cipher
void MorseDecode()
{
	string inputString = "";                                         //input string
	string outputString = "";										//output string
	ifstream fout1("Some_text.txt"); //читает файл с ключом и нашим текстом
	ofstream fin2("Str_aft_proc.txt");
	map <string, char> alfForDecode = { {"._",'A'}, {"_...",'B'}, {"_._.",'C'}, {"_..",'D'}, {".",'E'}, {".._.",'F'}, {"__.",'G'}, {"....",'H'}, {"..",'I'}, {".___",'J'},{"_._",'K'}, {"._..",'L'}, {"__",'M'},
										{"_.",'N'}, {"___",'O'}, {".__.",'P'}, {"__._",'Q'}, {"._.",'R'}, {"...",'S'}, {"_",'T'}, {".._",'U'}, {"..._",'V'}, {".__",'W'}, {"_.._",'X'}, {"_.__",'Y'}, {"__..",'Z'},
										{".____",'1'}, {"..___",'2'}, {"...__",'3'}, {"...._",'4'}, {".....",'5'}, {"_....",'6'}, {"__...",'7'}, {"___..",'8'}, {"____.",'9'}, {"_____",'0'}, {"______",' '} };

	funkPrinciple(2);
	funkTypeName(3);
	cout << "Decrypted string: " << endl;
	while (!fout1.eof())
	{
		inputString = "";
		outputString = "";
		getline(fout1, inputString);
		for (int i = 0; i < inputString.length(); i++)
		{
			string dotTirWord = "";
			for (int j = i; inputString[j] != ' '; j++)
			{
				dotTirWord += inputString[j];
				i = j;
			}
			i++;
			outputString += alfForDecode[dotTirWord];
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

//Decryption with Vernam cipher
void VernamDecode()
{
	srand(0);

	ifstream fout("Some_text.txt");
	ofstream fin("Str_aft_proc.txt");

	funkPrinciple(2);
	funkTypeName(4);

	cout << "Decrypted string:" << endl;
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

//Decryption with Atbash cipher
void AtbashDecode(int code) {
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
	funkPrinciple(2);
	funkTypeName(7);
	cout << "Decryption string: " << endl;

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

//Decryption with Simple Table Permutation
void SimpleTablePermutationDecode(int code) {
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
				outputString += " ";
			}
			outputString += a[j][i];
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

//Decryption with Vigener cipher
void VigenerDecode(vector<vector<char>> vigenerTable, int codeCheck)
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
	funkPrinciple(2);
	funkTypeName(10);

	if (codeCheck == 1)
	{
		cout << "Your KEY: " << key << endl;
	}
	cout << "Decrypted string: " << endl;

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
			for (int k = 0; k < vigenerTable[y].size(); k++)
			{
				if (codInpStr == vigenerTable[y][k])
				{
					x = k;
				}
			}
			outputString += alfForCod[x];
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