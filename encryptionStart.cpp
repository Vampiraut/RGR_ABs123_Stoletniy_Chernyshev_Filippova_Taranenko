#include "Header.h"

//Conditions for performing encryption for the selected type and principle of operation
void encryptionStart(int cryptoType, int funkType)
{
	if (cryptoType == 1)
	{
		if (funkType == 1)
		{
			CaesarCode();
		}

		else if (funkType == 2)
		{
			CaesarDecode();
		}
	}
	else if (cryptoType == 2)
	{
		if (funkType == 1)
		{
			GronsfeldCode();
		}
		else if (funkType == 2)
		{
			GronsfeldDecode();
		}
	}
	else if (cryptoType == 3)
	{
		cout << "3)" << endl;
	}
	else if (cryptoType == 4)
	{
		cout << "4)" << endl;
	}

	else if (cryptoType == 5)
	{
		cout << "5)" << endl;
	}

	/*
	switch (cryptoType)
	{
	case 1:
		switch (funkType)
		{
		case 1:
			Caesar_CODE();
		default:
			break;
		}
	default:
		break;
	}*/
}