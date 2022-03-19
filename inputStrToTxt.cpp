#include "Header.h"

//Entering a string and saving it to a file
void inputStrToTxt()
{
	string inputStr;
	cout << "Enter a line for encryption" << endl << ": ";
	getline(cin, inputStr);
	ofstream fin("Inputstring.txt");
	fin << inputStr;
	fin.close();
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
}