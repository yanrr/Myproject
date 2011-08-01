#include <stdio.h>
#define M 10
#define N 20
int main(int argc, const char *argv[])
{
	int i,j,n = 0;
	int a[M][N];
	printf("array:\n");
	for (i = 0; i < M; i++)
	{
		for (j= 0; j < N; j++)
		{
			a[i][j] = i*j;
			printf("%6d",a[i][j]);
			n++;
			if (n%N == 0)
			{
				printf("\n");
			}
		}
	}
		
	printf("a:         %p\n",a);
	printf("a[0]:      %p\n",a[0]);
	printf("&a[0][0]:  %p\n",&a[0][0]);
	printf("&a[0]:     %p\n",&a[0]);

	printf("\n");
	
	return 0;
}
