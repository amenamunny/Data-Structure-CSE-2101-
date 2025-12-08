#include<stdio.h>
int main(){
  int LA[]={10,20,30,40,50};
  int n=5;
  int data,value,pos=-1;
  printf("Enter data before which to insert:");
  scanf("%d",&data);
  printf("Enter value to insert:");
  scanf("%d",&value);

  for(int i=0; i<n; i++) {
        if(LA[i] == data) {
            pos = i;
            break;
        }
    }

    if(pos == -1) {
        printf("Data not found!");
        return 0;
    }

    for(int i=n; i>pos; i--)
        LA[i] = LA[i-1];

    LA[pos] = value;
    n++;

    printf("Array after insertion:");
    for(int i=0; i<n; i++)
        printf("%d ", LA[i]);

    return 0;
}

