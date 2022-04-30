#pragma once
#include <cstdint>

uint64_t privateExponSearch(uint64_t, uint64_t, uint64_t&);		//Private exponentiation calculation function (privateExpon * publicExpon = 1 + k * eiler) => (privateExpon = (1 + k * eiler)/publicExpon) must be in integer!!!