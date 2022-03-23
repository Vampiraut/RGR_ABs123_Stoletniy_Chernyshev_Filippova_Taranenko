#include "Header.h"

//Decryption with the Gronsfeld cipher
void GronsfeldDecode(int codeCheck)
{
	if (codeCheck != 1)
	{
		string bufer = "";
		ifstream fout("Some_text.txt");//������ ���� � ����� �������
		ofstream promeg("Bufer.txt");  //������� ���� bufer.txt � �������� ���� ��� �����
		while (!fout.eof())
		{
			getline(fout, bufer);
			promeg << bufer;
			if (!fout.eof())
			{
				promeg << '\n';
			}
		}
		fout.close();
		promeg.close();

		string someKey = "";
		cout << "Enter the KEY" << endl << ":";
		getline(cin, someKey);

		ofstream fin("Some_text.txt");	 //������� ���� Some_text.txt ���� ������� ������������ ����, � ����� �������� �����
		ifstream promegCopy("bufer.txt");//������ ���� � ������ ������ ������
		fin << someKey << endl;
		while (!promegCopy.eof())
		{
			getline(promegCopy, bufer);
			fin << bufer;
			if (!promegCopy.eof())
			{
				fin << '\n';
			}
		}
		fin.close();
		promegCopy.close();

#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
	}
	string inputString = "";                                         //input string
	string outputString = "";										//output string
	bool isEnd = false;                                                   //che�k-flag for continue
	string key = "";

	string buferSec = "";

	ifstream fout1("Some_text.txt"); //������ ���� � ������ � ����� �������
	getline(fout1, key);
	while (!fout1.eof())
	{
		getline(fout1, buferSec);
		inputString = inputString + buferSec;
		if (!fout1.eof())
		{
			inputString = inputString + '\n';
		}
	}
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
	if (codeCheck == 1)
	{
		cout << "Your KEY: " << key << endl;
	}
	cout << "Decryption string: " << endl << outputString << endl;		//output of the decrypted string

	ofstream fin2("Str_aft_proc.txt");
	fin2 << key << endl;
	fin2 << outputString;
	fin2.close();

#ifndef Clear
	system("PAUSE");
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
}