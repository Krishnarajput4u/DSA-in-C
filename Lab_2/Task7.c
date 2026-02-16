#include <stdio.h>

#define MAX 50

void instructions() {
    printf("\n--- Array Operations Menu ---\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Searching\n");
    printf("4. Traversal\n");
    printf("5. Update\n");
    printf("6. Display\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *n) {
    int pos, val;

    if (*n >= MAX) {
        printf("Array is full\n");
        return;
    }

    printf("Enter position (0 to %d): ", *n);
    scanf("%d", &pos);

    if (pos < 0 || pos > *n) {
        printf("Invalid position\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &val);

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = val;
    (*n)++;

    printf("Insertion successful\n");
}

void deleteElement(int arr[], int *n) {
    int pos;

    if (*n == 0) {
        printf("Array is empty\n");
        return;
    }

    printf("Enter position (0 to %d): ", *n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= *n) {
        printf("Invalid position\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;

    printf("Deletion successful\n");
}

void search(int arr[], int n) {
    int key, found = 0;

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at position %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found\n");
}

void update(int arr[], int n) {
    int pos, val;

    if (n == 0) {
        printf("Array is empty\n");
        return;
    }

    printf("Enter position (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &val);

    arr[pos] = val;
    printf("Update successful\n");
}

int main() {
    int arr[MAX], n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        instructions();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(arr, &n);
                break;
            case 2:
                deleteElement(arr, &n);
                break;
            case 3:
                search(arr, n);
                break;
            case 4:
                display(arr, n);
                break;
            case 5:
                update(arr, n);
                break;
            case 6:
                display(arr, n);
                break;
            case 0:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}
