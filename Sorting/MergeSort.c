#include<stdio.h>

void mergeSort(int arr[], int f, int l)
{
    if( f < l)
    {
        int m = ( f + l) / 2;
        mergeSort( arr, f, m);
        mergeSort( arr, m+1, l);
        merge( arr, f, m, l);
    }
}

void merge(int arr[], int f, int m, int l)
{
    int temp[100];
    int i = f, j = m+1, k = f;

    while (i <= m && j <= l)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while( i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while( j <= l)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = f; i<=l; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int arr[100], n, i;

    printf("Enter the value of N : ");
    scanf("%d", &n);

    printf("\nEnter an array list : ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n-1);

    printf("\nSorted Array : ");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
