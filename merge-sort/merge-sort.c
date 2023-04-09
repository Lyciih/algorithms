#include <stdio.h>

int merge_sort(int total_number, int begin, int end, int* array)
{
	if(total_number == 1)
	{
		return 0;
	}
	else
	{
		int temp[total_number];
		int first_number = total_number / 2;
		int second_number = total_number - first_number;
		int divide_position = begin + total_number / 2;

		merge_sort(first_number, begin, divide_position - 1, array);
		merge_sort(second_number, divide_position, end, array);

		int first_merge = begin;
		int second_merge = divide_position;
		int first_end = 0;
		int second_end = 0;

		for(int i = 0; i < total_number; i++)
		{
			if(first_end != 1 && second_end != 1)
			{
				if(*(array + first_merge) <= *(array + second_merge))
				{
					temp[i] = *(array + first_merge);
					if(first_merge == divide_position - 1)
					{
						first_end = 1;
					}
					else
					{
						first_merge++;
					}
				}
				else
				{
					temp[i] = *(array + second_merge);
					if(second_merge == end)
					{
						second_end = 1;
					}
					else
					{
						second_merge++;
					}
				}
			}
			else if(first_end == 1)
			{
				temp[i] = *(array + second_merge);
				if(second_merge < end)
				{
					second_merge++;
				}
			}
			else
			{
				temp[i] = *(array + first_merge);
				if(first_merge < divide_position - 1)
				{
					first_merge++;
				}
			}
		}

		for(int i = 0; i < total_number; i++)
		{
			array[begin + i] = temp[i];
		}
	}
}


int main()
{
	int array_number = 0;			
	scanf("%d", &array_number);		//輸入要處理的陣列長度

	int array[array_number];		//建立存放資料的陣列

	for(int i = 0; i < array_number; i++)
	{
		scanf("%d", &array[i]);
	}


	merge_sort(array_number, 0, array_number - 1, array);

	for(int i = 0; i < array_number; i++)
	{
		printf("%2d ", array[i]);
	}
	printf("\n");
	return 0;
}

