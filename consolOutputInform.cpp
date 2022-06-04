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
	case Ciphers::ElGamal:
		cout << "ElGamal cipher" << endl;
		break;
	case Ciphers::Gibberish:
		cout << "Gibberish letter" << endl;
		break;
	case Ciphers::Atbash:
		cout << "Atbash Cipher" << endl;
		break;
	case Ciphers::SimpleTablePermutation:
		cout << "Simple Table Permutation Cipher" << endl;
		break;
	case Ciphers::Shamir:
		cout << "Shamir Cipher" << endl;
		break;
	case Ciphers::Vigener:
		cout << "Vigener Cipher" << endl;
		break;
	case Ciphers::Binary:
		cout << "Binary Cipher" << endl;
		break;
	case Ciphers::Hil:
		cout << "some" << endl;
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