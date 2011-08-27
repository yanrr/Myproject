#include <stdio.h>
#include <stdlib.h>

char init_card();
int riffle(int (*p)[13]);

int main(int argc, const char *argv[])
{
	int a[4][13];

	riffle(a);
	print_num(a);
	return 0;
}

int riffle(int (*p)[13])
{
	int flag[52] = {0};
	int num = 52;
	int temp;
	int *q = (int *)p;

	srand(time(NULL));
	while (num > 0) 
	{
		temp = rand()%52;
		if (flag[temp] == 1) 
		{
			continue;
		}

		else
		{
			flag[temp] = 1;
			*q = temp;
			q++;
			num--;
		}
	}

	return 0;
}

int print_num(int (*p)[13])
{
	int *q = (int *)p;
	int i;

	for (i = 1; i <= 52; i++,q++) 
	{
		printf("%-4d",*q);
		if (i%8 == 0) 
		{
			printf("\n");
		}
	}

	printf("\n");
	return 0;
}
