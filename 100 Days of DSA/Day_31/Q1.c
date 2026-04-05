// Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

// Input:
// - First line: integer n (number of operations)
// - Next n lines: operation type and value (if applicable)
//   - 1 value: push value
//   - 2: pop
//   - 3: display

// Output:
// - For display: print stack elements from top to bottom
// - For pop: print popped element or 'Stack Underflow'

// Example:
// Input:
// 5
// 1 10
// 1 20
// 3
// 2
// 3

// Output:
// 20 10
// 20
// 10

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

void push(Stack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

void pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", s->items[(s->top)--]);
}

void display(Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    s.top = -1;
    int n, operation, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &operation);
        switch (operation) {
            case 1:
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            default:
                printf("Invalid operation\n");
        }
    }

    return 0;
}