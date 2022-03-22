#include "Header.h"

//Public exponentiation calculation function
uint64_t publicExponSearch(uint64_t eiler)
{
	uint64_t expon = 0;;

	for (expon = eiler - 1; expon > 1; expon--)
	{
		if (greatestCommonDivisor(expon, eiler) == 1)
		{
			return expon;
		}
	}

	return -1;
}
