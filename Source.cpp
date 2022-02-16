#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include <windows.h>

using namespace std;

void funktypename(string cryptotype)
{
	if (cryptotype == "1")
	{
		cout << "1)Caesar's Cipher" << endl;
	}
	else if (cryptotype == "2")
	{
		cout << "2)" << endl;
	}
	else if (cryptotype == "2")
	{
		cout << "3)" << endl;
	}
	else if (cryptotype == "2")
	{
		cout << "4)" << endl;
	}
	else if (cryptotype == "2")
	{
		cout << "5)" << endl;
	}
}

char* memorylock(int n)                                           //memory lock function for dynamic array
{
	char* B;
	B = static_cast <char*> (calloc(n, sizeof(char)));
	return B;
}

void CaesarCODE(int smehenie)
{
	string inputstring;                                        //input string
	string outputstring;
	bool end;                                                  //cheсk-flag for continue
	cout << "Enter coding string: ";                           //enter input string module
	cin.ignore();                                              
	getline(cin, inputstring);                                 
	for (int i = 0; inputstring[i] != '\0'; i++)               //input string check
	{
		end = false;												//set check-flag to false
		for (int j = 33; j < 127; j++)								//ASKII 33 -> 126 check in input string
		{
			char ASCIICod = j;											//int-dek to ASKII-symbol															
			if (inputstring[i] == ASCIICod)						//comparison of the symbol of the input string and the ASKII character
			{
				int smena = j + smehenie;									//shift by ASKII table (smehenie (defalt = 3))
				for (int h = 127; h < (127 + smehenie); h++)				//exclusion of unreadable characters from the ASKII table module
				{                                                       
					if (smena == h)                                         
					{                                                       
						smena = smena + 65;                                 
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
				int smena = j + smehenie;									//shift by ASKII table (smehenie (defalt = 3))
				for (int h = 256; h < (256 + smehenie); h++)				//exclusion of unreadable characters from the ASKII table module
				{															
					if (smena == h)											
					{														
						smena = smena - 256 + 33;							
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
		outputstring += inputstring[i];                           //if there is no ASKII in the range -> copy them to the output array without modification
	}
	int n = outputstring.length();
	system("CLS");												//clear console
	cout << "Coding string: ";									//output of encrypted text module
	for (int g = 0; g < n; g++)									
	{															
		cout << outputstring[g];								
	}															
	cout << endl;
}

void CaesarDECODE(int smehenie)
{
	string inputstring;                                        //input string
	string outputstring;
	bool end;                                                  //cheсk-flag for continue
	cout << "Enter decoding string: ";                         //enter input string module
	cin.ignore();                                              
	getline(cin, inputstring);                                 
	for (int i = 0; inputstring[i] != '\0'; i++)               //input string check
	{
		end = false;												//set check-flag to false
		for (int j = 33; j < 127; j++)								//ASKII 33 -> 126 check in input string
		{
			char ASCIICod = j;											//int-dek to ASKII-symbol														
			if (inputstring[i] == ASCIICod)								//comparison of the symbol of the input string and the ASKII character
			{
				int smena = j - smehenie;									//shift by ASKII table (smehenie (default = 3))

				for (int h = 30; h < (30 + smehenie); h++)					//exclusion of unreadable characters from the ASKII table module
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
				int smena = j - smehenie;									//shift by ASKII table (smehenie (default = 3))
				for (int h = 189; h < (189 + smehenie); h++)				//exclusion of unreadable characters from the ASKII table module
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
		outputstring += inputstring[i];                           //if there is no ASKII in the range -> copy them to the output array without modification
	}
	int n = outputstring.length();
	system("CLS");												//clear console
	cout << "Decoding string: ";									//output of encrypted text module
	for (int g = 0; g < n; g++)								
	{															
		cout << outputstring[g];								
	}															
	cout << endl;
}

void main()
{
	SetConsoleCP(1251);											//set ASKII by Windows console-in == console-out (for Кussian language)
	SetConsoleOutputCP(1251);									//

	setlocale(LC_ALL, "Rus");									//Russian localization



	string cryptotype;
	cout << "Encoding types:" << endl << "1)Caesar's Cipher" << endl << "2)" << endl << "3)" << endl << "4)" << endl << "5)" << endl << "What type you want: ";
	cin >> cryptotype;

	if (cryptotype != "1" && cryptotype != "2" && cryptotype != "3" && cryptotype != "4" && cryptotype != "5")
	{
		while (cryptotype != "1" && cryptotype != "2" && cryptotype != "3" && cryptotype != "4" && cryptotype != "5")
		{
			system("CLS");
			cout << "Error. Write \"1\" or \"2\" or \"3\" or \"4\" or \"5\" only." << endl;
			cout << "Encoding types:" << endl << "1)Caesar 's Cipher" << endl << "2)" << endl << "3)" << endl << "4)" << endl << "5)" << endl << "What type you want: ";
			cin >> cryptotype;
		}
	}
	system("CLS");

	funktypename(cryptotype);



	string funk;												//string to understand what to do with your string
	cout << "Code or Decode: ";									//
	cin >> funk;												//

	if (funk != "Code" && funk != "Decode")						//if you didn't write "Decode" or "Code"
	{
		while (funk != "Code" && funk != "Decode")
		{
			system("CLS");
			funktypename(cryptotype);
			cout << "Error. Write \"Code\" or \"Decode\" only." << endl;
			cout << "Code or Decode: ";
			cin >> funk;
		}
	}
	system("CLS");												//clear console

	if (cryptotype == "1")
	{
		int smehenie = 3;											//setting the offset for encoding (default = 3)
		if (funk == "Code")
		{
			CaesarCODE(smehenie);
		}

		else if (funk == "Decode")
		{
			CaesarDECODE(smehenie);
		}
	}
	else if (cryptotype == "2")
	{
		cout << "2)" << endl;
	}
	else if (cryptotype == "2")
	{
		cout << "3)" << endl;
	}
	else if (cryptotype == "2")
	{
		cout << "4)" << endl;
	}
	else if (cryptotype == "2")
	{
		cout << "5)" << endl;
	}
}