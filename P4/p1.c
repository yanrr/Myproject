#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i;
	int n = 0;

	for (i = 1; i < 200; i++) 
	{
		if (i%3 != 0) 
		{
			printf("%5d",i);
			n++;
			if (n%7 == 0) 
			{
				printf("\n");
			}
		}

	}

	printf("\n");

	return 0;
}
