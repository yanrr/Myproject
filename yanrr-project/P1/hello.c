#include<stdio.h>
#define HOW_MANY_TIMES_TO_SAY_HELLO 10000
int main(int argc, const char *argv[])
{
    int i;      //必须先定义了才能使用
    for (i=0;i<HOW_MANY_TIMES_TO_SAY_HELLO;i++)
        {
            print("helloword!\n");
        }

    return 0 ;
}
