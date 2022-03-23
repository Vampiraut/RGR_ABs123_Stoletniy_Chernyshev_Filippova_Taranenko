#include "Header.h"

//Encryption type select
int cryptoTypeSelect(int funkType)
{
	funkPrinciple(funkType);
	cout << "Select the encryption/decryption type: " << endl << "<1>The Gronsfeld Cipher" << endl << "<2>" << endl << "<3>" << endl << "<4>" << endl << "<5>RSA Cipher" << endl << ": ";
	string strNumType;
	getline(cin, strNumType);

	//Protection against an incorrectly entered encryption type
	while (strNumType != "1" && strNumType != "2" && strNumType != "3" && strNumType != "4" && strNumType != "5")
	{
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
		funkPrinciple(funkType);
		cout << "Error. Write \"1\" or \"2\" or \"3\" or \"4\" or \"5\" only." << endl;
		cout << "Select the encryption/decryption type: " << endl << "<1>The Gronsfeld Cipher" << endl << "<2>" << endl << "<3>" << endl << "<4>" << endl << "<5>RSA Cipher" << endl << ": ";
		getline(cin, strNumType);
	}

	int intNumType = strNumType[0] - 48;

#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
	return intNumType;
}