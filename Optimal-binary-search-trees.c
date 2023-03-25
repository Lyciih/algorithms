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
	//int key = 5;
	int key = 7;
	//scanf("%d", &between);
	/*
	float p[key + 1];
	p[0] = 0;
	p[1] = 0.15;
	p[2] = 0.10;
	p[3] = 0.05;
	p[4] = 0.10;
	p[5] = 0.20;
*/

	float p[key + 1];
	p[0] = 0;
	p[1] = 0.04;
	p[2] = 0.06;
	p[3] = 0.08;
	p[4] = 0.02;
	p[5] = 0.10;
	p[6] = 0.12;
	p[7] = 0.14;
	/*
	for(int i = 1; i <= between; i++)
	{
		scanf("%d", &size[i]);
	}
	*/

	/*
	float q[key + 1];
	q[0] = 0.05;
	q[1] = 0.10;
	q[2] = 0.05;
	q[3] = 0.05;
	q[4] = 0.05;
	q[5] = 0.10;
	*/

	float q[key + 1];
	q[0] = 0.06;
	q[1] = 0.06;
	q[2] = 0.06;
	q[3] = 0.06;
	q[4] = 0.05;
	q[5] = 0.05;
	q[6] = 0.05;
	q[7] = 0.05;

	float w_table[key + 2][key + 2];
	float e_table[key + 2][key + 2];
	int r_table[key + 2][key + 2];
	memset(w_table, 0, sizeof(w_table));
	memset(e_table, 0, sizeof(e_table));
	memset(r_table, 0, sizeof(r_table));



	//table 座標
	
	for(int j = 1; j <= key + 1; j++)
	{
		w_table[0][j] = j;
		e_table[0][j] = j;
		r_table[0][j] = j;
	}


	for(int i = 1; i <= key + 1; i++)
	{
		w_table[i][0] = key + 1 - i;
		e_table[i][0] = key + 1 - i;
		r_table[i][0] = key + 1 - i;
	}
	

	for(int i = 1; i <= key + 1; i++)
	{
		w_table[key + 2 - i][i] = q[i - 1];
		e_table[key + 2 - i][i] = q[i - 1];
	}


	printf("\nrun w table\n\n");
	for(int k = 1; k > 1 - key; k--)
	{
		for(int i = 1; i <= key; i++)
		{
			if(key + k - i <= 0)
			{
				break;
			}
			else
			{
				printf("[%d,%d]  ",i, i + 1 - k);
				printf("%.2f + %.2f + %.2f",w_table[key + k - i + 1][i], p[i + 1 - k], q[i + 1 - k]);
				w_table[key + k - i][i] = w_table[key + k - i + 1][i] + p[i + 1 - k] + q[i + 1 - k];
				printf(" = %.2f\n", w_table[key + k - i][i]);
			}
		}
		printf("---------------------------------\n");
	}


	printf("\nrun e table\n\n");
	
	for(int k = 1; k > 1 - key; k--)
	{
		for(int i = 1; i <= key; i++)
		{
			if(key + k - i <= 0)
			{
				break;
			}
			else
			{
				printf("[%d,%d]\n",i, i + 1 - k);
				for(int j = i; j <= i + 1 - k; j++)
				{
					float temp = e_table[key - j + 2][i] + e_table[key + k - i][j + 1] + w_table[key + k - i][i];
					printf("root = %d   %.2f + %.2f + %.2f = %.2f\n",j ,e_table[key - j + 2][i], e_table[key + k - i][j + 1], w_table[key + k - i][i], temp);
					if(j == i)
					{
						e_table[key + k - i][i] = temp;
						r_table[key + k - i][i] = j;
					}
					else
					{
						if(temp < e_table[key + k - i][i])
						{
							e_table[key + k - i][i] = temp;
							r_table[key + k - i][i] = j;
						}
					}
				}
				printf("-------------------------\n");
			}
		}
	}




	//印出整個table
	for(int i = 0; i <= key + 1; i++)
	{
		for(int j = 0; j <= key + 1; j++)
		{
			if(i != 0 && j != 0)
			{
				if(w_table[i][j] != 0)
				{
					printf("%.2f ", w_table[i][j]);
				}
			}
			else
			{
				if(i == 0 && j == 0)
				{
					printf("w  ");
				}
				else if(i == 0)
				{
					printf("%d    ", j);
				}
				else if(j == 0)
				{
					printf("%d  ", key + 1 - i);
				}
			}
		}
		printf("\n");
	}
	printf("-------------------\n");

	//印出整個table
	for(int i = 0; i <= key + 1; i++)
	{
		for(int j = 0; j <= key + 1; j++)
		{
			if(i != 0 && j != 0)
			{
				if(e_table[i][j] != 0)
				{
					printf("%.2f ", e_table[i][j]);
				}
			}
			else
			{
				if(i == 0 && j == 0)
				{
					printf("e  ");
				}
				else if(i == 0)
				{
					printf("%d    ", j);
				}
				else if(j == 0)
				{
					printf("%d  ", key + 1 - i);
				}
			}
		}
		printf("\n");
	}

	printf("-------------------\n");
	//印出整個table
	for(int i = 0; i <= key ; i++)
	{
		for(int j = 0; j <= key ; j++)
		{
			if(i != 0 && j != 0)
			{
				if(r_table[i][j] != 0)
				{
					printf("%d  ", r_table[i][j]);
				}
			}
			else
			{
				if(i == 0 && j == 0)
				{
					printf("root  ");
				}
				else if(i == 0)
				{
					printf("%d  ", j);
				}
				else if(j == 0)
				{
					printf("%d     ", key + 1 - i);
				}
			}
		}
		printf("\n");
	}
	//printf("%d\n", count_table[search_first][search_end]);
	//cut(search_first, search_end, cut_table, matrix_number + 1);
	//printf("\n");
}
