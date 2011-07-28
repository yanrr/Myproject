#include <stdio.h>
int main(int argc, const char *argv[])
{
     int i,n = 0;
     for (i = 0; i <=100; i++)
     {
        printf("%4d",i);
        n++;
        if(n%7 == 0)
        {
            printf("\n");
        }
     }
     printf("\n");
     return 0;
}   
