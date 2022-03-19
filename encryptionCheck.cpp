#include "Header.h"

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
		passwordCheñk();
		//Conditions for performing encryption for the selected type and principle of operation
		if (cryptoType == 1)
		{
			if (funkType == 2)
			{
				CaesarCode();
			}

			else if (funkType == 1)
			{
				CaesarDecode();
			}
		}
		else if (cryptoType == 2)
		{
			if (funkType == 2)
			{
				GronsfeldCode();
			}
			else if (funkType == 1)
			{
				GronsfeldDecode();
			}
		}
		else if (cryptoType == 3)
		{
			cout << "3)" << endl;
		}
		else if (cryptoType == 4)
		{
			cout << "4)" << endl;
		}
		else if (cryptoType == 5)
		{
			cout << "5)" << endl;
		}
	}

	else
	{
		system("PAUSE");
	}
	system("CLS");
}