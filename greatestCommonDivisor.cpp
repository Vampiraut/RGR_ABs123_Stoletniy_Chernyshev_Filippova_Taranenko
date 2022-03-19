#include "Header.h"

uint64_t greatestCommonDivisor(uint64_t expon, uint64_t eiler)
{
	while (expon > 0)
	{
		uint64_t promeg;

		promeg = expon;
		expon = eiler % expon;
		eiler = promeg;
	}

	return eiler;
}
