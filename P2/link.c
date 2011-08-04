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
int count_node(STU *P);
STU *delete_node(STU *P);

int main(int argc, const char *argv[])
{
        int n = 5;
        STU *head = NULL;
        int i;

        head = creat_link(n);
        print_link(head);

        printf("\n"); 

        head = delete_node(head);
        printf("\n"); 

        print_link(head);
        i =  count_node(head);
        printf("The number of nodes：%d\n",i);
        printf("\n"); 

        return 0;
}

STU *creat_link(int n)
{
    int i;
    STU *head = NULL;
    STU *P = NULL;
    int a[5] = {12,14,15,14,13};
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

STU *delete_node(STU *P)
{
    STU *head = P;
    STU *temp = NULL;
    int dage;
    char dname[20];

    if (NULL == P)
    {
        printf("This link doesn's exist\n");

        return NULL;
    }

    printf("please input the age you want to delete:\n");
    scanf("%d",&dage);
//  printf("please input the name you want to delete:\n");
//  scanf("%s",dname);
    printf("\n");

//  if (strcmp(P->name,dname) == 0)
    if (P->age == dage)
    {     
        head = P->next;
        free(P);
        return head;
    }

    while(P->next != NULL)
    {
    //  if(strcmp(P->name,dname) == 0)
        if (P->next->age == dage)
        {
            break;
        }
        P = P->next;
    } 

    if (P->next == NULL)
    {
        printf("The message you input just now doesn't exist!\n");
        return head;
    }  

    temp = P->next;
    P->next = P->next->next;
    free(temp);

    return head;

}

