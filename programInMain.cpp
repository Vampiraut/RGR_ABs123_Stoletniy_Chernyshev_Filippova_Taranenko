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
	cout << "Select the encryption/decryption type: " << endl << "<1>The Gronsfeld Cipher" << endl << "<2>RSA Cipher" << endl << "<3>" << endl
		<< "<4>Vernam Cipher" << endl << "<5>" << endl << "<6>"
		<< endl << "<7>" << endl << "<8>" << endl << "<9>"
		<< endl << "<10>" << endl << "<11>" << endl << "<12>"
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
		cout << "Select the encryption/decryption type: " << endl << "<1>The Gronsfeld Cipher" << endl << "<2>RSA Cipher" << endl << "<3>" << endl
			<< "<4>Vernam Cipher" << endl << "<5>" << endl << "<6>"
			<< endl << "<7>" << endl << "<8>" << endl << "<9>"
			<< endl << "<10>" << endl << "<11>" << endl << "<12>"
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
	switch (cryptoType)
	{
	case 1:
		switch (funkType)
		{
		case 1:
			GronsfeldCode(0);
			break;
		case 2:
			GronsfeldDecode(0);
			break;
		}
		break;
	case 2:
		switch (funkType)
		{
		case 1:
			RSAKeyGeneration(0);
			RSACode();
			break;
		case 2:
			RSAKeyGeneration(1);
			RSADecode();
			break;
		}
		break;
	case 3:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

			break;
		}
		break;
	case 4:
		switch (funkType)
		{
		case 1:
			VernamCode();
			break;
		case 2:
			VernamDecode();
			break;
		}
		break;
	case 5:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

			break;
		}
		break;
	case 6:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

			break;
		}
		break;
	case 7:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

			break;
		}
		break;
	case 8:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

			break;
		}
		break;
	case 9:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

			break;
		}
		break;
	case 10:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

			break;
		}
		break;
	case 11:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

			break;
		}
		break;
	case 12:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

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
		switch (cryptoType)
		{
		case 1:
			switch (funkType)
			{
			case 1:
				GronsfeldDecode(1);
				break;
			case 2:
				GronsfeldCode(1);
				break;
			}
			break;
		case 2:
			switch (funkType)
			{
			case 1:
				RSADecode();
				break;
			case 2:
				RSACode();
				break;
			}
			break;
		case 3:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 4:
			switch (funkType)
			{
			case 1:
				VernamDecode();
				break;
			case 2:
				VernamCode();
				break;
			}
			break;
		case 5:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 6:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 7:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 8:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 9:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 10:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 11:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 12:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

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