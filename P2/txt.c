#include <stdio.h>      
#include <stdlib.h>

int main(int argc, const char *argv[])

//  P = fopen("txt","w");   //若源文件中有内容，则将其清空再打印到该文件中
//  P = fopen("txt","w+");  //若源文件中有内容，则将其清空再打印到该文件中
    P = fopen("txt","r");
//  P = fopen("txt","r+");  //写入时若原文件中有内容，则将其覆盖，覆盖的长度就是其新打印的长度，原文件中覆盖后剩下的内容不变
//  P = fopen("txt","a");
//  P = fopen("txt","a+");  
//  (w:读 r:写 a:追加，凡带+的都是可读可写的,w+ a a+具有一个共同的特性就是，当txt文件不存在时，自动创建一个)
    char a[100] = {0};

    if (P == NULL)
    {
        perror("Wrong");
        exit(0);
    }

//  fprintf("%s\n",a); // (格式，变量名)该函数和fputs一样('写'函数)，把a的内容打印到P所指向的文件即txt中；后面的fscanf和fgets函数('读'函数)则是把P所指向的文件即txt中的内容读取出来，给变量a

//  fputs(a,P);        // (变量名，地址)该函数在结尾时不加\0

    fscanf(P,"%s",a);  // (地址，格式，变量名)只能接受连续的字符串，遇空格结束,无空格遇回车结束

    fgets(a,99,P);     // (变量名，读取长度，地址)可以接受有空格的字符串，遇回车结束，且在回车后自动加上\0形成完整的字符串

    printf("%s\n",a);

    fclose(P);

    return 0;
}
//printf("%s\n",a); //printf比puts范围广，可以输出任意类型
//puts(a);          //只能输出字符串
//scanf("%s",a); //scanf函数,在其打印输出时,遇空格自动结束,无空格遇回车结束
//gets(a);       //gets函数，在其打印输出时，遇回车结束，结尾处在加上\0的同时丢掉了回车,因为没有字符限制，可能会产生越界导致程序崩溃，比较危险，一般不用
