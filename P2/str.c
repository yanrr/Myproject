#include <stdio.h>
int main(int argc, const char *argv[])
{
        char S[] = "ABCDEFGH";
        char *P;
        
        P = S;     //将数组S的地址付给P的同时，也把S的值给了P
        while (*P != '\0')
        {
             printf("%c",*P);
             P++;
        }
        printf("\n");

        P--;    //用指针表示字符串时，是以'\0'结尾的，P--才能回到字符串
        while (P >= S)     //数组名的地址就是它的首地址
        {
            printf("%c",*P);
            P--;
        }

        printf("\n");
        return 0;
}
