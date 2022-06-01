#include "programInMain.h"

//Password verification function
void passwordCheñk()
{
	string password = "";
	cout << "Enter password" << endl << ": ";
	getline(cin, password);
	while (password != PASSWORD)
	{
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
		cout << "Wrong password!" << endl << "Enter password" << endl << ": ";
		getline(cin, password);
	}
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
	cout << "Authorization success!" << endl;;
	Sleep(500);
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
}

//Entering a string and saving it to a file or copying and encrypting your file
void inputStrToTxt()
{
	string fileCreate = "";
	cout << "Do you want to encrypt your file or create a new one?" << endl << "<1>Your file" << endl << "<2>A new file" << endl << ": ";
	getline(cin, fileCreate);
	while (fileCreate != "1" && fileCreate != "2")
	{
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
		cout << "Error. Write \"1\" or \"2\" only." << endl;
		cout << "Do you want to encrypt your file or create a new one?" << endl << "<1>Your file" << endl << "<2>A new file" << endl << ": ";
		getline(cin, fileCreate);
	}
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
	if (fileCreate == "1")
	{
		cout << "Enter the path to the file (remember, the file must be ANSI or Windows-1251 encoded)" << endl << ": ";
		string path = "";
		getline(cin, path);
		ofstream fin("Some_text.txt");
		ifstream fout(path);
		while (!fout.is_open())
		{
#ifndef Clear
			system("CLS");
#endif
#ifdef Clear
			cout << endl;
#endif
			cout << "Unknown file path!" << endl;
			cout << "Enter the path to the file (remember, the file must be ANSI or Windows-1251 encoded)" << endl << ": ";
			getline(cin, path);
			fout.open(path);
		}
		string bufer = "";
		while (!fout.eof())
		{
			getline(fout, bufer);
			fin << bufer;
			if (!fout.eof())
			{
				fin << endl;
			}
		}
		fin.close();
		fout.close();
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
	}
	else if (fileCreate == "2")
	{
		string inputStr = "";
		cout << "Enter a line for encryption" << endl << ": ";
		getline(cin, inputStr);
		while (inputStr == "")
		{
#ifndef Clear
			system("CLS");
#endif
#ifdef Clear
			cout << endl;
#endif
			cout << "An empty string has been entered!" << endl;
			cout << "Enter a line for encryption" << endl << ": ";
			getline(cin, inputStr);
		}
		ofstream fin("Some_text.txt");
		fin << inputStr;
		fin.close();
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
	}
}

//Choosing the principle of operation
int principleOfOperation()
{
	cout << "Choose the principle of operation: " << endl << "<1>Encryption" << endl << "<2>Decryption" << endl << ": ";
	string strNumPrinciple = "";
	getline(cin, strNumPrinciple);

	//Protection against incorrectly entered operating principle
	while (strNumPrinciple != "1" && strNumPrinciple != "2")
	{
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
		cout << "Error. Write \"1\" or \"2\" only." << endl;
		cout << "Choose the principle of operation: " << endl << "<1>Encryption" << endl << "<2>Decryption" << endl << ": ";
		getline(cin, strNumPrinciple);
	}

	int intNumPrinciple = strNumPrinciple[0] - 48;

#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
	return intNumPrinciple;
}

//Encryption type select
int cryptoTypeSelect(int funkType)
{
	funkPrinciple(funkType);
	cout << "Select the encryption/decryption type: " << endl << "<1>Gronsfeld Cipher" << endl << "<2>RSA Cipher" << endl << "<3>Morse Cipher" << endl
		<< "<4>Vernam Cipher" << endl << "<5>" << endl << "<6>"
		<< endl << "<7>Atbash Cipher" << endl << "<8>Simple Table Permutation" << endl << "<9>"
		<< endl << "<10>Vigener Cipher" << endl << "<11>Binary Cipher" << endl << "<12>Gibberish letter"
		<< endl << ": ";
	string strNumType;
	getline(cin, strNumType);

	//Protection against an incorrectly entered encryption type
	while (strNumType != "1" && strNumType != "2" && strNumType != "3" && strNumType != "4" && strNumType != "5" && strNumType != "6"
		&& strNumType != "7" && strNumType != "8" && strNumType != "9" && strNumType != "10" && strNumType != "11" && strNumType != "12")
	{
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
		funkPrinciple(funkType);
		cout << "Error. Write \"1\" or \"2\" or \"3\" or \"4\" or \"5\" or \"6\" or \"7\" or \"8\" or \"9\" or \"10\" or \"11\" or \"12\" only." << endl;
		cout << "Select the encryption/decryption type: " << endl << "<1>Gronsfeld Cipher" << endl << "<2>RSA Cipher" << endl << "<3>Morse Cipher" << endl
			<< "<4>Vernam Cipher" << endl << "<5>" << endl << "<6>"
			<< endl << "<7>Atbash Cipher" << endl << "<8>Simple Table Permutation" << endl << "<9>"
			<< endl << "<10>Vigener Cipher" << endl << "<11>Binary Cipher" << endl << "<12>Gibberish letter"
			<< endl << ": ";
		getline(cin, strNumType);
	}
	int intNumType = 0;
	for (int i = 0; strNumType[i] != '\0'; i++)
	{
		intNumType = (intNumType * 10) + (strNumType[i] - 48);
	}
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
	return intNumType;
}

//Conditions for performing encryption for the selected type and principle of operation
void encryptionStart(int cryptoType, int funkType)
{
	switch (Ciphers(cryptoType))
	{
	case Ciphers::Gronsfeld:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			GronsfeldCode(0);
			break;
		case Principle::Decription:
			GronsfeldDecode(0);
			break;
		}
		break;
	case Ciphers::RSA:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			RSAKeyGeneration(0);
			RSACode();
			break;
		case Principle::Decription:
			RSAKeyGeneration(1);
			RSADecode();
			break;
		}
		break;
	case Ciphers::Morse:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			MorseCode();
			break;
		case Principle::Decription:
			MorseDecode();
			break;
		}
		break;
	case Ciphers::Vernam:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			VernamCode();
			break;
		case Principle::Decription:
			VernamDecode();
			break;
		}
		break;
	case 5:
		switch (Principle(funkType))
		{
		case Principle::Encription:

			break;
		case Principle::Decription:

			break;
		}
		break;
	case 6:
		switch (Principle(funkType))
		{
		case Principle::Encription:

			break;
		case Principle::Decription:

			break;
		}
		break;
	case Ciphers::Atbash:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			AtbashCode(0);
			break;
		case Principle::Decription:
			AtbashDecode(0);
			break;
		}
		break;
	case Ciphers::SimpleTablePermutation:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			SimpleTablePermutationCode(0);
			break;
		case Principle::Decription:
			SimpleTablePermutationDecode(0);
			break;
		}
		break;
	case 9:
		switch (Principle(funkType))
		{
		case Principle::Encription:

			break;
		case Principle::Decription:

			break;
		}
		break;
	case Ciphers::Vigener:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			VigenerCode(VigenerMatrixCreate(), 0);
			break;
		case Principle::Decription:
			VigenerDecode(VigenerMatrixCreate(), 0);
			break;
		}
		break;
	case Ciphers::Binary:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			//BinaryCode();
			break;
		case Principle::Decription:
			//BinaryDecode();
			break;
		}
		break;
	case Ciphers::Gibberish:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			//GibberishCode();
			break;
		case Principle::Decription:
			//GibberishDecode();
			break;
		}
		break;
	}
}

//The function of starting the encryption check
void encryptionCheck(int cryptoType, int funkType)
{
	cout << "Do you want to check the encryption?" << endl << "<1>Yes" << endl << "<2>No" << endl << ":";
	string codeCheck = "";
	getline(cin, codeCheck);
	while (codeCheck != "1" && codeCheck != "2")
	{
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
		cout << "Error. Write \"1\" or \"2\" only." << endl;
		cout << "Do you want to check the encryption?" << endl << "<1>Yes" << endl << "<2>No" << endl << ":";
		getline(cin, codeCheck);
	}
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
	if (codeCheck == "1")
	{
		string bufer = "";
		ofstream fin("Some_text.txt");   //if - ÷òåíèå, of - çàïèñü
		ifstream fout("Str_aft_proc.txt");
		while (!fout.eof())
		{
			getline(fout, bufer);
			fin << bufer;
			if (!fout.eof())
			{
				fin << '\n';
			}
		}
		fin.close();
		fout.close();

		passwordCheñk();
		//Conditions for performing encryption for the selected type and principle of operation
		switch (Ciphers(cryptoType))
		{
		case Ciphers::Gronsfeld:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				GronsfeldDecode(1);
				break;
			case Principle::Decription:
				GronsfeldCode(1);
				break;
			}
			break;
		case Ciphers::RSA:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				RSADecode();
				break;
			case Principle::Decription:
				RSACode();
				break;
			}
			break;
		case Ciphers::Morse:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				MorseDecode();
				break;
			case Principle::Decription:
				MorseCode();
				break;
			}
			break;
		case Ciphers::Vernam:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				VernamDecode();
				break;
			case Principle::Decription:
				VernamCode();
				break;
			}
			break;
		case 5:
			switch (Principle(funkType))
			{
			case Principle::Encription:

				break;
			case Principle::Decription:

				break;
			}
			break;
		case 6:
			switch (Principle(funkType))
			{
			case Principle::Encription:

				break;
			case Principle::Decription:

				break;
			}
			break;
		case Ciphers::Atbash:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				AtbashDecode(1);
				break;
			case Principle::Decription:
				AtbashCode(1);
				break;
			}
			break;
		case Ciphers::SimpleTablePermutation:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				SimpleTablePermutationDecode(1);
				break;
			case Principle::Decription:
				SimpleTablePermutationCode(1);
				break;
			}
			break;
		case 9:
			switch (Principle(funkType))
			{
			case Principle::Encription:

				break;
			case Principle::Decription:

				break;
			}
			break;
		case Ciphers::Vigener:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				VigenerDecode(VigenerMatrixCreate(), 1);
				break;
			case Principle::Decription:
				VigenerCode(VigenerMatrixCreate(), 1);
				break;
			}
			break;
		case Ciphers::Binary:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				//BinaryDecode();
				break;
			case Principle::Decription:
				//BinaryCode();
				break;
			}
			break;
		case Ciphers::Gibberish:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				//GibberishDecode();
				break;
			case Principle::Decription:
				//GibberishCode();
				break;
			}
			break;
		}
	}
#ifdef Clear
	system("PAUSE");
#endif
	system("CLS");
}