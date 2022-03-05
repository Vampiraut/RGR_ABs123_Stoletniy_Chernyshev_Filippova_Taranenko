#include "Header.h"

//Decryption with the Caesar cipher
void Caesar_DECODE(int smehenie)
{
	string inputstring;                                         //input string
	string outputstring;										//output string
	bool end;                                                   //cheñk-flag for continue

	ifstream fout("Inputstring.txt");
	getline(fout, inputstring);
	fout.close();

	for (int i = 0; inputstring[i] != '\0'; i++)                //input string check
	{
		if (inputstring[i] == ' ')
		{
			outputstring += inputstring[i];
			continue;
		}
		end = false;												//set check-flag to false
		for (int j = 33; j < 127; j++)								//ASKII 33 -> 126 check in input string
		{
			char ASCIICod = j;											//int-dek to ASKII-symbol														
			if (inputstring[i] == ASCIICod)								//comparison of the symbol of the input string and the ASKII character
			{
				int smena = j - smehenie;									//shift by ASKII table (smehenie (default = 5))

				for (int h = 33 - smehenie; h < 33; h++)					//exclusion of unreadable characters from the ASKII table module
				{
					if (smena == h)
					{
						smena = smena + 256 - 33;
					}
				}

				char ASCIICod_smena = smena;                                //changing a character and saving it to the output array
				outputstring += ASCIICod_smena;
				end = true;													//set check-flag to true
				break;														//break the cycle
			}
		}
		if (end == true)											//check check-flag (if true -> do not check symbols further)
		{
			continue;
		}

		for (int j = 192; j < 256; j++)								//ASKII 192 -> 255 check in input string
		{
			char ASCIICod = j;											//int-dek to ASKII-symbol
			if (inputstring[i] == ASCIICod)								//comparison of the symbol of the input string and the ASKII character
			{
				int smena = j - smehenie;									//shift by ASKII table (smehenie (default = 5))
				for (int h = 192 - smehenie; h < 192; h++)					//exclusion of unreadable characters from the ASKII table module
				{
					if (smena == h)
					{
						smena = smena - 65;
					}
				}
				char ASCIICod_smena = smena;								//changing a character and saving it to the output array
				outputstring += ASCIICod_smena;
				end = true;													//set check-flag to true
				break;														//break the cycle
			}
		}
		if (end == true)											//check check-flag (if true -> do not check symbols further)
		{
			continue;
		}
		outputstring += inputstring[i];								//if there is no ASKII in the range -> copy them to the output array without modification
	}

#ifndef Clear
	system("CLS");
#endif
	funkprinciple(2);
	funktypename(1);

	cout << "Decryption string: " << outputstring << endl;		//output of the decrypted string

	ofstream fin("Inputstring.txt");
	fin << outputstring;
	fin.close();

	system("PAUSE");
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
}