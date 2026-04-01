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
   if(root == NULL)
        return createNode(value);
   if(value < root->data)
     root->left = insert(root->left, value);
   else
     root->right = insert(root->right, value);

   return root;
};

struct Node *search(struct Node *root, int ITEM)
{
    if (root == NULL)
    {
        printf("Value %d is not found \n", ITEM);
        return NULL;
    }
    if(root->data == ITEM)
    {
        printf("value %d Found \n ", ITEM);
        return root;
    }
    if(ITEM < root->data)
        return search(root->left, ITEM);
    else
        return search(root->right, ITEM);
};

struct Node *findMin(struct Node *root)
{
    while (root->left!= NULL)
    {
        root = root->left;
        return root;
    }
};

struct Node *deleteNode(struct Node *root, int ITEM)
{
     if (root == NULL)
    {
        printf("Value %d is not found \n", ITEM);
        return NULL;
    }
    if(ITEM < root->data)
        root->left = deleteNode(root->left, ITEM);
    else if (ITEM > root->data)
        root->right = deleteNode(root->right, ITEM);
    else
    {        //case 1 : no child
        if(root->left == NULL && root->right == NULL)
        {
            printf("Delete %d for BST \n", root->data);
            free(root);
            return NULL;
        }
          //case 2: one child
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            printf("Delete data from BST \n", root->data);
            free(root);
            return temp;

        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            printf("Delete data from BST \n", root->data);
            free(root);
            return temp;

        }
          //case 3: more than one child
            struct Node *temp = findMin(root->right);
            printf("Delete %d from BST (Replace with %d) \n", root->data, temp->data);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);

    }

    return root;
};

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node* root=NULL;
    int n, value, i, ITEM;

    printf("Number of Nodes: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("\n Enter a value to search: ");
    scanf("%d", &ITEM);
    search(root, ITEM);

    printf("\n Enter a value to delete: ");
    scanf("%d", &ITEM);
    root = deleteNode(root, ITEM);

    printf("\n BST after Deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}

