#include <stdio.h>
#define N 10
int main(int argc, const char *argv[])
{
        int array[N] = {0};
        int i;
        int interval = 3;
        int out_counter = 0;
        int m = 0;
        char flag = 0;

        for (i = 0; m<N; i++)
        {
            if (i == N)
            {
                i = 0;
            }
            if (array[i] == 0)
            {
                out_counter++;
                if(flag == 1)
                {
                    printf("\n  left : %d\n", i+1);
                    break;
                }
                if (out_counter == interval)
                {
                    m++;
                    out_counter = 0;
                    array[i] = 1;
                    if((N - 1) == m)
                    {
                        flag = 1;
                    }
                    printf("  out:%d\n",i+1);
                }
                else
                {
                printf("%4d",i+1);
                }
            }
        } 
        printf("\n");
        return 0;
}
