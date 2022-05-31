#include "funkTypeName.h"

//The function of writing the encryption type
void funkTypeName(int cryptoType)
{
	switch (cryptoType)
	{
	case 1:
		cout << "The Gronsfeld Cipher" << endl;
		break;
	case 2:
		cout << "RSA Cipher" << endl;
		break;
	case 3:
		cout << "" << endl;
		break;
	case 4:
		cout << "Vernam Ñipher" << endl;
		break;
	case 5:
		cout << "" << endl;
		break;
	case 6:
		cout << "" << endl;
		break;
	case 7:
		cout << "" << endl;
		break;
	case 8:
		cout << "" << endl;
		break;
	case 9:
		cout << "" << endl;
		break;
	case 10:
		cout << "Simple Table Permutation Cipher" << endl;
		break;
	case 11:
		cout << "Atbash Cipher" << endl;
		break;
	case 12:
		cout << "" << endl;
		break;
	}
}