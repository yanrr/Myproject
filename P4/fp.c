#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	int Snum;
	char name[20];
	char sex;
	short score;
};

typedef struct student STU;

STU init_information(void);
int p_Snum(STU S);
int p_name(STU S);
int p_sex(STU S);
int p_score(STU S);
int menu(void);

int main(int argc, const char *argv[])
{
	STU S;
	char buf[100];
	int (*p[4])(STU) = {p_Snum,p_name,p_sex,p_score};
	int num = 0;

	S = init_information();

	while (num != 4) 
	{
		printf("\n");
		menu();

		fgets(buf,sizeof(buf),stdin);
		buf[strlen(buf)-1] = '\0';
		num = atoi(buf);

		if (num == 4) 
		{
			break;
		}
		
		p[num](S);
	}

	return 0;
}

int menu(void)
{
	printf("Please make a choice:\n");

	printf("0 :print the Snum\n");
	printf("1 :print the name\n");
	printf("2 :print the sex\n");
	printf("3 :print the score\n");
	printf("4 :quit\n");

	return 0;
}

STU init_information(void)
{
	STU S;
	char buf[100];

	printf("Please input the Snum:\n");
	fgets(buf,sizeof(buf),stdin);
	buf[strlen(buf)-1] = '\0';
	S.Snum = atoi(buf);

	printf("Please input the name:\n");
	fgets(buf,sizeof(buf),stdin);
	buf[strlen(buf)-1] = '\0';
	strcpy(S.name,buf);

	printf("Please input the sex:\n");
	fgets(buf,sizeof(buf),stdin);
	if (strlen(buf) > 2) 
	{
		printf("Please input m or w\n");
		exit(0);
	}
	buf[strlen(buf)-1] = '\0';
	S.sex = buf[0];

	printf("Please input the score:\n");
	fgets(buf,sizeof(buf),stdin);
	buf[strlen(buf)-1] = '\0';
	S.score = atoi(buf);

	return S;
}

int p_Snum(STU S)
{
	printf("Student Snum:%d\n",S.Snum);
	return 0;
}

int p_name(STU S)
{
	printf("Student name:%s\n",S.name);
	return 0;
}

int p_sex(STU S)
{
	printf("Student sex:%c\n",S.sex);
	return 0;
}

int p_score(STU S)
{
	printf("Student score:%d\n",S.score);
	return 0;
}
