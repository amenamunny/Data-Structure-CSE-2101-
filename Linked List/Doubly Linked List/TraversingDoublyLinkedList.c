#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int INFO;
    struct NODE *FORW;
    struct NODE *BACK;
};
 struct NODE *START;

 void Traversing()
 {
     struct NODE  *PTR;

     printf("Forward Traversing: \n");
     PTR=START;
     while(PTR!=NULL)
     {
         printf("%d\n", PTR->INFO);
         PTR=PTR->FORW;
     }

     printf("Backward Traversing: \n");
     PTR=START;
     while(PTR->FORW!=NULL)
     {
         PTR=PTR->FORW;
     }
     while(PTR!=NULL)
     {
         printf("%d\n", PTR->INFO);
         PTR=PTR->BACK;
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

     Traversing();

     return 0;
 }
