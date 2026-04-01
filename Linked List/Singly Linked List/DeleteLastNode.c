#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int INFO;
    struct NODE *LINK;
};
void DeleteLast(struct NODE *START)
{
    struct NODE  *PTR, *TEMP;
    if (START == NULL)
    {
        printf("UNDERFLOW ");
        return;
    }

    if (START->LINK == NULL) {
        printf("Deleted node: %d\n", START->INFO);
        START = NULL;
        return;
    }

    PTR = START;

    while (PTR->LINK->LINK!= NULL)
    {
        PTR = PTR->LINK;
    }

    printf("Deleted node: %d\n", PTR->LINK->INFO);

    PTR->LINK = NULL;

    TEMP = START;
    while (TEMP != NULL)
    {
        printf("%d ", TEMP->INFO);
        TEMP = TEMP->LINK;
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

    DeleteLast(START);
    return 0;
}
