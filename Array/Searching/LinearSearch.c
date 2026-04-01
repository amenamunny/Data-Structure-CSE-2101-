#include<stdio.h>
int main()
{
    int arr[10]={1,2,3,4,5,6};
    int n=6;
    int item=4;
   int LOC=0;
   for(int i=0; i<n; i++)
   {
       if(arr[i]==item)
       {
           printf("Data found and index number is %d \n", i);
           LOC++;
           break;
       }
   }
    if(LOC==0)
       {
           printf("Data not found");
       }
   return 0;
}
