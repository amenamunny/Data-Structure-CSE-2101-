#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value)
{
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
};

struct Node* insert( struct Node* root, int value)
{
  if (root == NULL)
    return createNode(value);

  struct Node *q[100];
  int front = 0, rear = 0;

  q[rear++]=root;

  while(front<rear)
  {
      struct Node *temp = q[front++];

       if(temp->left == NULL)
        {
            temp->left = createNode(value);
            return root;
        }
        else
        {
            q[rear++] = temp->left;
        }

         if(temp->right == NULL)
        {
            temp->right = createNode(value);
            return root;
        }
        else
        {
            q[rear++] = temp->right;
        }
    }

    return root;

};

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
         printf("%d ", root->data);
    }
}

int main()
{
    struct Node* root=NULL;
    int n, value, i;

     printf("Number of Nodes: ");
    scanf("%d", &n);

    if(n<=0)
        return 0;

    for(i=1; i<=n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
