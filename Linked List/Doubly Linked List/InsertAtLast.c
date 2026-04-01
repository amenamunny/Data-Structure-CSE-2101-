#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int INFO;
    struct NODE *FORW;
    struct NODE *BACK;
};
 struct NODE *START;

 void InsertLast(struct NODE *AVAIL, int ITEM)
 {
     struct NODE  *NEW, *PTR;

     if(AVAIL==NULL)
     {
         printf("OVERFLOW ");
         return ;
     }

     NEW=AVAIL;
     AVAIL=AVAIL->FORW;

     NEW->INFO=ITEM;
     NEW->FORW=NULL;

     if(START==NULL)
     {
         NEW->BACK=NULL;
         START=NEW;
     }
     else
     {
         PTR=START;
         while(PTR->FORW!=NULL)
         {
             PTR= PTR->FORW;
         }
         PTR->FORW=NEW;
         NEW->BACK=PTR;
     }

     printf("The Linked List: \n");
     PTR=START;
     while(PTR!=NULL)
     {
         printf("%d\n", PTR->INFO);
         PTR=PTR->FORW;
     }
 }
 int main()
 {
     struct NODE *AVAIL, *N1, *N2, *N3;
     int ITEM;

     N1 = malloc(sizeof (struct NODE));
     N2 = malloc(sizeof (struct NODE));
     N3 = malloc(sizeof (struct NODE));

     START=N1;

     N1->INFO=10;
     N1->FORW=N2;
     N1->BACK=NULL;

     N2->INFO=20;
     N2->FORW=N3;
     N2->BACK=N1;

     N3->INFO=30;
     N3->FORW=NULL;
     N3->BACK=N2;

     AVAIL = malloc(sizeof (struct NODE));
     AVAIL->FORW=NULL;

     printf("Enter An Item: ");
     scanf("%d", &ITEM);

     InsertLast(AVAIL, ITEM);

     return 0;
 }
