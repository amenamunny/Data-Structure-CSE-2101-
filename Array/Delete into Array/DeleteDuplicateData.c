#include <stdio.h>
int main()
 {
    int arr[10] = {5, 4, 2, 9, 2, 4, 4, 2,0};
    int n = 8;
    int i, j, k;

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {

                for(k = j; k < n - 1; k++)
                    arr[k] = arr[k + 1];

                n--;
                j--;
            }
        }
    }
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
