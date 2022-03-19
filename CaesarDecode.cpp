#include "Header.h"

//Decryption with the Caesar cipher
void CaesarDecode()
{
	int smehenie = 5;											//Setting the offset for encoding (default = 5)
	string inputString;                                         //input string
	string outputString;										//output string
	bool isEnd;                                                   //cheñk-flag for continue

	ifstream fout("Inputstring.txt");
	getline(fout, inputString);
	fout.close();

	for (int i = 0; inputString[i] != '\0'; i++)                //input string check
	{
		if (inputString[i] == ' ')
		{
			outputString += inputString[i];
			continue;
		}
		isEnd = false;												//set check-flag to false
		for (int j = 33; j < 127; j++)								//ASKII 33 -> 126 check in input string
		{
			char ASCIICod = j;											//int-dek to ASKII-symbol														
			if (inputString[i] == ASCIICod)								//comparison of the symbol of the input string and the ASKII character
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
				int smena = j - smehenie;									//shift by ASKII table (smehenie (default = 5))
				for (int h = 192 - smehenie; h < 192; h++)					//exclusion of unreadable characters from the ASKII table module
				{
					if (smena == h)
					{
						smena = smena - 65;
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
	funkPrinciple(2);
	funkTypeName(1);

	cout << "Decryption string: " << outputString << endl;		//output of the decrypted string

	ofstream fin1("Inputstring.txt");
	fin1 << outputString;
	fin1.close();

	system("PAUSE");
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
}