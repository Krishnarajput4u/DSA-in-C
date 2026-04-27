#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100003

typedef struct {
    int key;
    int value;
    int filled;
} HashMap;

int hash(int key) {
    int h = key % MAX_SIZE;
    return (h < 0) ? h + MAX_SIZE : h;
}

int get_index(HashMap* map, int sum) {
    int h = hash(sum);
    while (map[h].filled) {
        if (map[h].key == sum) return map[h].value;
        h = (h + 1) % MAX_SIZE;
    }
    return -2;
}

void insert(HashMap* map, int sum, int index) {
    int h = hash(sum);
    while (map[h].filled) {
        h = (h + 1) % MAX_SIZE;
    }
    map[h].key = sum;
    map[h].value = index;
    map[h].filled = 1;
}

int maxLen(int arr[], int n) {
    HashMap* map = (HashMap*)calloc(MAX_SIZE, sizeof(HashMap));
    int max_len = 0;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];

        if (curr_sum == 0) {
            max_len = i + 1;
        }

        int prev_index = get_index(map, curr_sum);
        if (prev_index != -2) {
            int len = i - prev_index;
            if (len > max_len) {
                max_len = len;
            }
        } else {
            insert(map, curr_sum, i);
        }
    }

    free(map);
    return max_len;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", maxLen(arr, n));

    free(arr);
    return 0;
}