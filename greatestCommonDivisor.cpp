#include "greatestCommonDivisor.h"

//Greatest common divisor search function
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
