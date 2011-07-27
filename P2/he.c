#include <stdio.h>
int main(int argc, const char *argv[])
{
        int a,b;
        char mask;

        scanf("%d",&a);
        mask = 0x3c;
        b = a & mask;
        b >>= 2;

        printf("%d\n",b);
        return 0;
}

