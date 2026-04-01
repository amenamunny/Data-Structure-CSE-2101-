#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int INFO;
    struct Node *LINK;
};
void FindNode(struct NODE *START, struct NODE *ITEM)
{
    struct NODE *PTR, *SAVE, *LOC, *LOCP, *AVAIL;
    AVAIL=NULL;
    if (START == NULL)
    {
        LOC = NULL;
        LOCP = NULL;
    }

    else if (START->INFO == ITEM)
    {
        LOC = START;
        LOCP = NULL;
    }
    else
    {
        SAVE = START;
        PTR = START->LINK;

        while (PTR != NULL)
        {
            if (PTR->INFO == ITEM)
            {
                LOC = PTR;
                LOCP = SAVE;
                break;
            }

            SAVE = PTR;
            PTR = PTR->LINK;
        }

        if (PTR == NULL)
        {
            LOC = NULL;
            LOCP = NULL;
        }
    }

    if (LOC ==NULL)
        {
            printf("ITEM not found ");
            return;
        }
   if (LOCP==NULL)
    {
        START= START->LINK;
    }
    else
    {
        LOCP->LINK=LOC->LINK;
    }
    LOC->LINK=AVAIL;
    AVAIL=LOC;

     printf("List after Delete the Node:\n");
    PTR=START;
    while(PTR!=NULL)
    {
        printf("%d\n", PTR->INFO);
        PTR=PTR->LINK;
    }
}

int main()
{
    struct NODE *START, *N1, *N2, *N3 ;
    int ITEM;

    N1 = malloc(sizeof(struct NODE));
    N2 = malloc(sizeof(struct NODE));
    N3 = malloc(sizeof(struct NODE));

    START = N1;

    N1->INFO = 10;
    N1->LINK = N2;

    N2->INFO = 20;
    N2->LINK = N3;

    N3->INFO = 30;
    N3->LINK = NULL;

    printf("Enter a ITEM: ");
    scanf("%d", &ITEM);

    FindNode(START, ITEM);
    return 0;
}
