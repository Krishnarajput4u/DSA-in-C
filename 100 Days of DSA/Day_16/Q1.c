#include <stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *arr=malloc(n*sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++) {
        int count = 1;

        // Skip if element already counted
        if(arr[i] == -1)
            continue;

        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = -1;  // Mark as counted
            }
        }

        printf("%d:%d ", arr[i], count);
    }
    free(arr);
    return 0;
}