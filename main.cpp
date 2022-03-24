#include "Header.h"

//Main funk
int main()
{
	srand(time(0));
	SetConsoleCP(1251);			//installing the win-cp 1251 code page in the input stream
	SetConsoleOutputCP(1251);	//installing the win-cp 1251 code page in the output stream
	setlocale(LC_ALL, "Rus");
	for (int i = 153; i < 256; i++)
	{
		char a = i;
		cout << a << "     " << i << endl;
	}
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