// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int value) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow\n");
        return -1; // Indicate error
    }
    StackNode* temp = stack->top;
    int value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int main() {
    char postfix[100];
    Stack* stack = createStack();

    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (ch >= '0' && ch <= '9') {
            push(stack, ch - '0'); // Convert char to int
        } else if (isOperator(ch)) {
            int val2 = pop(stack);
            int val1 = pop(stack);
            int result;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }
            push(stack, result);
        }
    }

    printf("%d\n", pop(stack)); // Final result
    free(stack);
    return 0;
}

