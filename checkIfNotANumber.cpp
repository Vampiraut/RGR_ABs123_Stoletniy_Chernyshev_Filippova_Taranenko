#include "Header.h"

//The function of checking whether the entered string is a number
bool checkIfNotANumber(string intInStr)
{
	if (intInStr == "")   //chek for empety string
	{
		return false;
	}
	for (int i = 0; intInStr[i] != '\0'; i++)  //chek for not a number
	{
		char askii = 0;
		for (int j = 48; j < 58; j++)
		{
			askii = j;
			if (intInStr[i] != askii && j == 57)
			{
				return false;
			}
			else if (intInStr[i] == askii)
			{
				break;
			}
		}
	}
	return true;
}