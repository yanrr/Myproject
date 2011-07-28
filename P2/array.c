#include <stdio.h>
int main(int argc, const char *argv[])
{
        int array[100];
        int i=0;
        printf("array:");         
        printf("\n");
        while(i<100)
        {
            printf("%4d",(array[i]=i));
            i++;
        }
        printf("\n");
        return 0;
}
            
            
            
            
            
            
            
            
            
            
            
