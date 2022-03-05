#include "Header.h"

//Conditions for performing encryption for the selected type and principle of operation
void start_encryption(int cryptotype, int funk)
{
	if (cryptotype == 1)
	{
		int smehenie = 5;
		if (funk == 1)
		{
			Caesar_CODE(smehenie);
		}

		else if (funk == 2)
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

		if (funk == 1)
		{
			Gronsfeld_CODE();
		}
		else if (funk == 2)
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