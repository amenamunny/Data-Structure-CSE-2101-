#include<stdio.h>

int partition (int A[], int f, int l)
{
    int pivot, i, j, temp;

    pivot = A[f];
    i = f; j = l;

   while( i < j )
   {
       while ( A[i] <= pivot )
       {
           i++;
       }
        while ( A[j] > pivot )
       {
           j--;
       }
       if( i < j )
       {
           temp = A[i];
           A[i] = A[j];
           A[j] = temp;
       }
   }

   temp = A[f];
   A[f] = A[j];
   A[j] = temp;

   return j;
}

void Quick_Sort ( int A[], int f, int l)
{
    if ( f < l )
    {
        int j = partition( A, f, l);
        Quick_Sort( A, f, j-1);
        Quick_Sort( A, j+1, l);
    }
}

int main()
{
    int A[100], n, i;

    printf("Enter the value of N : ");
    scanf("%d", &n);

    printf("\nEnter an array : ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &A[i]);
    }

    Quick_Sort(A, 0, n-1);

    printf("\nSorted Array : ");
    for(i=0; i<n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}
