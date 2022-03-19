#include "Header.h"

//The function of writing the encryption type
void funkTypeName(int cryptoType)
{
	if (cryptoType == 1)
	{
		cout << "Caesar's Cipher" << endl;
	}
	else if (cryptoType == 2)
	{
		cout << "The Gronsfeld Cipher" << endl;
	}
	else if (cryptoType == 3)
	{
		cout << "" << endl;
	}
	else if (cryptoType == 4)
	{
		cout << "" << endl;
	}
	else if (cryptoType == 5)
	{
		cout << "RSA Cipher" << endl;
	}
}