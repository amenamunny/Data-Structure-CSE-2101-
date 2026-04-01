#include<stdio.h>
#include<stdlib.h>

struct NODE
{
    int INFO;
    struct NODE *LINK;
};

void DeletePosition(struct NODE *START, int POS)
{
    struct NODE *PTR, *TEMP;
    int i;

    if (START == NULL)
    {
        printf("UNDERFLOW");
        return;
    }


    if (POS == 1)
    {
        printf("Deleted node: %d\n", START->INFO);
        START = START->LINK;
    }
    else
    {
        PTR = START;

        for (i = 1; i < POS - 1; i++)
        {
            PTR = PTR->LINK;
        }

        TEMP = PTR->LINK;
        printf("Deleted node: %d\n", TEMP->INFO);

        PTR->LINK = TEMP->LINK;
    }

    PTR = START;
    while (PTR != NULL)
    {
        printf("%d ", PTR->INFO);
        PTR = PTR->LINK;
    }
}

int main()
{
    struct NODE *START, *N1, *N2, *N3;

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

    DeletePosition(START, 2);

    return 0;
}
