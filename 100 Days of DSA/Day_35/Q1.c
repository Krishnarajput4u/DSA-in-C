// Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements)
// - Second line: n space-separated integers

// Output:
// - Print queue elements from front to rear, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.

#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* items;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->items = (int*)malloc(capacity * sizeof(int));
    return queue;
}

void enqueue(Queue* queue, int value) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue Overflow\n");
        return;
    }
    queue->items[++(queue->rear)] = value;
}

void display(Queue* queue) {
    if (queue->front > queue->rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
}

int main() {
    int n, value;
    scanf("%d", &n);
    Queue* queue = createQueue(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(queue, value);
    }

    display(queue);
    return 0;
}


