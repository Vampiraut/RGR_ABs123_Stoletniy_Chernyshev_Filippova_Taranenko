#include "Header.h"

//Conditions for performing encryption for the selected type and principle of operation
void encryptionStart(int cryptoType, int funkType)
{
	switch (cryptoType)
	{
	case 1:
		switch (funkType)
		{
		case 1:
			CaesarCode();
			break;
		case 2:
			CaesarDecode();
			break;
		}

	case 2:
		switch (funkType)
		{
		case 1:
			GronsfeldCode();
			break;
		case 2:
			GronsfeldDecode();
			break;
		}

	case 3:
		switch (funkType)
		{
		case 1:
			
			break;
		case 2:
			
			break;
		}

	case 4:
		switch (funkType)
		{
		case 1:
			
			break;
		case 2:
			
			break;
		}

	case 5:
		switch (funkType)
		{
		case 1:
			RSAKeyGeneration();
			RSACode();
			break;
		case 2:
			
			break;
		}
	}
}