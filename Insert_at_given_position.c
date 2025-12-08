#include<stdio.h>
int main(){
    int LA[]={10,20,30,40,50};
    int n, position,value;
    printf("Enter n:");
    scanf("%d",&n);

    printf("Enter position:");
    scanf("%d",&position);
    printf("Enter value:");
    scanf("%d",&value);

    for(int i=n;i>=position;i--)
     LA[i]=LA[i-1];
     LA[position-1]=value;
     n++;

     printf("Array after inserting: ");
     for(int i=0;i<n;i++)
        printf("%d ",LA[i]);
     return 0;
}
