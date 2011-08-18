#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <menu.h>

struct student
{
         int Snum;
         char name[20];
         struct student *next;
};

typedef struct student STU;

STU *add_node(STU *P);
void print_link(STU *P);
int count_node(STU *P);
STU *delete_node(STU *P);
STU *read_date(void);
void save_date(STU *P);

void menu(void)
{
    printf("Please make a choice:\n");
    printf("1 :read date\n");
    printf("2 :add node\n");
    printf("3 :delete node\n");
    printf("4 :print link\n");
    printf("5 :count node\n");
    printf("6 :save\n");
    printf("7 :quit\n");
}

int main(int argc, const char *argv[])
{
        STU *head = NULL;
        int flag = 1;
        char choice = 0;
        int i;

        while (flag > 0)
        {
            menu();
            choice = getchar(); //getchar会将输入的值自动转换为字符
            getchar();          //getchar的赋值会将输入的字符和回车一起存放在缓冲区，再写一次可将字符提取出来
            switch(choice)
            {
                case '1':head = read_date();break;
                case '2':head = add_node(head);break;
                case '3':head = delete_node(head);break;
                case '4':print_link(head);break;
                case '5':i = count_node(head);
                         printf("The number of nodes:%d\n",i);break;
                case '6':save_date(head);break;
                case '7':flag = 0;break;
                default :printf("Please Do It Again!\n");
            }
                printf("\n\n");
        }

        return 0;
}

STU *read_date(void)
{
    FILE *Q = NULL;
    STU *head = NULL;
    STU *P = NULL;
    int r_Snum;
    char r_name[20];

    Q = fopen("txt1","r+");

    if (Q == NULL)
    {
        perror("fault");
        exit(0);
    }
    if (fscanf(Q,"%d%s",&r_Snum,r_name) == EOF)
    {
        return NULL;
    }
    head = P = malloc(sizeof(STU));

    if (head == NULL)
    {
        perror("malloc");
        exit(0);
    }


    head->Snum = r_Snum;
    strncpy(head->name,r_name,19);
    head->next = NULL;

    while (fscanf(Q,"%d%s",&r_Snum,r_name) != EOF) 
    {
            P->next = malloc(sizeof(STU));
            if (P->next == NULL)
            {
                    perror("malloc");
                    exit(0);
            }

            P->next->Snum = r_Snum;
            strncpy(P->next->name,r_name,19);
            P->next->next = NULL;           
            P = P->next;

    }

    

    return head;
}

STU *add_node(STU *P)
{
    STU *Q = NULL;
    STU *head = P;

    Q = malloc(sizeof(STU));
    if (Q == NULL)
    {
        perror("malloc");
        exit(0);
    }

    printf("Please input the Snum:\n");
    scanf("%d",&Q->Snum);
    getchar();
    printf("Please input the name:\n");
    scanf("%s",Q->name);
    getchar();

    while (P->next != NULL)
    {
        if (P->next->Snum < Q->Snum)
        {
            break;
        }

        P = P->next;
    }

    Q->next = P->next;
    P->next = Q;

    return head;
}

void print_link(STU *P)
{
        if (P == NULL)
        {
            perror("P = NULL");
            exit(0);
        }
        while (P)
        {
            printf("Snum:%d\n",P->Snum);
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
    int dnum;
    char dname[20];

    if (NULL == P)
    {
        printf("This link doesn's exist\n");

        return NULL;
    }

    printf("please input the Snum you want to delete:\n");
    scanf("%d",&dnum);
    getchar();
//  printf("please input the name you want to delete:\n");
//  scanf("%s",dname);
//  getchar();
    printf("\n");

//  if (strcmp(P->name,dname) == 0)
    if (P->Snum == dnum)
    {     
        head = P->next;
        free(P);
        return head;
    }

    while(P->next != NULL)
    {
    //  if(strcmp(P->name,dname) == 0)
        if (P->next->Snum == dnum)
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

void save_date(STU *P)
{
    FILE *Q = NULL;

    Q = fopen("txt2","w+");

    if (Q == NULL)
    {
        perror("fault");
        exit(0);
    }
    
    while (P != NULL)
    {
        fprintf(Q,"Snum:%d  name:%s\n",P->Snum,P->name);
        P = P->next;
    }
}
