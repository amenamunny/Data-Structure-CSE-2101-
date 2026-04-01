#include<stdio.h>

#define MAXSIZE 5

int queue[MAXSIZE];
int front = -1;
int rear = -1;

void enqueue(int item)
{
    if(rear == MAXSIZE-1)
    {
        printf("OVERFLOW ");
        return ;
    }

    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else
    {
        rear ++;
        queue[rear] = item;
    }

    printf("\nInserted : %d\n", item);

    printf("Queue : ");
    for(int i = front; i<=rear; i++)
    {
        printf("%d ", queue[i]);
    }

}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    return 0;
}
