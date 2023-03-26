#include "stdio.h"
#include "string.h"

//根據分割表，遞迴印出括號和矩陣名的函數
int cut(int first,int end, void * cut_table, int n_size)
{
	//用參數帶入的起始和終點座標，查詢分割表，找到對應的分割點
	int cut_location = *((int *)cut_table + first * n_size + end);

	//如果查到的分割點是 0 ，代表無法再分割，印出矩陣名就好
	if(cut_location == 0)
	{
		printf("A%d",first);
		return 0;
	}

	//分割前印出上層左括號
	printf("(");
	//以分割座標為界線，分別遞迴呼叫下一層的分割函數
	cut(first, cut_location, cut_table, n_size);
	cut(cut_location + 1, end, cut_table, n_size);
	//分割完成後印出上層右括號
	printf(")");

	return 0;
}


int main()
{
	//宣告用來存放矩陣間隔數(含頭尾)的變數
	int between = 0;
	//取得使用者輸入的矩陣間隔數
	scanf("%d", &between);
	//矩陣數是間隔數 - 1
	int matrix_number = between - 1;

	//宣告間隔數 + 1 的陣列，因為第 0 項不使用(為了便於座標換算) 
	int size[between + 1];

	//第 0 項放入矩陣數(如果未來想優化減少變數數量)
	size[0] = matrix_number;

	//取得使用者輸入的間隔值並填入 size 陣列
	for(int i = 1; i <= between; i++)
	{
		scanf("%d", &size[i]);
	}

	//取得使用者想查詢的區間的起始位置
	int search_first;
	scanf("%d", &search_first);

	//取得使用者想查詢的區間的終點位置
	int search_end;
	scanf("%d", &search_end);


	//產生記數陣列和分割位置陣列，+ 1 是座標軸
	int count_table[matrix_number + 1][matrix_number + 1];
	int cut_table[matrix_number + 1][matrix_number + 1];
	//陣列初始化
	memset(count_table, 0, sizeof(count_table));
	memset(cut_table, 0, sizeof(cut_table));



	//填入兩個二維陣列的行座標
	for(int j = 1; j<= 6; j++)
	{
		count_table[0][j] = j;
		cut_table[0][j] = j;
	}

	//填入兩個二維陣列的列座標
	for(int i = 1; i<= 6; i++)
	{
		count_table[i][0] = i;
		cut_table[i][0] = i;
	}


	//開始計算表格中的值
	//i是距離差值，從最短一直到最長(因為是從上三角矩陣的底部開始一層一層往上填)
	for(int i = 1; i <= matrix_number -1; i++)
	{
		//j是行座標
		for(int j = 1; j < matrix_number; j++)
		{
			//如果行座標加上距離差值大於所有矩陣數，代表超出表格範圍，就跳出不計算
			if(j + i <= matrix_number)
			{
				//計算各個分割情況的結果，j 是區間起始，j + i 是區間終點，k是分割點
				for(int k = j; k < j + i; k++)
				{
					//用 temp 暫存當次分割的結果值
					// count_table[j][k] 是分割前段，count_table[k + 1][j + i] 是分割後段，(size[j] * size[k + 1] * size[j + i + 1]) 是最後一次矩陣相乘的次數
					int temp = count_table[j][k] + count_table[k + 1][j + i] + size[j] * size[k + 1] * size[j + i + 1];
	
					//如果是迴圈的首次執行，就直接填入 temp (因為矩陣初始為0)
					if(k == j)
					{
						count_table[j][j + i] = temp;
						//將分割位置記錄起來
						cut_table[j][j + i] = k;
					}
					else	//如果迴圈不是第一次
					{
						//如果 temp 比表格中的值還小，就填入覆蓋
						if(temp < count_table[j][j + i])
						{
							count_table[j][j + i] = temp;
							//刷新分割位置記錄
							cut_table[j][j + i] = k;
						}
					}
				}
			}
			else
			{
				break;
			}
		}
	}

	//查詢並印出使用者輸入的區間
	printf("%d\n", count_table[search_first][search_end]);
	//印出包含括號的算式
	cut(search_first, search_end, cut_table, matrix_number + 1);
	printf("\n");
}
