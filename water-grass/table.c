#include <stdio.h>
#include <math.h>


typedef struct spinkler{
	int center;
	double l;
	double r;
}spinkler;

int main()
{
	int n = 0;
	int l = 0;
	int w = 0;
	scanf("%d %d %d", &n, &l, &w);

	spinkler spinklers[n];

	for(int i = 0; i < n; i++)
	{
		int center_i, radius_i;
		double range;
		scanf("%d %d", &center_i, &radius_i);
		spinklers[i].center = center_i;

		range = sqrt(radius_i*radius_i - (w/2)*(w/2));
		spinklers[i].l = (double)center_i - range;
		spinklers[i].r = (double)center_i + range;
	}

	for(int i = 0; i < n; i++)
	{
		printf("%d %f %f\n", spinklers[i].center, spinklers[i].l, spinklers[i].r);
	}
	return 0;
}
