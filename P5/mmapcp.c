#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

int main(int argc, const char *argv[])
{
	int fb,fd;
	char *P,*Q;
//	struct stat *buf;
//	buf = malloc(sizeof(struct stat));//若用定义结构体变量为一个指针时，需给其分配（malloc）一个空间
	struct stat buf;

	if (argc != 3) 
	{
		printf("Please input the two files after the ./a.out!\n");
		exit(-1);
	}

	fb = open(argv[1],O_RDONLY);
	if (fb < 0) 
	{
		perror("open fail!");
		exit(-1);
	}

	fd = open(argv[2],O_RDWR | O_CREAT,0777);
	if (fd < 0) 
	{
		perror("open fail!");
		exit(-1);
	}

	if (stat(argv[1],&buf) < 0) 
	{
		perror("stat fail!");
		exit(-1);
	}

	if (lseek(fd,buf.st_size-1,SEEK_SET) < 0) 
	{
		perror("iseek fail!");
		exit(-1);
	}
	write(fd, "1", 1);	//lseek时，只有在第二次操作时才能被真正拓展

	P = mmap(NULL,buf.st_size,PROT_READ,MAP_SHARED,fb,0);
	if (P == MAP_FAILED) 
	{
		perror("mmap");
		exit(-1);
	}

	Q = mmap(NULL,buf.st_size,PROT_WRITE,MAP_SHARED,fd,0);
	if (Q == MAP_FAILED) 
	{
		perror("mmap");
		exit(-1);
	}

	memcpy(Q,P,buf.st_size); 	//实现内存中文件的拷贝

	while (munmap(P,buf.st_size))
	{
		break;
	}
	while (munmap(Q,buf.st_size)) 
	{
		break;                          
	}

	close(fb);
	close(fd);

	return 0;
}
