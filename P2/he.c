#include <stdio.h>
int main(int argc, const char *argv[])
{   
        unsigned int a;
        unsigned char mask;
        char str[] = "0123456789abcdef";
        int move = 28,i;
        scanf("%d",&a);
        mask = 0xf;
        {
            for(i=0;i<8;i++)
                {                
                 printf("%c",str[(a >>move) & mask]);
                 move -=4;
                }
        }
        printf("\n");
        return 0;
}

