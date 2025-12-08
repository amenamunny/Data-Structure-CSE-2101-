#include<stdio.h>
int main(){
    int LA[]={10,20,30,40,50};
    int n,value;

    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter value:");
    scanf("%d",&value);

    for(int i=n;i>0;i--){
        LA[i]=LA[i-1];
    }
        LA[0]=value;

    printf("Array after inserting first: ");
    for(int i=0;i<n;i++){
        printf("%d ",LA[i]);
    }
    return 0;
}
