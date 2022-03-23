#include "Header.h"

//Entering a string and saving it to a file ùr copying and encrypting your file
void inputStrToTxt()
{
	string fileCreate = "";
	cout << "Do you want to encrypt your file or create a new one?" << endl << "<1>Your file" << endl << "<2>A new file" << endl << ": ";
	getline(cin, fileCreate);
	while (fileCreate != "1" && fileCreate != "2")
	{
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
		cout << "Error. Write \"1\" or \"2\" only." << endl;
		cout << "Do you want to encrypt your file or create a new one?" << endl << "<1>Your file" << endl << "<2>A new file" << endl << ": ";
		getline(cin, fileCreate);
	}
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
	if (fileCreate == "1")
	{
		cout << "Enter the path to the file" << endl << ": ";
		string path = "";
		getline(cin, path);
		string bufer = "";
		ofstream fin("Some_text.txt");
		ifstream fout;
		fout.open(path);
		while (!fout.is_open())
		{
#ifndef Clear
			system("CLS");
#endif
#ifdef Clear
			cout << endl;
#endif
			cout << "Unknown file path!" << endl;
			cout << "Enter the path to the file" << endl << ": ";
			getline(cin, path);
			fout.open(path);
		}
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
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
	}
	else if (fileCreate == "2")
	{
		string inputStr;
		cout << "Enter a line for encryption" << endl << ": ";
		getline(cin, inputStr);
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