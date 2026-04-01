#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = 0;
struct node *rear = 0;

void enqueue (int item)
{
    struct node *newnode;
    newnode = malloc (sizeof(struct node));

    newnode->data = item;
    newnode->next = NULL;

    if(front == 0 && rear == 0)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void display()
{
    struct node *temp = front;

    if(front == 0 && rear == 0)
    {
        printf("Queue is empty ");
        return;
    }

    printf("Queue : ");

    while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    return 0;
}
