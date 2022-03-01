#include <iostream>
#include <cstdlib>

#include <string>
#include <locale>
#include <windows.h>

using namespace std;

//System funk
bool PASSWORD_CHEK(bool chek_password)		//the function for password chek
{
	string password;
	cout << "Enter password: ";
	cin >> password;
	if (password == "1337")
	{
		chek_password = true;
	}
	else
	{
		chek_password = false;
	}
	return chek_password;
}


void funktypename(string cryptotype)		//the function of writing the encryption type
{
	if (cryptotype == "1")
	{
		cout << "Caesar's Cipher" << endl;
	}
	else if (cryptotype == "2")
	{
		cout << "The Gronsfeld Cipher" << endl;
	}
	else if (cryptotype == "3")
	{
		cout << "" << endl;
	}
	else if (cryptotype == "4")
	{
		cout << "" << endl;
	}
	else if (cryptotype == "5")
	{
		cout << "" << endl;
	}
}
void funkprinciple(string funk)				//the function of writing the principle of operation
{
	if (funk == "1")
	{
		cout << "Encryption" << endl;
	}
	else if (funk == "2")
	{
		cout << "Decryption" << endl;
	}
}	   


//Code and Decode funk
void Caesar_CODE(int smehenie)
{
	string inputstring;                                         //input string
	string outputstring;										//output string
	bool end;                                                   //cheсk-flag for continue

	cout << "Enter a line for encryption: ";                            //enter input string
	cin.ignore();
	getline(cin, inputstring);

	for (int i = 0; inputstring[i] != '\0'; i++)                //input string check
	{
		end = false;												//set check-flag to false
		for (int j = 33; j < 127; j++)								//ASKII 33 -> 126 check in input string
		{
			char ASCIICod = j;											//int-dek to ASKII-symbol															
			if (inputstring[i] == ASCIICod)								//comparison of the symbol of the input string and the ASKII character
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
				int smena = j + smehenie;									//shift by ASKII table (smehenie (defalt = 5))
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
		outputstring += inputstring[i];								//if there is no ASKII in the range -> copy them to the output array without modification
	}

	int n = outputstring.length();								//output string lenght

	system("CLS");
	funktypename("1");

	cout << "Encrypted string: ";									//output of encrypted string
	for (int g = 0; g < n; g++)
	{
		cout << outputstring[g];
	}
	cout << endl;
}
void Caesar_DECODE(int smehenie)
{
	string inputstring;                                         //input string
	string outputstring;										//output string
	bool end;                                                   //cheсk-flag for continue

	cout << "Enter a line for decryption: ";                          //enter input string
	cin.ignore();
	getline(cin, inputstring);

	for (int i = 0; inputstring[i] != '\0'; i++)                //input string check
	{
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
	int n = outputstring.length();								//output string lenght

	system("CLS");
	funktypename("1");

	cout << "Decryption string: ";								//output of the decrypted string
	for (int g = 0; g < n; g++)
	{
		cout << outputstring[g];
	}
	cout << endl;
}


//Main funk
int main()
{
	SetConsoleCP(1251);			//set ASKII by Windows console-in == console-out (for Кussian language)
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");	//Russian localization


	while (true)
	{
		//Entering the password and checking it for correctness
		bool chek_password = true;
		chek_password = PASSWORD_CHEK(chek_password);
		while (chek_password == false)
		{
			system("CLS");
			cout << "Wrong password!" << endl;
			chek_password = PASSWORD_CHEK(chek_password);
		}


		system("CLS");
		cout << "Authorization success!";
		Sleep(1000);
		system("CLS");


		//Choosing the principle of operation
		string funk;
		cout << "Choose the principle of operation: " << endl << "<1>Encryption" << endl << "<2>Decryption" << endl << ": ";
		cin >> funk;
		//Protection against incorrectly entered operating principle
		while (funk != "1" && funk != "2")
		{
			system("CLS");
			cout << "Error. Write \"1\" or \"2\" only." << endl;
			cout << "Choose the principle of operation: " << endl << "<1>Encryption" << endl << "<2>Decryption" << endl << ": ";
			cin >> funk;
		}


		system("CLS");
		funkprinciple(funk);


		//Encryption selection
		string cryptotype;
		cout << "Select the encryption/decryption type : " << endl << "<1>Caesar's Cipher" << endl << "<2>The Gronsfeld Cipher" << endl << "<3>" << endl << "<4>" << endl << "<5>" << endl << ": ";
		cin >> cryptotype;
		//Protection against an incorrectly entered encryption type
		while (cryptotype != "1" && cryptotype != "2" && cryptotype != "3" && cryptotype != "4" && cryptotype != "5")
		{
			system("CLS");
			funkprinciple(funk);
			cout << "Error. Write \"1\" or \"2\" or \"3\" or \"4\" or \"5\" only." << endl;
			cout << "Select the encryption/decryption type : " << endl << "<1>Caesar's Cipher" << endl << "<2>The Gronsfeld Cipher" << endl << "<3>" << endl << "<4>" << endl << "<5>" << endl << ": ";
			cin >> cryptotype;
		}


		system("CLS");
		funkprinciple(funk);
		funktypename(cryptotype);


		//Conditions for performing encryption for the selected type and principle of operation
		if (cryptotype == "1")
		{
			int smehenie = 5;	//Setting the offset for encoding (default = 5)
			if (funk == "1")
			{
				Caesar_CODE(smehenie);
			}

			else if (funk == "2")
			{
				Caesar_DECODE(smehenie);
			}
		}
		else if (cryptotype == "2")
		{
			int smehenie = 5;	//Setting the offset for encoding (default = 5)
			if (funk == "1")
			{
				Caesar_CODE(smehenie);
			}
			else if (funk == "2")
			{
				Caesar_DECODE(smehenie);
			}
		}
		else if (cryptotype == "3")
		{
			cout << "3)" << endl;
		}
		else if (cryptotype == "4")
		{
			cout << "4)" << endl;
		}
		else if (cryptotype == "5")
		{
			cout << "5)" << endl;
		}
		system("PAUSE");
		system("CLS");
	}
	return 0;
}