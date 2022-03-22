#include "Header.h"

//The function of writing the encryption type
void funkTypeName(int cryptoType)
{
	switch (cryptoType)
	{
	case 1:
		cout << "Caesar's Cipher" << endl;
		break;
	case 2:
		cout << "The Gronsfeld Cipher" << endl;
		break;
	case 3:
		cout << "The Atbash Ñipher" << endl;
		break;
	case 4:
		cout << "" << endl;
		break;
	case 5:
		cout << "RSA Cipher" << endl;
		break;
	}
}