// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 40 50 10 20

// Explanation:
// Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.ear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.

#include<stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value);
void dequeue();
void display();

int main() {
    int n, value;

    // Number of elements to enqueue
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    // Number of dequeue operations
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        dequeue();
    }

    // Display remaining queue
    display();

    return 0;
}

void enqueue(int value) {
    if(front == (rear + 1) % MAX) {
        printf("Overflow!!");
        return;
    }

    if(front == -1) {
        front = 0;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

void dequeue() {
    if(front == -1) {
        printf("Underflow!!");
        return;
    }

    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if(front == -1) return;

    int i = front;

    while(1) {
        printf("%d ", queue[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
}