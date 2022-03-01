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

void PASSWORD_request(int* password_array, int* flag_password)
{
	string password;
	flag_password[0] = 1;
	cout << "Enter password (if you don't have password -> write \"0\"): ";
	cin >> password;
	if (password == "0")
	{
		for (int i = 0; i < 30; i++)
		{
			int random_number = 1 + rand() % 9;
			password_array[i] = random_number;
		}
	}
	else
	{
		int i;
		for (i = 0; password[i] != '\0'; i++)
		{
			if (flag_password[0] == 0)
			{
				break;
			}
			if (i == 30)
			{
				system("CLS");
				cout << "Wrong password!" << endl;
				flag_password[0] = 0;
				break;
			}
			for (int j = 49; j < 58; j++)
			{
				char ASKII = j;
				if (password[i] == ASKII)
				{
					password_array[i] = j - 48;
					break;
				}
				else if (password[i] != ASKII && j == 57)
				{
					system("CLS");
					cout << "Wrong password!" << endl;
					flag_password[0] = 0;
					break;
				}
			}
		}
		if (i != 30 && flag_password[0] != 0)
		{
			system("CLS");
			cout << "Wrong password!" << endl;
			flag_password[0] = 0;
		}
	}
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
				int smena = j - smehenie;									//shift by ASKII table (smehenie (default = 3))

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
				int smena = j - smehenie;									//shift by ASKII table (smehenie (default = 3))
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

void Gronsfeld_CODE(int* password_array)
{
	string inputstring;                                         //input string
	string outputstring;										//output string
	bool end;                                                   //cheсk-flag for continue

	cout << "Enter coding string: ";                            //enter input string
	cin.ignore();
	getline(cin, inputstring);

	int p = -1;
	int smehenie = 0;

	for (int i = 0; inputstring[i] != '\0'; i++)                //input string check
	{

		p++;
		if (p == 29)
		{
			p = 0;
		}
		smehenie = password_array[p];

		end = false;												//set check-flag to false
		for (int j = 33; j < 127; j++)								//ASKII 33 -> 126 check in input string
		{
			char ASCIICod = j;											//int-dek to ASKII-symbol															
			if (inputstring[i] == ASCIICod)								//comparison of the symbol of the input string and the ASKII character
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
		outputstring += inputstring[i];								//if there is no ASKII in the range -> copy them to the output array without modification
	}

	int n = outputstring.length();								//output string lenght

	system("CLS");
	funktypename("1");

	cout << "Coding string: ";									//output of encrypted string
	for (int g = 0; g < n; g++)
	{
		cout << outputstring[g];
	}
	cout << endl;
}
void Gronsfeld_DECODE(int* password_array)
{
	string inputstring;                                         //input string
	string outputstring;										//output string
	bool end;                                                   //cheсk-flag for continue

	cout << "Enter decoding string: ";                          //enter input string
	cin.ignore();
	getline(cin, inputstring);

	int p = -1;
	int smehenie = 0;

	for (int i = 0; inputstring[i] != '\0'; i++)                //input string check
	{
		p++;
		if (p == 29)
		{
			p = 0;
		}
		smehenie = password_array[p];
		end = false;												//set check-flag to false
		for (int j = 33; j < 127; j++)								//ASKII 33 -> 126 check in input string
		{
			char ASCIICod = j;											//int-dek to ASKII-symbol														
			if (inputstring[i] == ASCIICod)								//comparison of the symbol of the input string and the ASKII character
			{
				int smena = j - smehenie;									//shift by ASKII table (smehenie (default = 3))

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
				int smena = j - smehenie;									//shift by ASKII table (smehenie (default = 3))
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

	cout << "Decoding string: ";								//output of the decrypted string
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


	//Greeting
	cout << "Hello Anonymous!" << endl << "Welcome to the encryption program!" << endl << "First you need to log in." << "\n\n";

	while (true)
	{
		//Entering the password and checking it for correctness
		bool chek_password = true;
		chek_password = PASSWORD_CHEK(chek_password);
		while (chek_password == false)
		{
			system("CLS");
			cout << "Wrong password!" << "\n\n";
			chek_password = PASSWORD_CHEK(chek_password);
		}
		system("CLS");
		cout << "Authorization success!";
		Sleep(1000);
		system("CLS");

		for (int q = 0; q < 10; q++)
		{
			//Choosing the principle of operation
			string funk;
			cout << "Choose the principle of operation: " << "\n\n" << "1)Encryption" << endl << "2)Decryption" << "\n\n" << "What we do: ";
			cin >> funk;
			//Protection against incorrectly entered operating principle
			while (funk != "1" && funk != "2")
			{
				system("CLS");
				cout << "Error. Write \"1\" or \"2\" only." << endl;
				cout << "Choose the principle of operation: " << "\n\n" << "1)Encryption" << endl << "2)Decryption" << "\n\n" << "What we do: ";
				cin >> funk;
			}

			system("CLS");
			funkprinciple(funk);


			//Encryption selection
			string cryptotype;
			cout << "Select the encryption/decryption type: " << "\n\n" << "1)Caesar's Cipher" << endl << "2)The Gronsfeld Cipher" << endl << "3)" << endl << "4)" << endl << "5)" << "\n\n" << "What type you want: ";
			cin >> cryptotype;
			//Protection against an incorrectly entered encryption type
			while (cryptotype != "1" && cryptotype != "2" && cryptotype != "3" && cryptotype != "4" && cryptotype != "5")
			{
				system("CLS");
				funkprinciple(funk);
				cout << "Error. Write \"1\" or \"2\" or \"3\" or \"4\" or \"5\" only." << endl;
				cout << "Select the encryption type: " << "\n\n" << "1)Caesar's Cipher" << endl << "2)The Gronsfeld Cipher" << endl << "3)" << endl << "4)" << endl << "5)" << "\n\n" << "What type you want: ";
				cin >> cryptotype;
			}

			system("CLS");
			funkprinciple(funk);
			funktypename(cryptotype);


			//Conditions for performing encryption for the selected type and principle of operation
			if (cryptotype == "1")
			{
				int smehenie = 5;	//Setting the offset for encoding (default = 3)
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
				int smehenie = 5;	//Setting the offset for encoding (default = 3)
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
		cout << "Login time-out!" << endl;
	}
	return 0;
}