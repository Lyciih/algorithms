#include "stdio.h"
#include "string.h"


int cut(int first,int end, void * cut_table, int n_size)
{
	int cut_location = *((int *)cut_table + first * n_size + end);
	if(cut_location == 0)
	{
		printf("A%d",first);
		return 0;
	}
	printf("(");
	cut(first, cut_location, cut_table, n_size);
	cut(cut_location + 1, end, cut_table, n_size);
	printf(")");

	return 0;
}


int main()
{
	/*
	int a;
	test();
	a = binomial_coefficient_DAC(7,3);
	printf(" %d \n", a);
	a = binomial_coefficient_DP(7,3);
	printf(" %d \n", a);
	*/

	int between = 0;
	scanf("%d", &between);
	int matrix_number = between - 1;

	int size[between + 1];
	size[0] = matrix_number;
	for(int i = 1; i <= between; i++)
	{
		scanf("%d", &size[i]);
	}

	int search_first;
	scanf("%d", &search_first);

	int search_end;
	scanf("%d", &search_end);


	int count_table[matrix_number + 1][matrix_number + 1];
	int cut_table[matrix_number + 1][matrix_number + 1];
	memset(count_table, 0, sizeof(count_table));
	memset(cut_table, 0, sizeof(cut_table));



	//table 座標
	for(int j = 1; j<= 6; j++)
	{
		count_table[0][j] = j;
		cut_table[0][j] = j;
	}


	for(int i = 1; i<= 6; i++)
	{
		count_table[i][0] = i;
		cut_table[i][0] = i;
	}


	//運算順序
	//int l = 1;
	for(int i = 1; i <= matrix_number -1; i++)
	{
		for(int j = 1; j < matrix_number; j++)
		{
			if(j + i <= matrix_number)
			{
				for(int k = j; k < j + i; k++)
				{
					int temp = count_table[j][k] + count_table[k + 1][j + i] + size[j] * size[k + 1] * size[j + i + 1];
		
					//printf("[%d %d] [%d %d] %d %d %d\n", j,k,k+1,j+i,size[j],size[k+1],size[j+i+1]);
					if(k == j)
					{
						count_table[j][j + i] = temp;
						cut_table[j][j+i] = k;
					}
					else
					{
						if(temp < count_table[j][j + i])
						{
							count_table[j][j + i] = temp;
							cut_table[j][j+i] = k;
						}
					}
				}
				//printf("----------------------\n");
				//count_table[j][j + i] = l;
				//l++;
			}
			else
			{
				break;
			}
		}
	}


	//印出整個table
	/*
	for(int i = 0; i <= matrix_number; i++)
	{
		for(int j = 0; j <= matrix_number; j++)
		{
			printf("%5d ", count_table[i][j]);
		}
		printf("\n");
	}
	printf("-------------------\n");
	*/

	//印出整個table
	/*
	for(int i = 0; i <= matrix_number; i++)
	{
		for(int j = 0; j <= matrix_number; j++)
		{
			printf("%5d ", cut_table[i][j]);
		}
		printf("\n");
	}
	*/

	printf("%d\n", count_table[search_first][search_end]);
	cut(search_first, search_end, cut_table, matrix_number + 1);
	printf("\n");
}
