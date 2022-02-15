#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include <windows.h>

using namespace std;

char* memorylock(int n)                                           //memory lock function for dynamic array
{
	char* B;
	B = static_cast <char*> (calloc(n, sizeof(char)));
	return B;
}

void CODE(int smehenie)
{
	string inputstring;                                        //input string
	bool end;                                                  //cheсk-flag for continue
	int n = 2;                                                 //start memory lock (1 free  and 1 for end-string symbol)
	char* outputstring = memorylock(n);
	char* outputstring_cop = memorylock(n);


	cout << "Enter coding string: ";                           //enter input string module
	cin.ignore();                                              //
	getline(cin, inputstring);                                 //



	for (int i = 0; inputstring[i] != '\0'; i++)               //input string check
	{
		end = false;												//set check-flag to false
		for (int j = 33; j < 127; j++)								//ASKII 33 -> 126 check in input string
		{
			char ASCIICod = j;											//int-dek to ASKII-symbol

			if (inputstring[i] == ' ')									//ignore the space module
			{															//
				break;													//
			}															//

			else if (inputstring[i] == ASCIICod)						//comparison of the symbol of the input string and the ASKII character
			{
				int smena = j + smehenie;									//shift by ASKII table (smehenie (defalt = 3))

				for (int h = 127; h < (127 + smehenie); h++)				//exclusion of unreadable characters from the ASKII table module
				{                                                           //
					if (smena == h)                                         //
					{                                                       //
						smena = smena + 65;                                 //
					}                                                       //
				}                                                           //

				char ASCIICod_smena = smena;                                //changing a character and saving it to the output array
				outputstring[i] = ASCIICod_smena;							//

				for (int g = 0; g < n; g++)                                 //updating (lengthening) the array in memory module
				{															//
					outputstring_cop[g] = outputstring[g];					//
				}															//
				n++;														//
				free(outputstring);											//
				outputstring = memorylock(n);								//
				for (int g = 0; g < n - 1; g++)								//
				{															//
					outputstring[g] = outputstring_cop[g];					//
				}															//
				free(outputstring_cop);										//
				outputstring_cop = memorylock(n);							//

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
				int smena = j + smehenie;									//shift by ASKII table (smehenie (defalt = 3))

				for (int h = 256; h < (256 + smehenie); h++)				//exclusion of unreadable characters from the ASKII table module
				{															//
					if (smena == h)											//
					{														//
						smena = smena - 256 + 33;							//
					}														//
				}															//

				char ASCIICod_smena = smena;								//changing a character and saving it to the output array
				outputstring[i] = ASCIICod_smena;							//

				for (int g = 0; g < n; g++)									//updating (lengthening) the array in memory module
				{															//
					outputstring_cop[g] = outputstring[g];					//
				}															//
				n++;														//
				free(outputstring);											//
				outputstring = memorylock(n);								//
				for (int g = 0; g < n - 1; g++)								//
				{															//
					outputstring[g] = outputstring_cop[g];					//
				}															//
				free(outputstring_cop);										//
				outputstring_cop = memorylock(n);							//

				end = true;													//set check-flag to true
				break;														//break the cycle
			}
		}

		if (end == true)											//check check-flag (if true -> do not check symbols further)
		{
			continue;
		}

		outputstring[i] = inputstring[i];                           //if there is no ASKII in the range -> copy them to the output array without modification

		for (int g = 0; g < n; g++)                                 //also updating (lengthening) the array in memory module
		{
			outputstring_cop[g] = outputstring[g];
		}
		n++;
		free(outputstring);
		outputstring = memorylock(n);
		for (int g = 0; g < n - 1; g++)
		{
			outputstring[g] = outputstring_cop[g];
		}
		free(outputstring_cop);
		outputstring_cop = memorylock(n);
		continue;
	}

	system("CLS");												//clear console

	cout << "Coding string: ";									//output of encrypted text module
	for (int g = 0; g < n - 1; g++)								//
	{															//
		cout << outputstring[g];								//
	}															//

	free(outputstring);											//cleaning memory
	free(outputstring_cop);										//
	cout << endl;
}

void DECODE(int smehenie)
{
	string inputstring;                                        //input string
	bool end;                                                  //cheсk-flag for continue
	int n = 2;                                                 //start memory lock (1 free  and 1 for end-string symbol)
	char* outputstring = memorylock(n);
	char* outputstring_cop = memorylock(n);


	cout << "Enter decoding string: ";                         //enter input string module
	cin.ignore();                                              //
	getline(cin, inputstring);                                 //



	for (int i = 0; inputstring[i] != '\0'; i++)               //input string check
	{
		end = false;												//set check-flag to false
		for (int j = 33; j < 127; j++)								//ASKII 33 -> 126 check in input string
		{
			char ASCIICod = j;											//int-dek to ASKII-symbol

			if (inputstring[i] == ' ')									//ignore the space module
			{															//
				break;													//
			}															//

			else if (inputstring[i] == ASCIICod)						//comparison of the symbol of the input string and the ASKII character
			{
				int smena = j - smehenie;									//shift by ASKII table (smehenie (default = 3))

				for (int h = 30; h < (30 + smehenie); h++)				//exclusion of unreadable characters from the ASKII table module
				{                                                           //
					if (smena == h)                                         //
					{                                                       //
						smena = smena + 256 - 33;                           //
					}                                                       //
				}                                                           //

				char ASCIICod_smena = smena;                                //changing a character and saving it to the output array
				outputstring[i] = ASCIICod_smena;							//

				for (int g = 0; g < n; g++)                                 //updating (lengthening) the array in memory module
				{															//
					outputstring_cop[g] = outputstring[g];					//
				}															//
				n++;														//
				free(outputstring);											//
				outputstring = memorylock(n);								//
				for (int g = 0; g < n - 1; g++)								//
				{															//
					outputstring[g] = outputstring_cop[g];					//
				}															//
				free(outputstring_cop);										//
				outputstring_cop = memorylock(n);							//

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
				int smena = j - smehenie;									//shift by ASKII table (smehenie (default = 3))

				for (int h = 189; h < (189 + smehenie); h++)				//exclusion of unreadable characters from the ASKII table module
				{															//
					if (smena == h)											//
					{														//
						smena = smena - 65;									//
					}														//
				}															//

				char ASCIICod_smena = smena;								//changing a character and saving it to the output array
				outputstring[i] = ASCIICod_smena;							//

				for (int g = 0; g < n; g++)									//updating (lengthening) the array in memory module
				{															//
					outputstring_cop[g] = outputstring[g];					//
				}															//
				n++;														//
				free(outputstring);											//
				outputstring = memorylock(n);								//
				for (int g = 0; g < n - 1; g++)								//
				{															//
					outputstring[g] = outputstring_cop[g];					//
				}															//
				free(outputstring_cop);										//
				outputstring_cop = memorylock(n);							//

				end = true;													//set check-flag to true
				break;														//break the cycle
			}
		}

		if (end == true)											//check check-flag (if true -> do not check symbols further)
		{
			continue;
		}

		outputstring[i] = inputstring[i];                           //if there is no ASKII in the range -> copy them to the output array without modification

		for (int g = 0; g < n; g++)                                 //also updating (lengthening) the array in memory module
		{
			outputstring_cop[g] = outputstring[g];
		}
		n++;
		free(outputstring);
		outputstring = memorylock(n);
		for (int g = 0; g < n - 1; g++)
		{
			outputstring[g] = outputstring_cop[g];
		}
		free(outputstring_cop);
		outputstring_cop = memorylock(n);
		continue;
	}

	system("CLS");												//clear console

	cout << "Decoding string: ";									//output of encrypted text module
	for (int g = 0; g < n - 1; g++)								//
	{															//
		cout << outputstring[g];								//
	}															//

	free(outputstring);											//cleaning memory
	free(outputstring_cop);										//
	cout << endl;
}

void main()
{
	SetConsoleCP(1251);											//set ASKII by Windows console-in == console-out (for Кussian language)
	SetConsoleOutputCP(1251);									//

	setlocale(LC_ALL, "Rus");									//Russian localization

	string funk;												//string to understand what to do with your string
	cout << "Code or Decode: ";									//
	cin >> funk;												//

	int smehenie = 3;											//setting the offset for encoding (default = 3)

	if (funk != "Code" || funk != "Decode")						//if you didn't write "Decode" or "Code"
	{
		while (funk != "Code" && funk != "Decode")
		{
			system("CLS");
			cout << "Error. Write \"Code\" or \"Decode\" only." << endl;
			cout << "Code or Decode: ";
			cin >> funk;
		}
	}

	system("CLS");												//clear console


	if (funk == "Code")											//start CODE or DECODE funk
	{
		CODE(smehenie);
	}

	else if (funk == "Decode")
	{
		DECODE(smehenie);
	}
}