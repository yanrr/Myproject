#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int number;
    struct node *next;
};

typedef struct node NODE;

NODE *init_link(int n);
void inter_game(NODE *P);

int main(int argc, const char *argv[])
{
        NODE *head = NULL;
        int n = 0;

        printf("Please input the node number of the link:\n");
        scanf("%d",&n);
        head = init_link(n);
        inter_game(head);

        return 0;
}

NODE *init_link(int n)
{
    NODE *head = NULL;
    NODE *P = NULL;
    int i;

    head = P = malloc(sizeof(NODE));

    if (P == NULL) 
    {
        perror("creat");
        exit(0);
    }
    
    P->number = 1;
    P->next = NULL;
    for (i = 0; i < n; i++) 
    {
        P->next = malloc(sizeof(NODE));

        if (P->next == NULL)
        {
            perror("creat");
            exit(0);
        }

        P->next->number = i+1;
        P->next->next = NULL;
        P = P->next;

        if(P->next == NULL)
        {
            P->next = head;
        }
    }

    return P;
}

void inter_game(NODE *P)
{
    NODE *Q = P->next;
    int interval = 3;
    int out_counter = 0;

    while (Q != Q->next)
    {
        out_counter++;

        if (out_counter == interval)
        {
            out_counter = 0;
            printf("%7d(out)\n",Q->number);
            P->next = Q->next;
            free(Q);
            Q = P->next;
        }

        else
        {
            printf("%7d",Q->number);
            P = P->next;
            Q = Q->next;
        }
    }

    printf("left:%7d\n",Q->number);

}
