#include <stdio.h>
#include <math.h>


typedef struct spinkler{
	int 	center;
	double	l;
	double	r;
	int	select;
}spinkler;

int main()
{
	int n = 0;
	int l = 0;
	int w = 0;

	scanf("%d %d %d", &n, &l, &w);	
	double w_h = ((double)w)/2;
	spinkler spinklers[n];

	for(int i = 0; i < n; i++)
	{
		spinklers[i].center = 0;
		spinklers[i].l = 0;
		spinklers[i].r = 0;
		spinklers[i].select = 0;

	}

	for(int i = 0; i < n; i++)
	{
		int center_i, radius_i;
		double range;
		scanf("%d %d", &center_i, &radius_i);
		spinklers[i].center = center_i;

		range = sqrt(radius_i*radius_i - w_h*w_h);
		spinklers[i].l = (double)center_i - range;
		spinklers[i].r = (double)center_i + range;
	}

	for(int i = 0; i < n; i++)
	{
		printf("%d %f %f\n", spinklers[i].center, spinklers[i].l, spinklers[i].r);
	}	

	double position = 0;
	double next_step = 0;
	int chose = -1;
	while(1)
	{
		position = next_step;
		chose = -1;

		//遍歷陣列尋找下一步選擇
		for(int i = 0; i < n; i++)
		{
			if(spinklers[i].l <= position && spinklers[i].select != 1)
			{
				if(spinklers[i].r > next_step)
				{
					next_step = spinklers[i].r;
					chose = i;
				}
			}
		}

		//如果有找到，標記起來
		if(chose != -1)
		{
			spinklers[chose].select = 1;
		}
		else
		{
			break;
		}

		//如果已成功覆蓋就退出
		if(next_step >= l)
		{
			break;
		}
	}

	for(int i = 0; i < n; i++)
	{
		printf("%d ", spinklers[i].select);
	}
	printf("\n%f\n", next_step);
	if(next_step >= l)
	{
		int count = 0;
		for(int i = 0; i < n; i++)
		{
			if(spinklers[i].select == 1)
			{
				count++;
			}
		}
		printf("%d\n", count);
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}
