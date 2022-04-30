#include "principleOfOperation.h"

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