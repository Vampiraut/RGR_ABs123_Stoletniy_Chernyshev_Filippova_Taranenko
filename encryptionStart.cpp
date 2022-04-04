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
			GronsfeldCode(0);
			break;
		case 2:
			GronsfeldDecode(0);
			break;
		}
		break;
	case 2:
		switch (funkType)
		{
		case 1:
			RSAKeyGeneration(0);
			RSACode();
			break;
		case 2:
			RSAKeyGeneration(1);
			RSADecode();
			break;
		}
		break;
	case 3:
		switch (funkType)
		{
		case 1:
			
			break;
		case 2:
			
			break;
		}
		break;
	case 4:
		switch (funkType)
		{
		case 1:
			
			break;
		case 2:
			
			break;
		}
		break;
	case 5:
		switch (funkType)
		{
		case 1:
			
			break;
		case 2:

			break;
		}
		break;
	case 6:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

			break;
		}
		break;
	case 7:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

			break;
		}
		break;
	case 8:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

			break;
		}
		break;
	case 9:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

			break;
		}
		break;
	case 10:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

			break;
		}
		break;
	case 11:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

			break;
		}
		break;
	case 12:
		switch (funkType)
		{
		case 1:

			break;
		case 2:

			break;
		}
		break;
	}
}