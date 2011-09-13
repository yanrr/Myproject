#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mystrcmp(char *a,char *b);

int main(int argc,char *argv[])
{
	if (argc != 3) 
	{
		printf("Please input two strings!\n");
		exit(0);
	}

	if (mystrcmp(argv[1],argv[2]) != 0)  
	{
		printf("%s\n",strcat(argv[1],argv[2]));
	}
	
	else
	{
		printf("Equal!\n");
	}

	return 0;
}

int mystrcmp(char *a,char *b)
{
	while ((*a == *b) && *a != '\0') 
	{
		*a++;
		*b++;
	}

	if (a == NULL || b == NULL) 
	{
		printf("It's NULL\n");
		return 0;
	}

	return (*a - *b);
}
