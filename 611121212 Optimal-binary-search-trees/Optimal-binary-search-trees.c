#include "stdio.h"
#include "string.h"


int main()
{
	//讀取key值
	int key = 0;
	scanf("%d", &key);
	
	//用key值宣告加一長度的p陣列
	float p[key + 1];

	//p的第0項為0
	p[0] = 0;

	//讀取使用者輸入的每一個P值填入P陣列
	for(int i = 1; i <= key; i++)
	{
		scanf("%f", &p[i]);
	}
	
	//用key值宣告加一長度的q陣列
	float q[key + 1];

	//讀取使用者輸入的每一個q值填入q陣列
	for(int i = 0; i <= key; i++)
	{
		scanf("%f", &q[i]);
	}


	//宣告存放 w 值的二維陣列
	float w_table[key + 2][key + 2];

	//宣告存放 e 值的二維陣列
	float e_table[key + 2][key + 2];

	//宣告存放 root 值的二維陣列
	int r_table[key + 2][key + 2];

	//初始化三個二維陣列
	memset(w_table, 0, sizeof(w_table));
	memset(e_table, 0, sizeof(e_table));
	memset(r_table, 0, sizeof(r_table));



	//在三個二維陣列填入行座標
	for(int j = 1; j <= key + 1; j++)
	{
		w_table[0][j] = j;
		e_table[0][j] = j;
		r_table[0][j] = j;
	}

	//在三個二維陣列填入列座標
	for(int i = 1; i <= key + 1; i++)
	{
		w_table[i][0] = key + 1 - i;
		e_table[i][0] = key + 1 - i;
		r_table[i][0] = key + 1 - i;
	}
	
	//填入 w 和 e 的初值(反對角項)
	for(int i = 1; i <= key + 1; i++)
	{
		w_table[key + 2 - i][i] = q[i - 1];
		e_table[key + 2 - i][i] = q[i - 1];
	}


	//開始運算 w 表
	//k 是每層座標運算的差值
	for(int k = 1; k > 1 - key; k--)
	{
		//這裡的 i 是 w 的行
		for(int i = 1; i <= key; i++)
		{
			 
			if(key + k - i <= 0)	//代表這層的最後一項做完了
			{
				break;
			}
			else	//計算 w 值，填入對應的格子中
			{
				// (key + k - i) 可以換算出當前階段處理的行對應的列座標，接著 (key + 1) - (key + k - i) = (i + 1 - k)，可以將對應的列座標換算回 p、q 陣列的對應項 
				w_table[key + k - i][i] = w_table[key + k - i + 1][i] + p[i + 1 - k] + q[i + 1 - k];
			}
		}
	}


	//開始運算 e 表
	//k 是每層座標運算的差值
	for(int k = 1; k > 1 - key; k--)
	{
		//這裡的 i 是 w 的行
		for(int i = 1; i <= key; i++)
		{
			if(key + k - i <= 0)	//代表這層的最後一項做完了
			{
				break;
			}
			else	//計算 e 值，填入對應的格子中
			{
				//計算root設在區間中各個點的結果，將最小的值填入對應的格子中
				// i 是區間起點，(i + 1 - k) 是區間終點
				for(int j = i; j <= i + 1 - k; j++)
				{
					//先把 root 為 j 的結果算出，存在 temp 中
					float temp = e_table[key - j + 2][i] + e_table[key + k - i][j + 1] + w_table[key + k - i][i];

					//如果是迴圈的第一次執行，因為二維矩陣初始為0，把 temp 直接填入
					if(j == i)
					{
						e_table[key + k - i][i] = temp;

						// root 表順便記錄分割點
						r_table[key + k - i][i] = j;
					}
					else	//如果不是迴圈的第一次執行
					{
						//比較 temp 與對應格子中的值，如果 temp 比較小，就填入 temp 的值將其覆蓋
						if(temp < e_table[key + k - i][i])
						{
							e_table[key + k - i][i] = temp;

							//更新 root 表
							r_table[key + k - i][i] = j;
						}
					}
				}
			}
		}
	}

	//輸出結果
	printf("E = %.2f\n", e_table[1][1]);
}
