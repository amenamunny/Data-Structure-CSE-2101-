#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    int INFO;
    struct NODE *FORW;
    struct NODE *BACK;
};

struct NODE *START;

void DeletePosition(int pos)
{
    struct NODE *PTR;
    int i;

    if(START == NULL)
    {
        printf("List is Empty ");
        return;
    }

    PTR = START;

    for(i=1; i<pos; i++)
    {
        PTR = PTR->FORW;

        if(PTR == NULL)
        {
            printf("Invalid Position");
            return;
        }
    }

    if(PTR->BACK == NULL)   // First node delete
    {
        START = PTR->FORW;

        if(START != NULL)
        {
            START->BACK = NULL;
        }
    }
    else
    {
        PTR->BACK->FORW = PTR->FORW;

        if(PTR->FORW != NULL)
        {
            PTR->FORW->BACK = PTR->BACK;
        }
    }

    free(PTR);

    printf("The Linked List:\n");

    PTR = START;

    while(PTR != NULL)
    {
        printf("%d\n", PTR->INFO);
        PTR = PTR->FORW;
    }
}

int main()
{
    struct NODE *N1, *N2, *N3;
    int pos;

    N1 = malloc(sizeof(struct NODE));
    N2 = malloc(sizeof(struct NODE));
    N3 = malloc(sizeof(struct NODE));

    START = N1;

    N1->INFO = 10;
    N1->FORW = N2;
    N1->BACK = NULL;

    N2->INFO = 20;
    N2->FORW = N3;
    N2->BACK = N1;

    N3->INFO = 30;
    N3->FORW = NULL;
    N3->BACK = N2;

    printf("Enter position to delete: ");
    scanf("%d",&pos);

    DeletePosition(pos);

    return 0;
}
