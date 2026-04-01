#include<stdio.h>

int A[100], n;

void heapify(int A[], int n, int i)
{
    int large, left, right, temp;

    large = i;
    left = 2*i;
    right = 2*i+1;

    if(left < n && A[left] > A[large])
    {
        large = left;
    }
    if(left < n && A[right] > A[large])
    {
        large = right;
    }
    if(large != i)
    {
        temp = A[i];
        A[i] = A[large];
        A[large] = temp;

        heapify(A, n, large);
    }
}

void heapsort(int A[], int n)
{
    int i, temp;

    for(i = n/2; i >=1; i--)
    {
        heapify(A, n, i);
    }
    for(i = n; i>=1; i--)
    {
        temp = A[1];
        A[1] = A[i];
        A[i] = temp;

        heapify(A, i-1, 1);
    }
}

int main()
{
    int i;
    printf("Enter an element : ");
    scanf("%d", &n);

    printf("Array : ");
    for( i = 1; i<=n; i++)
    {
        scanf("%d", &A[i]);
    }

    heapsort(A, n);
    printf("Sorted Heap : ");
    for(int i = 1; i<=n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;

}
