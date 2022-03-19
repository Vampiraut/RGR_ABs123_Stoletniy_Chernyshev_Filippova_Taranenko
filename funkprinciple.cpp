#include "Header.h"

//The function of writing the principle of action
void funkPrinciple(int funkType)
{
	switch (funkType)
	{
	case 1:
		cout << "Encryption" << endl;
		break;
	case 2:
		cout << "Decryption" << endl;
		break;
	}
}