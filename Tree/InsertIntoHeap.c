#include<stdio.h>

int heap[100] = {0, 50, 30, 40, 10, 20};
int n = 5;

void insert(int item)
{
    int ptr, par;

    n = n+1;
    ptr = n;
    while(ptr > 1)
    {
        par = ptr/2;
         if(item <= heap[par])
         {
             heap[ptr] = item;
             return;
         }
         heap[ptr] = heap[par];
         ptr = par;
    }

    heap[ptr] = item;
}

void display()
{
    for(int i = 1; i<=n; i++)
    {
        printf("%d ", heap[i]);
    }

    printf("\n");
}

int main()
{
    printf("Heap before insert : ");
    display();

    insert(60);

    printf("Heap after insert : ");
    display();

    return 0;
}
