#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int INFO;
    struct NODE *LINK;
};
void DeleteFirst(struct NODE *START, struct NODE *AVAIL)
{
    struct NODE *LOC, *PTR;
    if (START == NULL)
    {
        printf("UNDERFLOW ");
        return;
    }

    LOC=START;
    START=START->LINK;

    LOC->LINK=AVAIL;
    AVAIL=LOC;

    PTR=START;
    while(PTR!=NULL)
    {
        printf("%d\n", PTR->INFO);
        PTR=PTR->LINK;
    }
}
int main()
{
    struct NODE *START, *AVAIL, *N1, *N2, *N3;

    START=malloc(sizeof(struct NODE));
    N1=malloc(sizeof(struct NODE));
    N2=malloc(sizeof(struct NODE));
    N3=malloc(sizeof(struct NODE));

    START=N1;
    N1->INFO=10;
    N1->LINK=N2;
    N2->INFO=20;
    N2->LINK=N3;
    N3->INFO=30;
    N3->LINK=NULL;

    AVAIL=malloc(sizeof(struct NODE));
    AVAIL->LINK=NULL;

    DeleteFirst(START, AVAIL);
    return 0;
}
