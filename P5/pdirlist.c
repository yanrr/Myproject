#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>

#define MAX_PATH 1024

int dirwalk(char *dir,int(*fcn)(char *));
int fsize(char *name);

int main(int argc, char *argv[])
{
	if (argc == 1) 
	{
		fsize(".");
	}
	else
	{
		while (--argc > 0) 
		{
			fsize(*++argv);
		}
	}

	return 0;
}

int fsize(char *name)
{
	struct stat stbuf;

	if (stat(name,&stbuf) == -1) 		//将stat函数换成lstat更好，因为lstat函数不跟踪符号链接文件
	{
		fprintf(stderr,"fize: can't access %s\n",name);
		return 0;
	}

	if ((stbuf.st_mode & S_IFMT) == S_IFDIR) 
	{
		dirwalk(name,fsize);
	}

	printf("%8ld %s\n",stbuf.st_size,name);

	return 0;
}

int dirwalk(char *dir,int(*fcn)(char *))
{
	char name[MAX_PATH];
	struct dirent *dp;
	DIR *dfd;

	if ((dfd = opendir(dir)) == NULL) 
	{
		fprintf(stderr,"dirwalk :can't open %s\n",dir);
		return 0;
	}
	while ((dp = readdir(dfd)) != NULL) 
	{
		if (strcmp(dp->d_name,".") == 0 || strcmp(dp->d_name,"..") == 0) 
		{
			continue;
		}

		if (strlen(dir)+strlen(dp->d_name)+2 > sizeof(name)) 
		{
			fprintf(stderr, "dirwalk: name %s %s too long\n",dir, dp->d_name);
		}
		else 
		{
			sprintf(name, "%s/%s", dir, dp->d_name);
			(*fcn)(name);
		}
	}
	closedir(dfd);

	return 0;
}
