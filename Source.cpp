#include "Header.h"

//Main funk
int main()
{
	srand(time(0));
	SetConsoleCP(1251);			//set ASKII by Windows console-in == console-out (for Russian language)
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");	//Russian localization

	passwordCheñk();

	int funkType = 0;
	int cryptoType = 0;
	while (true)
	{
		inputStrToTxt();

		funkType = principleOfOperation();
		cryptoType = cryptoTypeSelect(funkType);

		encryptionStart(cryptoType, funkType);

		encryptionCheck(cryptoType, funkType);
	}
	return 0;
}