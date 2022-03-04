#include "Header.h"

//Password verification function
bool PASSWORD_CHEK(bool chek_password)
{
	string password;
	cout << "Enter password" << endl << ": ";
	cin >> password;
	if (password == "1337")
	{
		chek_password = true;
	}
	else
	{
		chek_password = false;
	}
	return chek_password;
}