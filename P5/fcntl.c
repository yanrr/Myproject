#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, const char *argv[])
{
	int val;
	if (argc != 2) 
	{
		fputs("usage:a.out <descriptor#>\n",stderr);
		exit(-1);
	}
	if ((val = fcntl(atoi(argv[1]),F_GETFL)) < 0) 
	{
		printf("fcntl error for fd %d\n",atoi(argv[1]));
		exit(-1);
	}
	switch(val & O_ACCMODE)
	{
	case O_RDONLY:
		printf("read only\n");
		break;
	case O_WRONLY:
		printf("write only\n");
		break;
	case O_RDWR:
		printf("read write\n");
		break;
	default:
		fputs("invalid access mode\n",stderr);
		exit(1);
	}
	if (val & O_APPEND) 
	{
		printf(",append\n");
	}
	if (val & O_NONBLOCK) 
	{
		printf(",NONBLOCK\n");
	}
	putchar('\n');
	return 0;
}
