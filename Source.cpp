#include "Header.h"

//Main funk
int main()
{
	SetConsoleCP(1251);			//set ASKII by Windows console-in == console-out (for Кussian language)
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");	//Russian localization

	PASSWORD_CHEK();

	while (true)
	{
		string inputing;
		cout << "Enter a line for encryption" << endl << ": ";
		getline(cin, inputing);
		cin.ignore();
		ofstream fin("Inputstring.txt");
		fin << inputing;
		fin.close();


#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif


		int funk = principle_of_operation();
		funkprinciple(funk);

		int cryptotype = crypto_type_select(funk);

		start_encryption(cryptotype, funk);

		/*
		switch (cryptotype)
		{
		case 1:

		default:
			break;
		}
		*/
		//chek_encryption(cryptotype, funk);


		string code_chek;
		cout << "Do you want to check the encryption?" << endl << "<1>Yes" << endl << "<2>No" << endl << ":";
		cin >> code_chek;
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
			cin >> code_chek;
		}
		if (code_chek == "1")
		{
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
				cin.ignore();
				getline(cin, someKey);
				ofstream fin("SecretKEY.txt");
				fin << someKey;
				fin.close();

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
	return 0;
}