#include <stdio.h>
#include <string.h>




int main()
{
	int first_length = 0;
	int second_length = 0;
	char first[600];
	char second[600];
	

	scanf("%d", &first_length);
	scanf("%d", &second_length);
	scanf("%s", first);
	scanf("%s", second);

	int count_table[first_length + 2][second_length + 2];
	memset(count_table , 0, sizeof(count_table));

	int hit_table[first_length + 2][second_length + 2];
	memset(hit_table , 0, sizeof(hit_table));

	int hit[first_length];
	memset(hit, 0, sizeof(hit));

	for(int i = 2; i < first_length + 2; i++)
	{
		for(int j = 2; j < second_length + 2; j++)
		{
			if(*(first + i - 2) == *(second + j - 2))
			{
				count_table[i][j] = count_table[i-1][j-1] + 1;
				hit_table[i][j] = 2;
			}
			else
			{
				count_table[i][j] = count_table[i-1][j];
				hit_table[i][j] = 1;
				if(count_table[i][j-1] > count_table[i][j])
				{
					count_table[i][j] = count_table[i][j-1];
					hit_table[i][j] = 3;
				}
			}

		}
	}


	int k = first_length + 1;
	int l = second_length + 1;
	while(!(k == 1 || l == 1))
	{
		if(hit_table[k][l] == 1)
		{
			k = k-1;
		}
		else if(hit_table[k][l] == 2)
		{
			hit[k - 2] = 1;
			k = k-1;
			l = l-1;
		}
		else if(hit_table[k][l] == 3)
		{
			l = l-1;
		}
	}


	printf("LCS: ");
	for(int i = 0; i < first_length; i++)
	{
		if(hit[i] == 1)
		{
			printf("%c ",*(first + i));
		}
	}
	printf("\n");
	
	return 0;

}

