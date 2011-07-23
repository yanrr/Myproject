#include<stdio.h>
#define HOW_MANY_TIMES_TO_SAY_HELLO 3
void say_three_hi();

int main(int argc, const char *argv[])
{
    say_three_hi();     //Ctrl-]:from call to definition
    return 0;
}

void say_three_hi();    //Ctrl-t:go back Ctrl-o:from definition to call
{
    int i;      
    for (i=0;i<HOW_MANY_TIMES_TO_SAY_HELLO;i++)
        {
            print("helloword!\n");
        }

    return 0 ;
}
