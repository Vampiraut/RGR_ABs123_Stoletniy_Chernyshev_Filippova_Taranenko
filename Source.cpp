#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include <windows.h>
#include <ctime>

using namespace std;

void funktypename(string cryptotype)				//the function of writing the encryption type
{
	if (cryptotype == "1")
	{
		cout << "1)Caesar's Cipher" << endl;
	}
	else if (cryptotype == "2")
	{
		cout << "2)" << endl;
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

void Caesar_CODE(int* password_array)
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
void Caesar_DECODE(int* password_array)
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

int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);								//set ASKII by Windows console-in == console-out (for Кussian language)
	SetConsoleOutputCP(1251);						
	setlocale(LC_ALL, "Rus");						//Russian localization

	string cryptotype;								//encryption selection
	cout << "Encoding types:" << endl << "1)Caesar's Cipher" << endl << "2)" << endl << "3)" << endl << "4)" << endl << "5)" << endl << "What type you want: ";
	cin >> cryptotype;

	if (cryptotype != "1" && cryptotype != "2" && cryptotype != "3" && cryptotype != "4" && cryptotype != "5")	//protection against an incorrectly entered encryption type
	{
		while (cryptotype != "1" && cryptotype != "2" && cryptotype != "3" && cryptotype != "4" && cryptotype != "5")
		{
			system("CLS");
			cout << "Error. Write \"1\" or \"2\" or \"3\" or \"4\" or \"5\" only." << endl;
			cout << "Encoding types:" << endl << "1)Caesar's Cipher" << endl << "2)" << endl << "3)" << endl << "4)" << endl << "5)" << endl << "What type you want: ";
			cin >> cryptotype;
		}
	}

	system("CLS");
	funktypename(cryptotype);

	string funk;									//сhoosing the principle of operation
	cout << "Code or Decode: ";
	cin >> funk;

	if (funk != "Code" && funk != "Decode")																		//Protection against an incorrectly entered principle of operation
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

	system("CLS");
	funktypename(cryptotype);

	if (cryptotype == "1")							//conditions for performing encryption for the selected type and principle of operation
	{
		int password_array[30];
		int* pass = password_array;
		int flag_password[1] = { 1 };
		int* flag_pas = flag_password;
		PASSWORD_request(pass, flag_pas);
		if (flag_password[0] == 0)
		{
			while (flag_password[0] == 0)
			{
				PASSWORD_request(pass, flag_pas);
			}
		}
		system("CLS");
		cout << "Your password is: ";
		for (int i = 0; i < 30; i++)
		{
			cout << password_array[i];
		}
		cout << endl;
		if (funk == "Code")
		{
			Caesar_CODE(pass);
		}

		else if (funk == "Decode")
		{
			Caesar_DECODE(pass);
		}
	}
	else if (cryptotype == "2")
	{
		cout << "2)" << endl;
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
	return 0;
}