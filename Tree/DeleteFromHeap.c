#include<stdio.h>

int A[100], n, i;

int deleteheap()
{
    int ptr, left, right, large, temp, max;

    max = A[1];
    temp = A[n];
    n = n-1;

    ptr = 1;

    while(ptr*2 <= n)
    {
        left = 2*ptr;
        right = 2*ptr+1;

        if(right <= n && A[right] > A[left])
        {
            large = right;
        }
        else
        {
            large = left;
        }
        if(temp >= A[large])
        {
            A[ptr] = temp;
            return max;
        }
        A[ptr] = A[large];
        ptr = large;
    }

    A[ptr] = temp;
    return max;
}

void display()
{
    for(int i = 1; i<=n; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");

}

int main()
{
    printf("Enter an element : ");
    scanf("%d", &n);

    printf("Array : ");
    for( i = 1; i<=n; i++)
    {
        scanf("%d", &A[i]);
    }

    int max = deleteheap();
    printf("Delete element : %d\n", max);

    printf("After Delete : ");
    display();

    return 0;

}
