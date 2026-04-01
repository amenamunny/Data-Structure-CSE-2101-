#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int INFO;
    struct NODE *LINK;
};
void InsertLast(struct NODE *ptr, struct NODE *AVAIL, int ITEM )
{
    struct NODE *NEW, *temp;
    int pos = 2, i =1;
     if(AVAIL==NULL)
    {
        printf("OVERFLOW\n");
        return ;
    }

    NEW=AVAIL;
    AVAIL= AVAIL->LINK;
    NEW->INFO=ITEM;

     temp=ptr;
     while (i<pos)
   {
       temp=temp->LINK;
       i++;
   }
   NEW->LINK=temp->LINK;
   temp->LINK=NEW;

   printf("List After Insertion : \n");
     temp=ptr;
     while(temp!= NULL)
    {
        printf("%d\n", temp->INFO);
          temp=temp->LINK;
    }
}
int main()
{
    struct NODE *START, *N1, *N2, *N3, *AVAIL;
    int ITEM;
    START = malloc(sizeof(struct NODE));
    N1 = malloc(sizeof(struct NODE));
    N2 = malloc(sizeof(struct NODE));
    N3 = malloc(sizeof(struct NODE));
    START=N1;
    N1->INFO=10;
    N1->LINK=N2;
    N2->INFO=20;
    N2->LINK=N3;
    N3->INFO=30;
    N3->LINK=NULL;
    AVAIL = malloc(sizeof(struct NODE));
    AVAIL->LINK=NULL;
    printf("Enter a value: ");
    scanf("%d", &ITEM);
    InsertLast(START, AVAIL, ITEM);
    return 0;
}
