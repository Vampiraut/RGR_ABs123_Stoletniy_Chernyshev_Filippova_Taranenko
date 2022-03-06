#include "Header.h"

void encryption_chek(int cryptotype, int funk)
{
	string code_chek;
	cout << "Do you want to check the encryption?" << endl << "<1>Yes" << endl << "<2>No" << endl << ":";
	getline(cin, code_chek);
	while (code_chek != "1" && code_chek != "2")
	{
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
		cout << "Error. Write \"1\" or \"2\" only." << endl;
		cout << "Do you want to check the encryption?" << endl << "<1>Yes" << endl << "<2>No" << endl << ":";
		getline(cin, code_chek);
	}
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
	if (code_chek == "1")
	{
		PASSWORD_CHEK();
		//Conditions for performing encryption for the selected type and principle of operation
		if (cryptotype == 1)
		{
			int smehenie = 5;	//Setting the offset for encoding (default = 5)
			if (funk == 2)
			{
				Caesar_CODE(smehenie);
			}

			else if (funk == 1)
			{
				Caesar_DECODE(smehenie);
			}
		}
		else if (cryptotype == 2)
		{
			string someKey;

			cout << "Enter the KEY" << endl << ":";
			getline(cin, someKey);
			ofstream fin("SecretKEY.txt");
			fin << someKey;
			fin.close();
#ifndef Clear
			system("CLS");
#endif
#ifdef Clear
			cout << endl;
#endif
			if (funk == 2)
			{
				Gronsfeld_CODE();
			}
			else if (funk == 1)
			{
				Gronsfeld_DECODE();
			}
		}
		else if (cryptotype == 3)
		{
			cout << "3)" << endl;
		}
		else if (cryptotype == 4)
		{
			cout << "4)" << endl;
		}
		else if (cryptotype == 5)
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