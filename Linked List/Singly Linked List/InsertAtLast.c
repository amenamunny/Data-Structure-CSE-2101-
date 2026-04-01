#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int INFO;
    struct NODE *LINK;
};
void InsertLast(struct NODE *ptr, int ITEM )
{
    struct NODE *NEW;
    NEW=malloc(sizeof(struct NODE));
    NEW->INFO=ITEM;
    NEW->LINK=NULL;
    struct NODE *temp=ptr;
     while (temp->LINK!=NULL)
   {
       temp=temp->LINK;
   }
   temp->LINK=NEW;
   printf("List After Insertion : \n");
   temp=ptr;
   temp=temp->LINK;
     while(temp!= NULL)
    {
        printf("%d\n", temp->INFO);
          temp=temp->LINK;
    }
}
int main()
{
    struct NODE *START, *N1, *N2, *AVAIL;
    int ITEM;
    START = malloc(sizeof(struct NODE));
    N1 = malloc(sizeof(struct NODE));
    N2 = malloc(sizeof(struct NODE));
    START->LINK=N1;
    N1->INFO=10;
    N1->LINK=N2;
    N2->INFO=20;
    N2->LINK=NULL;
    printf("Enter a value: ");
    scanf("%d", &ITEM);
    InsertLast(START, ITEM);
    return 0;
}
