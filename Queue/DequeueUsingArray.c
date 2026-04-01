#include<stdio.h>

#define MAXSIZE 5

int queue[MAXSIZE];
int front = 0;
int rear = 2;

void dequeue()
{
    if(front > rear )
    {
        printf("UNDERFLOW ");
        return ;
    }
    if(front == rear)
    {
        printf("Delete : %d", queue[front]);
        front ++;
    }
    else
    {
        printf("Delete : %d\n", queue[front]);
        front ++;
    }

    if(front > rear )
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue : ");
       for(int i = front; i<=rear; i++)
       {
           printf("%d ", queue[i]);
       }
       printf("\n");
    }
}

int main()
{
    queue[0] = 10;
    queue[1] = 20;
    queue[2] = 30;

    dequeue();
    dequeue();

    return 0;
}

