#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int INFO;
    struct NODE *LINK;
};
void InsertFirst(struct NODE *START, struct NODE *AVAIL,struct NODE *LOC, int ITEM )
{
    struct NODE *PTR, *SAVE, *NEW;

    if(START==NULL)
    {
        LOC=NULL;
        return;
    }

    if(ITEM<START->INFO)
    {
         LOC=NULL;
        return;
    }

    else
    {
        SAVE=START;
        PTR=START->LINK;
        while(PTR!=NULL)
        {
            if(ITEM<PTR->INFO)
            {
                LOC=SAVE;
                break;
            }
            SAVE=PTR;
            PTR=PTR->LINK;
        }
        if(PTR==NULL)
        {
            LOC=SAVE;
        }
    }

    if(AVAIL==NULL)
    {
        printf("OVERFLOW\n");
        return ;
    }
    NEW=AVAIL;
    AVAIL=(AVAIL)->LINK;
    NEW->INFO=ITEM;
    if(LOC==NULL)
    {
        NEW->LINK= START;
        START=NEW;
    }
    else
    {
        NEW->LINK=LOC->LINK;
        LOC->LINK=NEW;
    }
    printf("List After Insertion : \n");
    PTR=START;
    while(PTR!=NULL)
    {
        printf("%d\n", PTR->INFO);
        PTR=PTR->LINK;
    }
}
int main()
{
    struct NODE *START, *N1, *N2, *LOC, *AVAIL;
    int ITEM;

    N1 = malloc(sizeof(struct NODE));
    N2 = malloc(sizeof(struct NODE));

    START=N1;
    N1->INFO=10;
    N1->LINK=N2;
    N2->INFO=20;
    N2->LINK=NULL;

    AVAIL= malloc(sizeof(struct NODE));
    AVAIL->LINK= NULL;
    LOC=N1;

    printf("Enter a value: ");
    scanf("%d", &ITEM);
    InsertFirst(START, AVAIL, LOC, ITEM);
    return 0;
}
