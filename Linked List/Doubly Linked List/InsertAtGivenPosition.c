#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    int INFO;
    struct NODE *FORW;
    struct NODE *BACK;
};

struct NODE *START;

void InsertPosition(struct NODE *AVAIL, int ITEM, int POS)
{
    struct NODE *NEW, *PTR;
    int i;

    if(AVAIL==NULL)
    {
        printf("OVERFLOW\n");
        return;
    }

    NEW = AVAIL;
    AVAIL = AVAIL->FORW;

    NEW->INFO = ITEM;

    if(POS==1)
    {
        NEW->FORW = START;
        NEW->BACK = NULL;

        if(START!=NULL)
        {
            START->BACK = NEW;
        }

        START = NEW;
        return;
    }

    PTR = START;

    for(i=1;i<POS-1;i++)
    {
        if(PTR==NULL)
        {
            printf("Invalid Position\n");
            return;
        }
        PTR = PTR->FORW;
    }

    NEW->FORW = PTR->FORW;
    NEW->BACK = PTR;

    if(PTR->FORW!=NULL)
    {
        PTR->FORW->BACK = NEW;
    }

    PTR->FORW = NEW;

    printf("The Linked List:\n");

    PTR = START;

    while(PTR!=NULL)
    {
        printf("%d\n",PTR->INFO);
        PTR = PTR->FORW;
    }
}

int main()
{
    struct NODE *AVAIL,*N1,*N2,*N3;
    int ITEM,POS;

    N1 = malloc(sizeof(struct NODE));
    N2 = malloc(sizeof(struct NODE));
    N3 = malloc(sizeof(struct NODE));

    START = N1;

    N1->INFO=10;
    N1->FORW=N2;
    N1->BACK=NULL;

    N2->INFO=20;
    N2->FORW=N3;
    N2->BACK=N1;

    N3->INFO=30;
    N3->FORW=NULL;
    N3->BACK=N2;

    AVAIL = malloc(sizeof(struct NODE));
    AVAIL->FORW = NULL;

    printf("Enter Item: ");
    scanf("%d",&ITEM);

    printf("Enter Position: ");
    scanf("%d",&POS);

    InsertPosition(AVAIL, ITEM, POS);

    return 0;
}
