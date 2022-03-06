#include "Header.h"

//Main funk
int main()
{
	SetConsoleCP(1251);			//set ASKII by Windows console-in == console-out (for Кussian language)
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");	//Russian localization

	int funk = 0;
	int cryptotype = 0;

	PASSWORD_CHEK();

	while (true)
	{
		input_str_to_txt();

		funk = principle_of_operation();
		cryptotype = crypto_type_select(funk);

		start_encryption(cryptotype, funk);

		encryption_chek(cryptotype, funk);
	}
	return 0;
}