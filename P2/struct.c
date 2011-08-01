#include <stdio.h>     // 多个结构体用指针相连构成链表，其中的结构体称为节点（node）
#include <string.h>

struct complex_struct
{
         int age;
         char name[20];
         struct complex_struct *P1;
};

typedef struct complex_struct STU;      

int main(int argc, const char *argv[])
{
        STU m;
        STU n;
        STU *P2;
        
        P2 = &m;
        P2->P1 = &n;
        
        P2->age = 11;
        strcpy(P2->name,"yanxx");
        P2->P1->age = 22;
        strcpy(P2->P1->name, "yanrr");

        printf("name:%s   age:%d\n",P2->name,P2->age);
        printf("name:%s   age:%d\n",P2->P1->name,P2->P1->age);

        return 0;
}
