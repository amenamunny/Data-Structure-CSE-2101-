#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int INFO;
    struct NODE *LINK;
};
void Search(struct NODE *ptr, int ITEM)
{
    int LOC=0;
    while(ptr!= NULL)
    {
        if(ITEM==ptr->INFO)
        {
          LOC=ptr;
          break;
        }
        else
        {
            ptr=ptr->LINK;
        }
    }
    if(LOC!=NULL)
    {
        printf("Item %d found in the list\n", ITEM);
    }
    else
    {
        printf("Item %d not found in the list\n", ITEM);
    }
}
int main()
{
    struct NODE *START;
    struct NODE *N1;
    struct NODE *N2;
    struct NODE *N3;

    START = malloc(sizeof(struct NODE));
    N1 = malloc(sizeof(struct NODE));
    N2 = malloc(sizeof(struct NODE));
    N3 = malloc(sizeof(struct NODE));

    START->LINK=N1;
    N1->INFO=1;
    N1->LINK=N2;
    N2->INFO=2;
    N2->LINK=N3;
    N3->INFO=3;
    N3->LINK=NULL;

    Search(START,3);
    return 0;
}
