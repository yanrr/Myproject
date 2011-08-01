#include <stdio.h>
#include <string.h>

struct complex_struct
{
  
    int age;
    char name[20];
};
   
typedef struct complex_struct STU;     
  
int main(int argc, const char *argv[])
{
    STU m;
    int *p1;
    char *p2;
  
    p1 = &m.age
    p2 = m.name;
  
  
    *p1 = 22;
    strcpy(p2, "yanrr");

    printf("name:%s   age:%d\n",p2, *p1);
    return 0;
}

