// Problem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottom

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 20 10

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* items;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (int*)malloc(capacity * sizeof(int));
    return stack;
}

void push(Stack* stack, int value) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++(stack->top)] = value;
}

void pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    stack->top--;
}

void display(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main() {
    int n, m, value;
    scanf("%d", &n);
    
    Stack* stack = createStack(n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(stack, value);
    }
    
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        pop(stack);
    }
    
    display(stack);
    
    free(stack->items);
    free(stack);
    
    return 0;
}
