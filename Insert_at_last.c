#include<stdio.h>
int main(){
   int LA[]={10,20,30,40,50};
   int n,value;
   printf("Enter n:");
   scanf("%d",&n);
   printf("Enter value:");
   scanf("%d",&value);

   LA[n]=value;
   n++;

   printf("Array after inserting last:");
   for(int i=0;i<n;i++){
    printf("%d ",LA[i]);
   }
   return 0;
}
