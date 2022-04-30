#include "publicExponSearch.h"

//Public exponentiation calculation function
uint64_t publicExponSearch(uint64_t eiler, int memoryBit)
{
	uint64_t expon = 0;

	for (expon = (eiler / stepen(2, memoryBit + 5)) + 2; expon < eiler; expon++)
	{
		if (greatestCommonDivisor(expon, eiler) == 1)
		{
			return expon;
		}
	}
	return -1;
}
