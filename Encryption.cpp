#include "Encryption.h"
#include "HillComp.h"

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
					int smena = j + smehenie;									//shift by ASKII table
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
					int smena = j + smehenie;									//shift by ASKII table
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
			fin << smenaASKII << 'O';
			cout << smenaASKII << 'O';
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
			key += (char)(32 + rand() % (126 - 32 + 1));
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

//Encryption with ElGamal cipher
void ElGamalCode(){
	int p = 997;
	int g = 840;
	int x = 581;

	ifstream fout("Some_text.txt");
	ofstream fin("Str_aft_proc.txt");

	funkPrinciple(1);
	funkTypeName(5);

	int y = deg(g, x, p);
	cout << "Encrypted string:" << endl;
	while (!fout.eof()){
		string shStr = "";
		string oStr = "";
		getline(fout, oStr);
		int m = 1;
		int i = 0;
		while (1){
			m = oStr[i];
			if (m == 0){ break; }
			int k = rand() % (p - 2) + 1; // 1 < k < (p-1)
			int a = deg(g, k, p);
			int b = mod(deg(y, k, p), m, p);
			shStr += to_string(a) + " " + to_string(b) + " ";
			i++;
		}
		fin << shStr;
		cout << shStr << endl;
		if (!fout.eof()){
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

//Encryption with Gibberish cipher
void GibberishCode(){
	map<char, char> alfavit{ { 'b', 'z' }, { 'c', 'x' }, { 'd', 'w' }, { 'f', 'v' }, { 'g', 't' }, { 'h', 's' }, { 'j', 'r' }, { 'k', 'q' }, { 'l', 'p' }, { 'm', 'n' },
	{ 'z', 'b' }, { 'x', 'c' }, { 'w', 'd' }, { 'v', 'f' }, { 't', 'g' }, { 's', 'h' }, { 'r', 'j' }, { 'q', 'k' }, { 'p', 'l' }, { 'n', 'm' },
	{ 'B', 'Z' }, { 'C', 'X' }, { 'D', 'W' }, { 'F', 'V' }, { 'G', 'T' }, { 'H', 'S' }, { 'J', 'R' }, { 'K', 'Q' }, { 'L', 'P' }, { 'M', 'N' },
	{ 'Z', 'B' }, { 'X', 'C' }, { 'W', 'D' }, { 'V', 'F' }, { 'T', 'G' }, { 'S', 'H' }, { 'R', 'J' }, { 'Q', 'K' }, { 'P', 'L' }, { 'N', 'M' },
	{ 'a', 'o' }, { 'e', 'u' }, { 'i', 'y' }, { 'o', 'a' }, { 'u', 'e' }, { 'y', 'i' },
	{ 'A', 'O' }, { 'E', 'U' }, { 'I', 'Y' }, { 'O', 'A' }, { 'U', 'E' }, { 'Y', 'I' } };


	ifstream fout("Some_text.txt");
	ofstream fin("Str_aft_proc.txt");


	funkPrinciple(1);
	funkTypeName(6);

	cout << "Encrypted string:" << endl;
	while (!fout.eof()){
		string oStr = "";
		getline(fout, oStr);

		string shStr = "";

		for (int i = 0; oStr[i] != '\0'; i++){
			if ((oStr[i] >= 'a' && oStr[i] <= 'z') || (oStr[i] >= 'A' && oStr[i] <= 'Z')){
				auto it = alfavit.find(oStr[i]);
				shStr += it->second;
			}
			else{
				shStr += oStr[i];
			}
		}

		fin << shStr;
		cout << shStr << endl;
		if (!fout.eof()){
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
	while (!fout1.eof()) {
		inputString = "";
		outputString = "";
		getline(fout1, inputString);
		vector<char> seng = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
		vector<char> beng = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
		char c;
		bool flag;
		for (int i = 0; inputString[i] != '\0'; i++) {
			flag = false;
			for (int j = 0; j < beng.size(); j++) {
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
			if (flag == false) {
				outputString += inputString[i];
			}
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
	funkTypeName(8);
	cout << "Encrypted string: " << endl;
	while (!fout1.eof()) {
		inputString = "";
		outputString = "";
		getline(fout1, inputString);

		int strings = 1;
		int i, j, rez, count;
		for (i = 0; i < inputString.length(); i++)
		{
			if (inputString[i] == ' ')
			{
				strings++;
				inputString.erase(i, 1);
			}
		}
		count = inputString.length();
		if (strings == 1) {
			outputString = inputString;
		}
		else {
			int columns = inputString.length() / strings;
			if (inputString.length() % strings != 0) {
				columns++;
			}
			int i, j, rez;
			char** a = new char* [strings];
			for (int i = 0; i < strings; ++i)
				a[i] = new char[columns];
			rez = 0;
			for (i = 0; i < strings; i++)
			{
				for (j = 0; j < columns; j++)
				{
					a[i][j] = '$';
					rez++;
				}
			}
			rez = 0;
			for (i = 0; i < columns; i++)
			{
				for (j = 0; j < strings; j++)
				{
					a[j][i] = ' ';
					rez++;
				}
			}
			rez = 0;
			for (i = 0; i < columns; i++)
			{
				for (j = 0; j < strings; j++)
				{
					a[j][i] = inputString[rez];
					if (rez == count) {
						break;
					}
					rez++;
				}
				if (rez == count) {
					break;
				}
			}
			rez = -1;
			for (i = 0; i < strings; i++)
			{
				for (j = 0; j < columns; j++)
				{
					if (a[i][j] != '$') {
						rez++;
						if (rez == strings)
						{
							rez = 0;
							outputString += " ";
						}
						outputString += a[i][j];
					}
				}
			}
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

//Encryption with Shamir cipher
void ShamirCode() {
		string publicp = "";
		string publicCa = "";
		string publicCb = "";
		string privateDa = "";
		string privateDb = "";
		string input = "";

		ifstream fout("Some_text.txt");
		getline(fout, publicp);
		getline(fout, publicCa);
		getline(fout, publicCb);
		getline(fout, privateDa);
		getline(fout, privateDb);

		int p = stoi(publicp);
		int Ca = stoi(publicCa);
		int Cb = stoi(publicCb);
		int Da = stoi(privateDa);
		int Db = stoi(privateDb);

		ofstream fin("Str_aft_proc.txt");
		fin << p << endl;
		fin << Ca << endl;
		fin << Cb << endl;
		fin << Da << endl;
		fin << Db << endl;
		funkPrinciple(1);
		funkTypeName(9);
		cout << "Encryption string: " << endl;

		while (!fout.eof())
		{
			getline(fout, input);
			for (int i = 0; input[i] != '\0'; i++)
			{
				int el = input[i];
				int shag;
				shag = shamir(el, Ca, p);
				shag = shamir(shag, Cb, p);
				fin << shag << ' ';
				cout << shag << ' ';
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

//Encryption with Hill cipher
void HillCode(int codeCheck)
{
	vector<char> alf;// = { 'А','Б','В','Г','Д','Е','Ё','Ж','З','И','Й','К','Л','М','Н','О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Щ','Ъ','Ы','Ь','Э','Ю','Я','.',',',' ','?' };

	for (int i = 32; i < 127; i++)
	{
		alf.push_back((char)i);
	}
	alf.push_back('№');
	alf.push_back((char)181);


	vector<int> codByAlfKey;
	vector<vector<int>> matrixKey;
	int g = 0;
	string someKey = "";
	int obrEl = 100;
	if (codeCheck != 1)
	{
		while (1)
		{
			codByAlfKey.clear();
			matrixKey.clear();
			someKey = "";
			for (int i = 0; i < 9; i++)
			{
				someKey += alf[rand() % alf.size()];
			}
			for (char i : someKey)
			{
				for (int j = 0; j < alf.size(); j++)
				{
					if (i == alf[j])
					{
						codByAlfKey.push_back(j);
					}
				}
			}
			for (int i = 0; i < (int)rint(sqrt(someKey.length())); i++)
			{
				vector<int> m;
				matrixKey.push_back(m);
			}
			g = 0;
			for (int i = 0; i < (int)rint(sqrt(someKey.length())); i++)
			{
				for (int j = 0; j < (int)rint(sqrt(someKey.length())); j++)
				{
					matrixKey[i].push_back(codByAlfKey[g++]);
				}
			}
			int detMatrixKey = determCalk(matrixKey, matrixKey.size());;
			int x = rasAlgEvkl(detMatrixKey, alf.size());
			int obrEl = 0;
			if ((detMatrixKey < 0 && x > 0) || (detMatrixKey > 0 && x > 0))
			{
				obrEl = x;
			}
			if (detMatrixKey < 0 && x < 0)
			{
				obrEl = -x;
			}
			if (detMatrixKey > 0 && x < 0)
			{
				obrEl = alf.size() + x;
			}
			if (obrEl < 97)
			{
				break;
			}
		}
	}
	ifstream fout("Some_text.txt");//читает файл с нашим текстом
	ofstream fin("Str_aft_proc.txt"); //очищает файл Str_aft_proc.txt куда записывает зашифрованный текст
	if (codeCheck == 1)
	{
		getline(fout, someKey);
	}
	fin << someKey << endl;

	string key = someKey;

	if (codeCheck == 1)
	{
		for (char i : key)
		{
			for (int j = 1; j < alf.size(); j++)
			{
				if (i == alf[j])
				{
					codByAlfKey.push_back(j);
				}
			}
		}
		for (int i = 0; i < (int)rint(sqrt(key.length())); i++)
		{
			vector<int> m;
			matrixKey.push_back(m);
		}
		g = 0;
		for (int i = 0; i < (int)rint(sqrt(key.length())); i++)
		{
			for (int j = 0; j < (int)rint(sqrt(key.length())); j++)
			{
				matrixKey[i].push_back(codByAlfKey[g++]);
			}
		}
	}
	system("CLS");
	funkPrinciple(1);
	funkTypeName(12);
	cout << "Your KEY: " << key << endl;
	cout << "Encrypted string: " << endl;
	while (!fout.eof())
	{
		string inputString = "";
		getline(fout, inputString);
		vector<int> codByAlfStr;
		for (char i : inputString)
		{
			for (int j = 0; j < alf.size(); j++)
			{
				if (i == alf[j])
				{
					codByAlfStr.push_back(j);
				}
			}
		}
		vector<vector<int>> matrixStr;
		int crat = 0;
		if ((codByAlfStr.size() % (int)rint(sqrt(key.length()))) != 0)
		{
			crat = 1;
		}
		for (int i = 0; i < codByAlfStr.size() / (int)rint(sqrt(key.length())) + crat; i++)
		{
			vector<int> m;
			matrixStr.push_back(m);
		}
		g = 0;
		for (int i = 0; i < codByAlfStr.size() / (int)rint(sqrt(key.length())) + crat; i++)
		{
			if (g < codByAlfStr.size())
			{
				for (int j = 0; j < (int)rint(sqrt(key.length())); j++)
				{
					matrixStr[i].push_back(codByAlfStr[g++]);
					if (g >= codByAlfStr.size())
					{
						while (matrixStr[i].size() < (int)rint(sqrt(key.length())))
						{
							matrixStr[i].push_back(0); ///////////////////////////////////////////////////
						}
						break;
					}
				}
			}
			else
			{
				while (matrixStr[i].size() < (int)rint(sqrt(key.length())))
				{
					matrixStr[i].push_back(0); ////////////////////////////////////////////////
				}
			}
		}
		vector<vector<int>> encryptStr;
		for (int i = 0; i < matrixStr.size(); i++)
		{
			vector<int> m;
			encryptStr.push_back(m);
		}
		int mnog = 0;
		g = -1;
		for (vector<int> blok : matrixStr)
		{
			g++;
			for (int i = 0; i < blok.size(); i++)
			{
				mnog = 0;
				for (int j = 0; j < blok.size(); j++)
				{
					mnog += blok[j] * matrixKey[j][i];
				}
				encryptStr[g].push_back(mnog);
			}
		}
		string outputString = "";
		for (vector<int> blok : encryptStr)
		{
			for (int i : blok)
			{
				outputString += alf[i % alf.size()];
			}
		}
		fin << outputString;
		cout << outputString << endl;
		if (!fout.eof())
		{
			fin << endl;
		}
	}
	fout.close();
	fin.close();
	cout << endl;
	system("PAUSE");
	system("CLS");
}