#include "algorithms.h"


int main()
{
	int a;
	test();
	a = binomial_coefficient_DAC(7,3);
	printf(" %d \n", a);
	a = binomial_coefficient_DP(7,3);
	printf(" %d \n", a);
}
