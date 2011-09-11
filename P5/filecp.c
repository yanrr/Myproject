#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
	int destfd,srcfd;
	int len;
	char buf[4096];

	if (argc != 3) 
	{
		perror("Please input two files after ./a.out");
		exit(-1);
	}

	destfd = open(argv[1],O_RDONLY);
	if (destfd < 0) 
	{
		perror("open destfd fail");
		exit(-1);
	}

	srcfd = open(argv[2],O_RDWR | O_CREAT,0777);
	if (srcfd < 0) 
	{
		perror("open srcfd fail");
		exit(-1);
	}

	while(len = read(destfd,buf,sizeof(buf))) 
	{ 
		write(srcfd,buf,len);
	}

	close(destfd);
	close(srcfd);

	return 0;
}
