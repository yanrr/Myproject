#include<stdio.h>
#define N 100

int main ()
{
	int a[N],i;
	int n = 0;
    
	for(i=0;i<100;i++)
	{
		a[i] = i+1;
		if((a[i]%10) == 9 && (a[i]/10) != 9 ) 
		{
			n++;
            printf("%4d",a[i]);
		}
		if((a[i]/10) == 9 )
		{
			n++;
            printf("%4d",a[i]);
		}
	}
    
    printf("\n");
	printf("total:%d\n",n);
	return 0;
}
