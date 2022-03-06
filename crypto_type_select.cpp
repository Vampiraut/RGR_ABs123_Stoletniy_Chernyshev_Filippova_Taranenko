#include "Header.h"

//Encryption type select
int crypto_type_select(int funk)
{
	string char_num_type;
	funkprinciple(funk);
	cout << "Select the encryption/decryption type: " << endl << "<1>Caesar's Cipher" << endl << "<2>The Gronsfeld Cipher" << endl << "<3>" << endl << "<4>" << endl << "<5>Hard Gronsfeld" << endl << ": ";
	getline(cin, char_num_type);

	//Protection against an incorrectly entered encryption type
	while (char_num_type != "1" && char_num_type != "2" && char_num_type != "3" && char_num_type != "4" && char_num_type != "5")
	{
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
		funkprinciple(funk);
		cout << "Error. Write \"1\" or \"2\" or \"3\" or \"4\" or \"5\" only." << endl;
		cout << "Select the encryption/decryption type: " << endl << "<1>Caesar's Cipher" << endl << "<2>The Gronsfeld Cipher" << endl << "<3>" << endl << "<4>" << endl << "<5>Hard Gronsfeld" << endl << ": ";
		getline(cin, char_num_type);
	}

	int int_num_type = 0;									//’рень дл€ преобразовани€ чара в инт (тип чтобы если в строку пришла 1, то она была в инте) Ќјƒќ ѕ≈–≈ѕ»—ј“№
	for (int i = 49; i < 54; i++)
	{
		char simb = i;
		if (simb == char_num_type[0])
		{
			int_num_type = i - 48;
		}
	}

#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
	return int_num_type;
}