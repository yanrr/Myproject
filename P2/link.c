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

void print_link(STU *P);
STU *add_node(STU *P);

int main(int argc, const char *argv[])
{
        STU *head = NULL;
        int i;
        int n;
        int j;

        printf("Please input the number of nodes you want to add:\n");
        scanf("%3d",&n);

        for(i=0; i<n; i++)
        {
            head = add_node(head);
        }    

        printf("\n");
        j = count_node(head);
        print_link(head);
        printf("%d\n",j);

        return 0;
}

void print_link(STU *P)
{
        if (P == NULL)
        {
            printf("\nP = NULL\n");
        }

        while (P != NULL)
        {
            printf("age:%d  name:%s\n",P->age,P->name);
            P = P->next;
        }
        printf("\n");
}

int count_node(STU *P)
{
    int i = 0;

    while(P)
    { 
        P = P->next;
        i++;
    }

    return i;
}

STU *add_node(STU *p)
{
    STU *q = NULL;
    STU *head = p;
    
    q = malloc(sizeof(STU));
        
    if (q == NULL)
    {
        perror("malloc new");
        exit(0);
    }
    
    printf("please input age:\n");
    scanf("%d",&q->age);
    printf("please input name:\n");
    scanf("%s",q->name);
    q->next = NULL;

    if(p == NULL)
    {
        return q;
    }

    if(p->age > q->age)
    {
        q->next = p;
        return q;
    }
    while (p->next != NULL)
    {
        if (p->next->age > q->age) 
        {
            break;
        }
    
        p = p->next;
    }
    q->next = p->next;
    p->next = q;

    return head;
}

