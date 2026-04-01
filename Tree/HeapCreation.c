#include<stdio.h>

int A[100];
int n;

void createheap()
{
    int i, left, right, large, temp;

    i = n/2;

    while(i >=1)
    {
        int k = i;

        while(1)
        {
            left = 2*k;
        right = 2*k+1;
        large = k;

        if(left <= n && A[large] < A[left])
        {
            large = left;
        }
        if(right <= n && A[large] < A[right])
        {
            large = right;
        }
        if (large != k)
        {
            temp =  A[k];
            A[k] = A[large];
            A[large] = temp;

            k = large;
        }
        else
        {
            break;
        }
        }

        i --;
    }
}

int main()
{
    printf("Enter an element : ");
    scanf("%d", &n);

    printf("Array : ");
    for(int i = 1; i<=n; i++)
    {
        scanf("%d", &A[i]);
    }

    createheap();

    printf("Heap : ");
    for(int i = 1; i<=n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}
