#include "Header.h"

//Choosing the principle of operation
int principle_of_operation()
{
	string str_num_principle;
	cout << "Choose the principle of operation: " << endl << "<1>Encryption" << endl << "<2>Decryption" << endl << ": ";
	getline(cin, str_num_principle);

	//Protection against incorrectly entered operating principle
	while (str_num_principle != "1" && str_num_principle != "2")
	{
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
		cout << "Error. Write \"1\" or \"2\" only." << endl;
		cout << "Choose the principle of operation: " << endl << "<1>Encryption" << endl << "<2>Decryption" << endl << ": ";
		getline(cin, str_num_principle);
	}

	int int_num_principle = 0;									//’рень дл€ преобразовани€ чара в инт (тип чтобы если в строку пришла 1, то она была в инте) Ќјƒќ ѕ≈–≈ѕ»—ј“№
	for (int i = 49; i < 51; i++)
	{
		char simb = i;
		if (simb == str_num_principle[0])
		{
			int_num_principle = i - 48;
		}
	}

#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
	return int_num_principle;
}