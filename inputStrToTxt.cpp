#include "Header.h"

//Entering a string and saving it to a file or copying and encrypting your file
void inputStrToTxt()
{
	string fileCreate = "";
	cout << "Do you want to encrypt your file or create a new one?" << endl << "<1>Your file" << endl << "<2>A new file" << endl << ": ";
	getline(cin, fileCreate);
	while (fileCreate != "1" && fileCreate != "2")
	{
		system("CLS");
		cout << "Error. Write \"1\" or \"2\" only." << endl;
		cout << "Do you want to encrypt your file or create a new one?" << endl << "<1>Your file" << endl << "<2>A new file" << endl << ": ";
		getline(cin, fileCreate);
	}
	system("CLS");

	
	if (fileCreate == "1")
	{
		cout << "Enter the path to the file (remember, the file must be ANSI or Windows-1251 encoded)" << endl << ": ";
		string path = "";
		getline(cin, path);
		ofstream fin("Some_text.txt");
		ifstream fout(path);
		while (!fout.is_open())
		{
#ifndef Clear
			system("CLS");
#endif
#ifdef Clear
			cout << endl;
#endif
			cout << "Unknown file path!" << endl;
			cout << "Enter the path to the file (remember, the file must be ANSI or Windows-1251 encoded)" << endl << ": ";
			getline(cin, path);
			fout.open(path);
		}
		string bufer = "";
		while (!fout.eof())
		{
			getline(fout, bufer);
			fin << bufer;
			if (!fout.eof())
			{
				fin << endl;
			}
		}
		fin.close();
		fout.close();
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
	}
	else if (fileCreate == "2")
	{
		string inputStr = "";
		cout << "Enter a line for encryption" << endl << ": ";
		getline(cin, inputStr);
		while (inputStr == "")
		{
#ifndef Clear
			system("CLS");
#endif
#ifdef Clear
			cout << endl;
#endif
			cout << "An empty string has been entered!" << endl;
			cout << "Enter a line for encryption" << endl << ": ";
			getline(cin, inputStr);
		}
		ofstream fin("Some_text.txt");
		fin << inputStr;
		fin.close();
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
	}
}
