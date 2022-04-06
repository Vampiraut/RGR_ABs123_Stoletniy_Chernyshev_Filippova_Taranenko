#include "Header.h"

//The function of starting the encryption check
void encryptionCheck(int cryptoType, int funkType)
{
	cout << "Do you want to check the encryption?" << endl << "<1>Yes" << endl << "<2>No" << endl << ":";
	string codeCheck = "";
	getline(cin, codeCheck);
	while (codeCheck != "1" && codeCheck != "2")
	{
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
		cout << "Error. Write \"1\" or \"2\" only." << endl;
		cout << "Do you want to check the encryption?" << endl << "<1>Yes" << endl << "<2>No" << endl << ":";
		getline(cin, codeCheck);
	}
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
	if (codeCheck == "1")
	{
		string bufer = "";
		ofstream fin("Some_text.txt");   //if - ÷òåíèå, of - çàïèñü
		ifstream fout("Str_aft_proc.txt");
		while (!fout.eof())
		{
			getline(fout, bufer);
			fin << bufer;
			if (!fout.eof())
			{
				fin << '\n';
			}
		}
		fin.close();
		fout.close();

		passwordCheñk();
		//Conditions for performing encryption for the selected type and principle of operation
		switch (cryptoType)
		{
		case 1:
			switch (funkType)
			{
			case 1:
				GronsfeldDecode(1);
				break;
			case 2:
				GronsfeldCode(1);
				break;
			}
			break;
		case 2:
			switch (funkType)
			{
			case 1:
				RSADecode();
				break;
			case 2:
				RSACode();
				break;
			}
			break;
		case 3:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 4:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 5:
			switch (funkType)
			{
			case 1:
				
				break;
			case 2:
				
				break;
			}
			break;
		case 6:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 7:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 8:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 9:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 10:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 11:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		case 12:
			switch (funkType)
			{
			case 1:

				break;
			case 2:

				break;
			}
			break;
		}
	}
#ifdef Clear
	system("PAUSE");
#endif
	system("CLS");
}