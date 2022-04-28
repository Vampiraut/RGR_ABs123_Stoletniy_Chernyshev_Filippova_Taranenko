#include "Header.h"

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