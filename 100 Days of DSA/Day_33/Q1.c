// Problem: Convert an infix expression to postfix notation using stack.

// Input:
// - Single line: infix expression (operands are single characters)

// Output:
// - Print the postfix expression

// Example:
// Input:
// A+B*C

// Output:
// ABC*+

// Explanation:
// Operator precedence: * > +
// Use stack to handle operator precedence and associativity

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    char items[MAX];
    int top;
} Stack;

void push(Stack* s, char value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

char pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    Stack s;
    s.top = -1;
    int j = 0;

    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if ((token >= 'A' && token <= 'Z') || (token >= 'a' && token <= 'z')) {
            postfix[j++] = token; // Add operand to postfix
        } else if (token == '(') {
            push(&s, token);
        } else if (token == ')') {
            while (s.top != -1 && s.items[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Pop '('
        } else { // Operator
            while (s.top != -1 && precedence(s.items[s.top]) >= precedence(token)) {
                postfix[j++] = pop(&s);
            }
            push(&s, token);
        }
    }

    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0'; // Null-terminate the string

    printf("%s\n", postfix);
    return 0;
}

