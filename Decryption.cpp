#include "Decryption.h"
#include "HillComp.h"

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
			for (; inputString[i] != 'O'; i++)
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

//Decryption with ElGamal cipher
void ElGamalDecode(){
	int p = 997;
	int x = 581;
	ifstream fout("Some_text.txt");
	ofstream fin("Str_aft_proc.txt");


	funkPrinciple(2);
	funkTypeName(5);

	cout << "Decrypted string:" << endl;
	while (!fout.eof()){
		string shStr = "";
		getline(fout, shStr);
		string oStr = "";
		int i = 0;
		while (i < shStr.length()){
			int a = 0;
			while (shStr[i] != ' ' && shStr[i] != '\0'){
				a = a * 10 + (shStr[i] - '0');
				i++;
			}
			i++;
			int b = 0;
			while (shStr[i] != ' ' && shStr[i] != '\0') {
				b = b * 10 + (shStr[i] - '0');
				i++;
			}
			i++;
			if (a != 0 && b != 0){
				int bukva = mod(b, deg(a, p - 1 - x, p), p);// m=b*a^(p-1-x)mod p
				char m = (char)(bukva);
				oStr += m;
			}
		}
		fin << oStr;
		cout << oStr << endl;
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

//Decryption with Gibberish cipher
void GibberishDecode(){
	map<char, char> alfavit{ { 'b', 'z' }, { 'c', 'x' }, { 'd', 'w' }, { 'f', 'v' }, { 'g', 't' }, { 'h', 's' }, { 'j', 'r' }, { 'k', 'q' }, { 'l', 'p' }, { 'm', 'n' },
	{ 'z', 'b' }, { 'x', 'c' }, { 'w', 'd' }, { 'v', 'f' }, { 't', 'g' }, { 's', 'h' }, { 'r', 'j' }, { 'q', 'k' }, { 'p', 'l' }, { 'n', 'm' },
	{ 'B', 'Z' }, { 'C', 'X' }, { 'D', 'W' }, { 'F', 'V' }, { 'G', 'T' }, { 'H', 'S' }, { 'J', 'R' }, { 'K', 'Q' }, { 'L', 'P' }, { 'M', 'N' },
	{ 'Z', 'B' }, { 'X', 'C' }, { 'W', 'D' }, { 'V', 'F' }, { 'T', 'G' }, { 'S', 'H' }, { 'R', 'J' }, { 'Q', 'K' }, { 'P', 'L' }, { 'N', 'M' },
	{ 'a', 'o' }, { 'e', 'u' }, { 'i', 'y' }, { 'o', 'a' }, { 'u', 'e' }, { 'y', 'i' },
	{ 'A', 'O' }, { 'E', 'U' }, { 'I', 'Y' }, { 'O', 'A' }, { 'U', 'E' }, { 'Y', 'I' } };


	ifstream fout("Some_text.txt");
	ofstream fin("Str_aft_proc.txt");


	funkPrinciple(2);
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
	while (!fout1.eof()) {
		vector<char> seng = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
		vector<char> beng = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
		inputString = "";
		outputString = "";
		getline(fout1, inputString);
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
	cout << "Decryption string: " << endl;
	while (!fout1.eof()) {
		inputString = "";
		outputString = "";
		getline(fout1, inputString);

		int columns = 1;
		int i, j, rez, count;
		for (i = 0; i < inputString.length(); i++)
		{
			if (inputString[i] == ' ')
			{
				columns++;
				inputString.erase(i, 1);
			}
		}
		count = inputString.length();
		if (columns == 1) {
			outputString = inputString;
		}
		else {
			int strings;
			strings = inputString.length() / columns + inputString.length() % columns;
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
			for (i = 0; i < strings; i++)
			{
				for (j = 0; j < columns; j++)
				{
					a[i][j] = inputString[rez];
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
			for (i = 0; i < columns; i++)
			{
				for (j = 0; j < strings; j++)
				{
					if (a[j][i] != '$') {
						rez++;
						if (rez == columns) {
							rez = 0;
							outputString += " ";
						}
						outputString += a[j][i];
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

//Decryption with Shamir cipher
void ShamirDecode() {
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
	funkPrinciple(2);
	funkTypeName(9);
	cout << "Decryption string: " << endl;
	int bufer = 0;
	int shag;
	while (!fout.eof())
	{
		getline(fout, input);
		bufer = 0;
		for (uint64_t i = 0; i < input.length(); ++i)
		{
			if ((input[i] == ' ') || (input[i] == '\0')) {
				shag = shamir(bufer, Da, p);
				shag = shamir(shag, Db, p);
				char out = shag;
				fin << out;
				cout << out;
				bufer = 0;
			}
			else {
				bufer = bufer * 10 + (input[i] - 48);
			}
		}
		shag = shamir(bufer, Da, p);
		shag = shamir(shag, Db, p);
		char out = shag;
		fin << out;
		cout << out;
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

//Decryption with Binary cipher
void BinaryDecode()
{
	ifstream fout("Some_text.txt");
	ofstream fin("Str_aft_proc.txt");
	string inputString = "";
	string outputString = "";

	funkPrinciple(2);
	funkTypeName(11);

	cout << "Decrypted string:" << endl;
	while (!fout.eof())
	{
		inputString = "";
		outputString = "";
		getline(fout, inputString);
		for (int i = 0; i < inputString.length(); i++)
		{
			string binCod = "";
			for (int j = i; inputString[j] != ' '; j++)
			{
				binCod += inputString[j];
				i = j;
			}
			i++;
			int decCod = 0;
			for (int j = 0; j < binCod.length(); j++)
			{
				if (binCod[j] == '1')
				{
					decCod += pow(2, (binCod.length() - 1) - j);
				}
			}
			char simb = (char)decCod;
			outputString += simb;
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

//Decryption with Hill cipher
void HillDecode(int codeCheck)
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
	if (codeCheck != 1)
	{
		string someKey = "";
		bool isGood = false;
		do
		{
			try
			{
				codByAlfKey.clear();
				matrixKey.clear();
				cout << "Enter the KEY" << endl << ": ";
				getline(cin, someKey);
				for (int i = 2; i < someKey.length(); i++)
				{
					if (someKey.length() == pow(i, 2))
					{
						isGood = true;
						break;
					}
				}
				if (isGood == false)
				{
					throw runtime_error("The key is incorrect.\nThe key length must be equal to the square of an integer.\n");
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
				for (int i = 0; i < (int)sqrt(someKey.length()); i++)
				{
					vector<int> m;
					matrixKey.push_back(m);
				}
				g = 0;
				for (int i = 0; i < (int)sqrt(someKey.length()); i++)
				{
					for (int j = 0; j < (int)sqrt(someKey.length()); j++)
					{
						matrixKey[i].push_back(codByAlfKey[g++]);
					}
				}
				if (determCalk(matrixKey, matrixKey.size()) == 0)
				{
					throw runtime_error("The key is incorrect.\nDuring calculations, the determinant of the key matrix turned out to be zero.\n");
				}
			}
			catch (const exception& error)
			{
				system("CLS");
				isGood = false;
				cout << error.what();
			}
		} while (isGood == false);
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
	}

	ifstream fout1("Some_text.txt");//читает файл с нашим текстом
	ofstream fin1("Str_aft_proc.txt"); //очищает файл Str_aft_proc.txt куда записывает зашифрованный текст
	string key = "";
	getline(fout1, key);
	fin1 << key << endl;
	if (codeCheck == 1)
	{
		for (char i : key)
		{
			for (int j = 0; j < alf.size(); j++)
			{
				if (i == alf[j])
				{
					codByAlfKey.push_back(j);
					break;
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
	funkPrinciple(2);   //есть codByAlfKey matrixKey
	funkTypeName(12);
	if (codeCheck == 1)
	{
		cout << "Your KEY: " << key << endl;
	}
	cout << "Decrypted string: " << endl;

	while (!fout1.eof())
	{
		string inputString = "";
		getline(fout1, inputString);
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
		if (codByAlfStr.size() % (int)rint(sqrt(key.length())) != 0)
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
							matrixStr[i].push_back(0); ///////////////////////////////////////////
						}
						break;
					}
				}
			}
			else
			{
				while (matrixStr[i].size() < (int)rint(sqrt(key.length())))
				{
					matrixStr[i].push_back(0); ////////////////////////////////////////////////////
				}
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

		vector<vector<int>> matrixAlgDop;
		for (int i = 0; i < matrixKey.size(); i++)
		{
			vector<int> m;
			matrixAlgDop.push_back(m);
		}
		vector<vector<int>> matMinor;
		for (int i = 0; i < matrixKey.size(); i++)
		{
			for (int j = 0; j < matrixKey.size(); j++)
			{
				matMinor.clear();
				for (int a = 0; a < matrixKey.size() - 1; a++)
				{
					vector<int> m;
					matMinor.push_back(m);
				}
				int lin = 0;
				bool isK = false;
				for (int k = 0; k < matrixKey.size(); k++)
				{
					isK = false;
					for (int f = 0; f < matrixKey.size(); f++)
					{
						if ((k != i) && (f != j))
						{
							matMinor[lin].push_back(matrixKey[k][f]);
							isK = true;
						}
					}
					if (isK == true)
					{
						lin++;
					}
				}
				matrixAlgDop[i].push_back(pow(-1, i + j) * determCalk(matMinor, matMinor.size()));
			}
		}
		for (int i = 0; i < matrixAlgDop.size(); i++)
		{
			for (int j = 0; j < matrixAlgDop.size(); j++)
			{
				if (matrixAlgDop[i][j] < 0)
				{
					int num = abs(matrixAlgDop[i][j]) % alf.size();
					matrixAlgDop[i][j] = -num;
				}
				else
				{
					matrixAlgDop[i][j] = matrixAlgDop[i][j] % alf.size();
				}
			}
		}
		for (int i = 0; i < matrixAlgDop.size(); i++)
		{
			for (int j = 0; j < matrixAlgDop.size(); j++)
			{
				if (matrixAlgDop[i][j] < 0)
				{
					int num = abs(matrixAlgDop[i][j] * obrEl) % alf.size();
					matrixAlgDop[i][j] = -num;
				}
				else
				{
					matrixAlgDop[i][j] = (matrixAlgDop[i][j] * obrEl) % alf.size();
				}
			}
		}

		vector<vector<int>> transpMatr;
		for (int i = 0; i < matrixAlgDop.size(); i++)
		{
			vector<int> m;
			transpMatr.push_back(m);
		}

		for (int i = 0; i < matrixAlgDop.size(); i++)
		{
			for (int j = 0; j < matrixAlgDop.size(); j++)
			{
				transpMatr[i].push_back(matrixAlgDop[j][i]);
			}
		}

		for (int i = 0; i < transpMatr.size(); i++)
		{
			for (int j = 0; j < transpMatr.size(); j++)
			{
				if (transpMatr[i][j] < 0)
				{
					transpMatr[i][j] = alf.size() + transpMatr[i][j];
				}
			}
		}//получии транспонированную матрицу которая является обратной по модулю к матрице ключа.

		vector<vector<int>> decryptStr;
		for (int i = 0; i < matrixStr.size(); i++)
		{
			vector<int> m;
			decryptStr.push_back(m);
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
					mnog += blok[j] * transpMatr[j][i];
				}
				decryptStr[g].push_back(mnog);
			}
		}
		string outputString = "";
		for (vector<int> blok : decryptStr)
		{
			for (int i : blok)
			{
				outputString += alf[i % alf.size()];
			}
		}
		fin1 << outputString;
		cout << outputString << endl;
		if (!fout1.eof())
		{
			fin1 << endl;
		}
	}
	fout1.close();
	fin1.close();
	cout << endl;
	system("PAUSE");
	system("CLS");
}