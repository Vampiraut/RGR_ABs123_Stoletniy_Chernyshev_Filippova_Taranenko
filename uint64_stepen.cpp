#include "Header.h"

uint64_t stepen(uint64_t x, int y)
{
	uint64_t result = x;
	for (int i = 1; i < y; i++)
	{
		result = result * x;
	}
	return result;
}
