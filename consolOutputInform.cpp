#include "consolOutputInform.h"

//The function of writing the encryption type
void funkTypeName(int cryptoType)
{
	switch (Ciphers(cryptoType))
	{
	case Ciphers::Gronsfeld:
		cout << "Gronsfeld Cipher" << endl;
		break;
	case Ciphers::RSA:
		cout << "RSA Cipher" << endl;
		break;
	case Ciphers::Morse:
		cout << "Morse Cipher" << endl;
		break;
	case Ciphers::Vernam:
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
	case Ciphers::Vigener:
		cout << "Vigener Cipher" << endl;
		break;
	case Ciphers::Binary:
		cout << "Binary Cipher" << endl;
		break;
	case Ciphers::Gibberish:
		cout << "Gibberish letter" << endl;
		break;
	}
}

//The function of writing the principle of action
void funkPrinciple(int funkType)
{
	switch (Principle(funkType))
	{
	case Principle::Encription:
		cout << "Encryption" << endl;
		break;
	case Principle::Decription:
		cout << "Decryption" << endl;
		break;
	}
}