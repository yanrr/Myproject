#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct complex_struct
{
         int age;
         char name[20];
};

typedef struct complex_struct STU;      

int main(int argc, const char *argv[])
{
        STU m;
        STU *P1 = NULL;             //P1初始化为空
        P1 = malloc(sizeof(STU));   //为P1开辟空间，其大小为STU的长度

        if (P1 == NULL)
        {
                perror("malloc");   //若开辟空间出错，打印出其位置
                exit(0);            //若开辟空间出错，则退出
        }

  //    P1 = &m;                    其改变了之前malloc开辟的空间，与后面的free不匹配
        P1->age  = 22;
        strcpy(P1->name, "yanrr");

        printf("name:%s   age:%d\n",P1->name,P1->age);

        free(P1);                   //释放出之前开辟的空间
        return 0;
}
