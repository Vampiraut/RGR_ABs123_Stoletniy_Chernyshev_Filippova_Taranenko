#include "Header.h"

void input_str_to_txt()
{
	string inputing;
	cout << "Enter a line for encryption" << endl << ": ";
	getline(cin, inputing);
	ofstream fin("Inputstring.txt");
	fin << inputing;
	fin.close();
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
}