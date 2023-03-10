#include "algorithms.h"


void test()
{
	printf("123\n");
}



int minimun(int a, int b)
{
	if(a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}


int binomial_coefficient_DAC(int n, int k)
{
	if(k == 0 || n == k)
		return 1;
	else
		return binomial_coefficient_DAC(n-1,k-1) + binomial_coefficient_DAC(n-1,k);
}



int binomial_coefficient_DP(int n, int k)
{
	int i, j;
	int B[n+1][k+1];
	memset(B, 0, sizeof(B));

	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= minimun(i,k) ; j++)
		{
			if(j == 0 || j == i)
			{
				B[i][j] = 1;
			}
			else
			{
				B[i][j] = B[i-1][j-1] + B[i-1][j];
			}
		}
	}
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= k; j++)
		{
			printf("%3d ",B[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return B[n][k];
}


