#include <stdio.h>
#include <stdlib.h>

/* Structure definition for a stack node */
struct stackNode {
    int data;                     // Value stored in the stack
    struct stackNode *nextPtr;    // Pointer to the next node
};

/* Type definitions for convenience */
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

/* Function prototypes */
void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);

int main(void) {

    StackNodePtr stackPtr = NULL;   // Pointer to top of stack (initially empty)
    int choice;                     // User menu choice
    int value;                      // Value to be pushed

    instructions();
    printf("? ");
    scanf("%d", &choice);

    /* Loop until user chooses to end program */
    while (choice != 3) {

        switch (choice) {

            case 1:   // Push operation
                printf("Enter an integer: ");
                scanf("%d", &value);
                push(&stackPtr, value);
                printStack(stackPtr);
                break;

            case 2:   // Pop operation
                if (!isEmpty(stackPtr)) {
                    printf("The popped value is %d\n", pop(&stackPtr));
                } else {
                    puts("Stack is empty. Nothing to pop.");
                }
                printStack(stackPtr);
                break;

            default:  // Invalid input
                puts("Invalid choice.");
                instructions();
                break;
        }
        scanf("%d", &choice);
    }

    puts("End of run.");
    return 0;
}

/* Displays menu options to the user */
void instructions(void) {
    puts("Enter choice:");
    puts("1 - Push");
    puts("2 - Pop");
    puts("3 - End program");
}

/* Pushes a value onto the stack */
void push(StackNodePtr *topPtr, int info) {

    StackNodePtr newPtr = malloc(sizeof(StackNode)); // Allocate memory

    /* Check if memory allocation was successful */
    if (newPtr != NULL) {
        newPtr->data = info;        // Store value
        newPtr->nextPtr = *topPtr;  // Link new node to previous top
        *topPtr = newPtr;           // Update top pointer
    } else {
        printf("%d not inserted. No memory available.\n", info);
    }
}

/* Pops (removes) the top value from the stack */
int pop(StackNodePtr *topPtr) {

    StackNodePtr tempPtr = *topPtr; // Temporarily store top node
    int popValue = tempPtr->data;   // Retrieve value

    *topPtr = tempPtr->nextPtr;     // Move top pointer down
    free(tempPtr);                  // Free removed node

    return popValue;                // Return popped value
}

/* Prints the contents of the stack */
void printStack(StackNodePtr currentPtr) {

    if (currentPtr == NULL) {
        puts("The stack is empty.");
    } else {
        puts("The stack is:");

        /* Traverse and print stack */
        while (currentPtr != NULL) {
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        puts("NULL");
    }
}

/* Checks if the stack is empty */
int isEmpty(StackNodePtr topPtr) {
    return topPtr == NULL;
}