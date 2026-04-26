#include <stdio.h>

int heap[100];
int n = 0;

void insert(int val) {
    heap[n] = val;   // insert at end
    int i = n;
    n++;

    // heapify up
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[i] > heap[parent]) {
            int temp = heap[i];
            heap[i] = heap[parent];
            heap[parent] = temp;

            i = parent;
        } else {
            break;
        }
    }
}

void delete(int value){
    int i;
    for(i=0; i<n; i++){
        if(heap[i] == value){
            break;
        }
    }

    if(i == n){
        printf("Value not found in heap.\n");
        return;
    }

    heap[i] = heap[n-1]; // replace with last element
    n--;

    // heapify down
    while (i < n) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < n && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < n && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;

            i = largest;
        } else {
            break;
        }
    }
}

int main() {
    insert(50);
    insert(30);
    insert(20);
    insert(10);
    insert(40);
    insert(60);

    // print heap
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }

        printf("\n");

    delete(60);
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");

    return 0;
}