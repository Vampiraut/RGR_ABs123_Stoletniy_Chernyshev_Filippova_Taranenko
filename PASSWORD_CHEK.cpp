#include "Header.h"

//Password verification function
void PASSWORD_CHEK()
{
	bool chek_password = false;
	while (chek_password == false)
	{
		string password;
		cout << "Enter password" << endl << ": ";
		getline(cin, password);
		if (password == "1337")
		{
			chek_password = true;
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