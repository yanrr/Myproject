#include <stdio.h>
int main(int argc, const char *argv[])
{
        int array[100];
        int i;
        printf("array:");         
        printf("\n");
        for(i=0; i<100; i++)
        {
            printf("%4d",(array[i]=i));
        }
        printf("\n");
        return 0;
}
