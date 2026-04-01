#include<stdio.h>
int main(){
int A[]={10,20,30,40};
int n=4,pos=3;
for(int i=pos-1;i<n;i++)
    A[i]=A[i+1];
n--;
for(int i=0;i<n;i++){
    printf("%d ",A[i]);
}
return 0;
}

