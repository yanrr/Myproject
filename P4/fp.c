#include <stdio.h>

int foo(int num,char ch)
{
	printf("%d %c\n",num,ch);

	return 0;
}

int main(int argc, const char *argv[])
{
	int i = 0;
//	int (*p[10])(int,char);
	int (*p[10])(int,char) = {foo,foo};
/*
	p[0] = foo;
	p[0](7,'s');
	
*/
	if (p == NULL) 
	{
		perror("init fault");
		exit(0);
	}
	while (i <10) 
	{
		p[i](i,'a'+i);
		i++;
	}

	return 0;
}
