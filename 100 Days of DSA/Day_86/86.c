#include <stdio.h>

int sqrtBinary(int n) {
    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        // Avoid overflow using long long
        long long square = (long long)mid * mid;

        if (square == n) {
            return mid;
        }
        else if (square < n) {
            ans = mid;      // store possible answer
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    int result = sqrtBinary(n);

    printf("Integer square root: %d\n", result);

    return 0;
}