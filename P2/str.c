#include <stdio.h>
int main(int argc, const char *argv[])
{
        char S[] = "ABCDEFGH";
        char *P;
        char Q[10];
        P = S;

        while (*P != '\0')      //在这个程序中，它是复制一个，打印一个，所以才会打印出完整的字符。但是它后来复制的内容会覆盖之前的，所以最终的Q中只是S的最后一个字符
        {
            *Q = *P;
            printf("%c",*Q);
            P++;
        }
        printf("\n");
        return 0;
} 

The teacher's example：

#include <stdio.h>
#define N 20
char *my_copy(char *d,char *s)
{
    while (*s != '\0')  //char *m = d;
    {                   //while((*(d++) = *(s++)) !='0');
        *d = *s;        //return m;
        d++;            //自定义函数的内容可用注释的这部分代替,且比其规范
        s++;
    }
    *d = '\0';
    return d;
} 
int main(int argc, const char *argv[])
{
        char str[N] = "hello word!";
        char c_str[N];

        my_copy(c_str,str);       //之所以调用注释部分的函数，是因为其简捷，且规范。若调用自定义函数，会出现一个严重的bug:因为它只能打印复制的最后一个字符.在这个程序中之所以正常执行，是因为数组名的地址就是数组的首地址。
        printf("%s\n",c_str);
        return 0;
}
