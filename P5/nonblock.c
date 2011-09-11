#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define MSG_TRY "try again\n"

int main(int argc, const char *argv[])
{
	char buf[10];
	int fd,n,i = 0;

	fd = open("/dev/tty",O_RDONLY | O_NONBLOCK);
	if (fd < 0) 
	{
		perror("open dev/tty");
		exit(-1);
	}

tryagain:
	n = read(fd,buf,10);
	if (n < 0) 
	{
		if (errno == EAGAIN) 
		{
			sleep(2);
			write(STDOUT_FILENO,MSG_TRY,strlen(MSG_TRY));
			i++;
			if (i == 5) 
			{
				perror("time out");
				exit(-1);
			}
			goto tryagain;
		}
		perror("read /dev/tty");
		exit(-1);
	}

	write(STDOUT_FILENO,buf,n);
	close(fd);

	return 0;
}
