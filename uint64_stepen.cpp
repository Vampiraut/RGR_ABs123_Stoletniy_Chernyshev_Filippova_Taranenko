#include "Header.h"

//8 byte unsigned int exponentiation function
uint64_t stepen(uint64_t x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	uint64_t result = x;
	for (int i = 1; i < y; i++)
	{
		result = result * x;
	}
	return result;
}
