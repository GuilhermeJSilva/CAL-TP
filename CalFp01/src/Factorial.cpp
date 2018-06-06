/*
 * Factorial.cpp
 */

#include "Factorial.h"

int factorialRecurs(int n)
{
	if(n == 1 || n == 0)
		return 1;
	else
		return n*factorialRecurs(n - 1);

}

int factorialDinam(int n)
{
	static int fact[5000];
	fact[0] = 1;
	fact[1] = 1;
	int res = 1;
	for (int i = 2; i <= n; ++i) {
		if(fact[i] != 0)
			res = fact[i];
		else
			res = fact[i] = i * fact[i-1];
	}
	return res;
}
