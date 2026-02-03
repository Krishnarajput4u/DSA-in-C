// Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

// Input:
// - First line: integer n (array size)
// - Second line: n space-separated integers
// - Third line: integer k (key to search)

// Output:
// - Line 1: "Found at index i" OR "Not Found"
// Line 2: "Comparisons = c"

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// Found at index 2
// Comparisons = 3

// Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)
#include <stdio.h>
#include<stdlib.h>
int main() {
    int num;

    if (scanf("%d", &num) != 1 || num <= 0)
        return 1;

    int *arr=malloc(num*sizeof(int));

    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    scanf("%d",&target);
    int i;
    for(i=0;i<num;i++){
        if(target==arr[i]){
            break;
        }
    }
    printf("Found at index : %d\n",i);
    printf("Comparisons: %d",i+1);

    free(arr);
    return 0;
}
