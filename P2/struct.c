#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct complex_struct
{
         int age;
         char name[20];
         struct complex_struct *next;
};

typedef struct complex_struct STU;
STU *creat_link(int n);
void print_link(STU *P);

int main(int argc, const char *argv[])
{
        int n = 5;
        STU *head = NULL;

        head = creat_link(n);
        print_link(head);

        free(head);
        return 0;
}

STU *creat_link(int n)
{
    int i;
    STU *head = NULL;
    STU *P = NULL;
    int a[5] = {12,14,15,13,13};
    char *Q[5] = {"zhang","wang","yan","li","zhi"};
    head = P = malloc(sizeof(STU));

    if (P == NULL)
    {
        perror("creat");
        exit(0);
    }

    P->age = a[0];
    strcpy(P->name,Q[0]);

    for (i = 1; i < n; i++) 
    {
            P->next = malloc(sizeof(STU));
            if (P->next == NULL)
            {
                    perror("creat");
                    exit(0);
            }

            P->next->age = a[i];
            strcpy(P->next->name,Q[i]);
            P->next->next = NULL;           
            P = P->next;

    }

    return head;
}

void print_link(STU *P)
{
        while (P)
        {
            printf("age:%d\n",P->age);
            printf("name:%s\n",P->name);

            P = P->next;
        }
}
