#include <stdio.h>
#include <string.h>




int main()
{
	int array_number = 0;			
	scanf("%d", &array_number);		//輸入要處理的陣列長度

	int array[array_number];		//建立存放資料的陣列
	memset(array, 0, sizeof(array));

	for(int i = 0; i < array_number; i++)
	{
		scanf("%d", &array[i]);
	}

	int k = 0;
	for(int i = 1; i < array_number; i++)
	{
		k = array[i];
		printf("( k = %2d )", k);
		int j = i;
		for(j; j > 0; j--)
		{
			if(array[j-1] > k)
			{
				array[j] = array[j-1];
			}
			else
			{
				break;
			}
		}
		array[j] = k;
		for(int i = 0; i < array_number; i++)
		{
			printf("%2d ", array[i]);
		}
		printf("\n\n");
	}
	return 0;
}

