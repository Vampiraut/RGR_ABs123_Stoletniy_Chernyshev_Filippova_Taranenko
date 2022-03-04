#include "Header.h"

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
#ifndef clear
			system("CLS");
#endif
#ifdef clear
			cout << endl;
#endif
			cout << "Wrong password!" << endl;
			chek_password = PASSWORD_CHEK(chek_password);
		}


#ifndef clear
		system("CLS");
#endif
#ifdef clear
		cout << endl;
#endif
		cout << "Authorization success!";
		Sleep(500);
#ifndef clear
		system("CLS");
#endif
#ifdef clear
		cout << endl;
#endif


		//Saving a inputstring to a file
		string inputing;
		cout << "Enter a line for encryption" << endl << ": ";
		cin.ignore();
		getline(cin, inputing);
		ofstream fin("Inputstring.txt");
		fin << inputing;
		fin.close();


#ifndef clear
		system("CLS");
#endif
#ifdef clear
		cout << endl;
#endif


		//Choosing the principle of operation
		string funk;
		cout << "Choose the principle of operation: " << endl << "<1>Encryption" << endl << "<2>Decryption" << endl << ": ";
		cin >> funk;
		//Protection against incorrectly entered operating principle
		while (funk != "1" && funk != "2")
		{
#ifndef clear
			system("CLS");
#endif
#ifdef clear
			cout << endl;
#endif
			cout << "Error. Write \"1\" or \"2\" only." << endl;
			cout << "Choose the principle of operation: " << endl << "<1>Encryption" << endl << "<2>Decryption" << endl << ": ";
			cin >> funk;
		}


#ifndef clear
		system("CLS");
#endif
#ifdef clear
		cout << endl;
#endif
		funkprinciple(funk);


		//Encryption selection
		string cryptotype;
		cout << "Select the encryption/decryption type: " << endl << "<1>Caesar's Cipher" << endl << "<2>The Gronsfeld Cipher" << endl << "<3>" << endl << "<4>" << endl << "<5>" << endl << ": ";
		cin >> cryptotype;
		//Protection against an incorrectly entered encryption type
		while (cryptotype != "1" && cryptotype != "2" && cryptotype != "3" && cryptotype != "4" && cryptotype != "5")
		{
#ifndef clear
			system("CLS");
#endif
#ifdef clear
			cout << endl;
#endif
			funkprinciple(funk);
			cout << "Error. Write \"1\" or \"2\" or \"3\" or \"4\" or \"5\" only." << endl;
			cout << "Select the encryption/decryption type: " << endl << "<1>Caesar's Cipher" << endl << "<2>The Gronsfeld Cipher" << endl << "<3>" << endl << "<4>" << endl << "<5>" << endl << ": ";
			cin >> cryptotype;
		}


#ifndef clear
		system("CLS");
#endif
#ifdef clear
		cout << endl;
#endif
		funkprinciple(funk);
		funktypename(cryptotype);


		//Conditions for performing encryption for the selected type and principle of operation
		if (cryptotype == "1")
		{
			int smehenie = 5;
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
			string someKey;

			cout << "Enter the KEY" << endl << ":";
			cin.ignore();
			getline(cin, someKey);
			ofstream fin("SecretKEY.txt");
			fin << someKey;
			fin.close();

#ifndef clear
			system("CLS");
#endif
#ifdef clear
			cout << endl;
#endif

			if (funk == "1")
			{
				Gronsfeld_CODE();
			}
			else if (funk == "2")
			{
				Gronsfeld_DECODE();
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



		string code_chek;
		cout << "Do you want to check the encryption?" << endl << "<1>Yes" << endl << "<2>No" << endl << ":";
		cin >> code_chek;
		while (code_chek != "1" && code_chek != "2")
		{
#ifndef clear
			system("CLS");
#endif
#ifdef clear
			cout << endl;
#endif
			cout << "Error. Write \"1\" or \"2\" only." << endl;
			cout << "Do you want to check the encryption?" << endl << "<1>Yes" << endl << "<2>No" << endl << ":";
			cin >> code_chek;
		}
		if (code_chek == "1")
		{
			//Conditions for performing encryption for the selected type and principle of operation
			if (cryptotype == "1")
			{
				int smehenie = 5;	//Setting the offset for encoding (default = 5)
				if (funk == "2")
				{
					Caesar_CODE(smehenie);
				}

				else if (funk == "1")
				{
					Caesar_DECODE(smehenie);
				}
			}
			else if (cryptotype == "2")
			{
				string someKey;

				cout << "Enter the KEY" << endl << ":";
				cin.ignore();
				getline(cin, someKey);
				ofstream fin("SecretKEY.txt");
				fin << someKey;
				fin.close();

				if (funk == "2")
				{
					Gronsfeld_CODE();
				}
				else if (funk == "1")
				{
					Gronsfeld_DECODE();
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
		}

		else
		{
			system("PAUSE");
		}
		system("CLS");
	}
	return 0;
}