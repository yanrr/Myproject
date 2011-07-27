#include <stdio.h>
int main(int argc, const char *argv[])
{
        unsigned int a;
        unsigned int mask;

        scanf("%d",&a);
        mask = (1 << 31);
        for (; mask>0; mask >>=1)
        {
            printf("%c",((a & mask) > 0) ? '1' : '0');
        }
        printf("\n");
        return 0;
}

