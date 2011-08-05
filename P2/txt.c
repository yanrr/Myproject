#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *P = NULL;
    int i = 0;

    P = fopen("txt","r+");

    char a[100] = "This is a C program!";
    char r_a[100] = {0};

    if (P == NULL)
    {
        perror("Wrong");
        exit(0);
    }

    while(a[i] != '\0')    //字符串以隐藏的\0结尾
    {
        putc(a[i],P);
        i++;
    }
 
    i = 0;
    fseek(P,0,SEEK_SET);    //rewind(P)也可以实现，但rewind时直接复位到首位，而fseek函数可以复位到任意位置

    while ((r_a[i] = getc(P)) != EOF)
    {
        i++;
    }
 
    r_a[i] = '\0';

    printf("%s\n",r_a);

    fclose(P);

    return 0;
}
//putc与fputc等价，都是把数组a的内容一个一个打印到P所指向的文件即txt中
//getc与fgetc等价，都是把P所指向的文件即txt中的内容一个一个读取出来，再赋给数组a
