#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int sys_err(char *s)
{
	write(1,s,strlen(s));
	exit(-1);
}

int main(int argc, const char *argv[])
{
	int fd;

	if (argc != 2) 
	{
		sys_err("./a.out file\n");	
	}
	fd = open(argv[1],O_RDWR | O_CREAT,0755);	//若无第三个参数，则系统会随机用一个,将会出现未知的bug
	if (fd <0) 
	{
		sys_err("open file fail\n");
	}

	return 0;
}
