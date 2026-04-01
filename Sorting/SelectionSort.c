#include<stdio.h>
int main()
{
    int A[100];
    int n, i, j, small_index, temp;

    printf("Enter the value of N : ");
    scanf("%d", &n);

    printf("\nEnter an array list : ");
    for (i=1; i<=n; i++)
    {
        scanf("%d", &A[i]);
    }

    for(i=1; i<=n-1; i++)
    {
        small_index = i;

        for(j=i+1; j<=n; j++)
        {
            if(A[j] < A[small_index])
            {
                small_index = j;
            }
        }

        temp = A[i];
        A[i] = A[small_index];
        A[small_index] = temp;
    }

    printf("\nSorted List : ");
    for(i=1; i<=n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;

}
