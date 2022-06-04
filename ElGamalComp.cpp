#include "ElGamalComp.h"

int deg(int a, int b, int n){// a^b mod n
	int tmp = a;
	int sum = tmp;
	for (int i = 1; i<b; i++){
		for (int j = 1; j<a; j++){
			sum += tmp;
			if (sum >= n){
				sum -= n;
			}
		}
		tmp = sum;
	}
	return tmp;
}

int mod(int a, int b, int n){// a*b mod n
	int sum = 0;

	for (int i = 0; i<b; i++){
		sum += a;

		if (sum >= n){
			sum -= n;
		}
	}

	return sum;
}
