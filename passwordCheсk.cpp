#include "passwordCheñk.h"

//Password verification function
void passwordCheñk()
{
	string password = "";
	cout << "Enter password" << endl << ": ";
	getline(cin, password);
	while (password != PASSWORD)
	{
#ifndef Clear
		system("CLS");
#endif
#ifdef Clear
		cout << endl;
#endif
		cout << "Wrong password!" << endl << "Enter password" << endl << ": ";
		getline(cin, password);
	}
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
	cout << "Authorization success!" << endl;;
	Sleep(500);
#ifndef Clear
	system("CLS");
#endif
#ifdef Clear
	cout << endl;
#endif
}