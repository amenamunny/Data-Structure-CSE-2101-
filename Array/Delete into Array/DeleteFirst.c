#include<stdio.h>
int main(){
int A[]={10,20,30,40};
int n=4;
for(int i=0;i<=n-1;i++)
    A[i]=A[i+1];
n--;
for(int i=0;i<n;i++){
    printf("%d ",A[i]);
}
return 0;
}
