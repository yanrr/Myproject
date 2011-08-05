#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    FILE *P = NULL;
    int i = 0;
    int n = 0;

    P = fopen("txt","r+");

    char a[100] = "This is a C program!";
    char r_a[100] = "Hello everyone,I love you very much!";

    if (P == NULL)
    {
        perror("Wrong");
        exit(0);
    }

    fwrite(a,1,strlen(a),P);  //strlen函数用于字符串，sizeof函数用于一个空间

    fseek(P,0,SEEK_SET);

    n = fread(r_a,1,99,P);    //fread函数的返回值就是P所指向的文件中有效内容的长度，若将其改为“fread(r_a,1,99,P);”且无“r_a[n] = '\0';”则打印出来的r_a是：若原有内容太长，则覆盖之后剩下的依然输出打印

    r_a[n] = '\0';

    printf("%s\n",r_a);

    fclose(P);

    return 0;
}
