#include "Header.h"

//Private exponentiation calculation function
uint64_t privateExponSearch(uint64_t publicExpon, uint64_t eiler)
{
	for (uint64_t privateExpon = eiler - 1; privateExpon > 2; privateExpon--)
	{
		if (privateExpon == publicExpon)
		{
			continue;
		}
		else if (((privateExpon * publicExpon) % eiler) == 1)
		{
			return privateExpon;
		}
	}
	return -1;
}