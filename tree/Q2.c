#include <stdio.h>

#define MAX_SIZE 100

void printArrayAsBinaryTree(int arr[], int present[], int n) {
	for (int i = 0; i < n; i++) {
		int left = (2 * i) + 1;
		int right = (2 * i) + 2;

		if (present[i]) {
			printf("Parent arr[%d] = %d", i, arr[i]);
		} else {
			printf("Parent arr[%d] = EMPTY", i);
		}

		if (left < n) {
			if (present[left]) {
				printf(" | Left arr[%d] = %d", left, arr[left]);
			} else {
				printf(" | Left arr[%d] = EMPTY", left);
			}
		} else {
			printf(" | Left = NULL");
		}

		if (right < n) {
			if (present[right]) {
				printf(" | Right arr[%d] = %d", right, arr[right]);
			} else {
				printf(" | Right arr[%d] = EMPTY", right);
			}
		} else {
			printf(" | Right = NULL");
		}

		printf("\n");
	}
}

int main() {
	int n;
	int arr[MAX_SIZE];
	int present[MAX_SIZE];
	char choice;
	printf("Enter number of elements: ");
	scanf("%d", &n);

	if (n <= 0 || n > MAX_SIZE) {
		printf("Invalid size.\n");
		return 0;
	}

	for (int i = 0; i < n; i++) {
		printf("Leave index %d empty? (y/n): ", i);
		scanf(" %c", &choice);

		if (choice == 'y' || choice == 'Y') {
			present[i] = 0;
		} else {
			present[i] = 1;
			printf("Enter element for index %d: ", i);
			scanf("%d", &arr[i]);
		}
	}

	printf("\nBinary tree relation using 2*i+1 and 2*i+2:\n");
	printArrayAsBinaryTree(arr, present, n);

	return 0;
}
