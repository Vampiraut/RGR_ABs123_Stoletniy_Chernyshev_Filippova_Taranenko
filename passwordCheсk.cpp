#include "Header.h"

//Password verification function
void passwordCheÒk()
{
	bool is—orrect = false;
	while (is—orrect == false)
	{
		string password;
		cout << "Enter password" << endl << ": ";
		getline(cin, password);
		if (password == "1337")
		{
			is—orrect = true;
		}
		else
		{
#ifndef Clear
			system("CLS");
#endif
#ifdef Clear
			cout << endl;
#endif
			cout << "Wrong password!" << endl;
		}
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