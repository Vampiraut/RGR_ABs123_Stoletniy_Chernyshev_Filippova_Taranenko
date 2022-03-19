#include "Header.h"

uint64_t privateExponSearch(uint64_t publicExpon, uint64_t eiler)
{
	for (uint64_t i = eiler; i > publicExpon; i--)
	{
		if ((i * publicExpon) % eiler == 1)
		{
			return i;
		}
	}
	return -1;
}
