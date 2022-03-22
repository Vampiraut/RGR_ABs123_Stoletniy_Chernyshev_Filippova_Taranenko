#include "Header.h"

//Encryption with the Gronsfeld cipher
void GronsfeldCode()
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

	string inputString;                                         //input string
	string outputString;										//output string
	bool isEnd;                                                   //cheñk-flag for continue
	string key;


	ifstream fout("Inputstring.txt");
	getline(fout, inputString);
	fout.close();

	ifstream fout1("SecretKey.txt");
	getline(fout1, key);
	fout1.close();
	int p = -1;

	for (int i = 0; inputString[i] != '\0'; i++)                //input string check
	{
		if (inputString[i] == ' ')
		{
			outputString += inputString[i];
			continue;
		}
		p++;
		int smehenie = 0;
		for (int k = 48; k < 58; k++)
		{
			if (key[p] == '\0')
			{
				p = 0;
			}
			char ASKIIkey = k;
			if (ASKIIkey == key[p])
			{
				smehenie = k - 48;
			}
		}
		isEnd = false;												//set check-flag to false
		for (int j = 33; j < 127; j++)								//ASKII 33 -> 126 check in input string
		{
			char ASCIICod = j;											//int-dek to ASKII-symbol															
			if (inputString[i] == ASCIICod)								//comparison of the symbol of the input string and the ASKII character
			{
				int smena = j + smehenie;									//shift by ASKII table (smehenie (defalt = 5))
				for (int h = 127; h < (127 + smehenie); h++)				//exclusion of unreadable characters from the ASKII table module
				{
					if (smena == h)
					{
						smena = smena + 65;
					}
				}
				char ASCIICod_smena = smena;                                //changing a character and saving it to the output array
				outputString += ASCIICod_smena;
				isEnd = true;													//set check-flag to true
				break;														//break the cycle
			}
		}
		if (isEnd == true)											//check check-flag (if true -> do not check symbols further)
		{
			continue;
		}

		for (int j = 192; j < 256; j++)								//ASKII 192 -> 255 check in input string
		{
			char ASCIICod = j;											//int-dek to ASKII-symbol
			if (inputString[i] == ASCIICod)								//comparison of the symbol of the input string and the ASKII character
			{
				int smena = j + smehenie;									//shift by ASKII table (smehenie (defalt = 5))
				for (int h = 256; h < (256 + smehenie); h++)				//exclusion of unreadable characters from the ASKII table module
				{
					if (smena == h)
					{
						smena = smena - 256 + 33;
					}
				}
				char ASCIICod_smena = smena;								//changing a character and saving it to the output array
				outputString += ASCIICod_smena;
				isEnd = true;													//set check-flag to true
				break;														//break the cycle
			}
		}
		if (isEnd == true)											//check check-flag (if true -> do not check symbols further)
		{
			continue;
		}
		outputString += inputString[i];								//if there is no ASKII in the range -> copy them to the output array without modification
	}

#ifndef Clear
	system("CLS");
#endif
	funkPrinciple(1);
	funkTypeName(2);

	cout << "Encrypted string: " << outputString << endl;			//output of encrypted string

	ofstream fin1("Inputstring.txt");
	fin1 << outputString;
	fin1.close();

#ifndef Clear
	system("PAUSE");
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
}