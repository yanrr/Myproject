#include <stdio.h>
int main(int argc, const char *argv[])
{
        int array[100];
        int i=0;
        int *p;
        p = array; 
        printf("array:");         
        printf("\n");
        
        for (i = 0; i < 100; i++)
        {
            array[i] = i;
            *p = array[i];
            printf("%4d",*p);
        }
        printf("\n");
        return 0;
}
            
            
            
            
            
            
            
            
            
            
            
