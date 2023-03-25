#include "stdio.h"
#include "string.h"


int main()
{
	int key = 0;
	scanf("%d", &key);
	
	float p[key + 1];
	p[0] = 0;
	for(int i = 1; i <= key; i++)
	{
		scanf("%f", &p[i]);
	}
	
	float q[key + 1];
	for(int i = 0; i <= key; i++)
	{
		scanf("%f", &q[i]);
	}

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
				w_table[key + k - i][i] = w_table[key + k - i + 1][i] + p[i + 1 - k] + q[i + 1 - k];
			}
		}
	}


	
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
				for(int j = i; j <= i + 1 - k; j++)
				{
					float temp = e_table[key - j + 2][i] + e_table[key + k - i][j + 1] + w_table[key + k - i][i];
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
			}
		}
	}
	printf("E = %.2f\n", e_table[1][1]);
}
