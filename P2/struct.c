#include <stdio.h>
#include <string.h>

struct complex_struct
{
         int age;
         char name[20];
};

typedef struct complex_struct STU;      //结构体命名一般要大写

int main(int argc, const char *argv[])
{
        STU m;

        m.age = 22;
        strcpy(m.name, "yanrr");

        printf("name:%s   age:%d\n", m.name, m.age);
        return 0;
}
