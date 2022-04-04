#include "Header.h"

//Private exponentiation calculation function (privateExpon * publicExpon = 1 + k * eiler) => (privateExpon = (1 + k * eiler)/publicExpon) must be in integer!!!
uint64_t privateExponSearch(uint64_t publicExpon, uint64_t eiler, uint64_t& k)
{
    while (true)
    {
        k = k + eiler;   //k - is a number initially equal to 1, to which we add the Euler function, i.e. we add it (k) times until, when dividing by a public exponent, we get a division without remainder.
        if (k % publicExpon == 0)
        {
            return (k / publicExpon);
        }
    }
}