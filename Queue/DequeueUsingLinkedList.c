#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void dequeue()
{
    struct node *temp;
    temp = front;

    if(front == 0 && rear == 0)
    {
        printf("UNDERFLOW");
        return;
    }

    printf("Deleted : %d\n", temp->data);
    front = front->next;



    free(temp);
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
        printf("\n");
}

int main()
{
    struct node *n1, *n2, *n3;

    n1 = malloc(sizeof(struct node));
    n2 = malloc(sizeof(struct node));
    n3 = malloc(sizeof(struct node));

    n1->data = 10;
    n1->next = n2;

    n2->data = 20;
    n2->next = n3;

    n3->data = 30;
    n3->next = NULL;

    front = n1;
    rear = n3;

    display ();

    dequeue();
    display();

    return 0;
}
