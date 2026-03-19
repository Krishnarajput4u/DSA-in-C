#include<stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1; //stack is empty

// Push operation
void push(int value){
    if (top == SIZE - 1){ // checking overflow condition 
        printf("Stack Overflow\n");
    }
    else{
        top ++;
        stack[top] = value; // used index because we are performing operation using array
        printf("%d pushed into stack\n", value);
    }
}

// Pop operation
void pop(){
    if (top == -1){ // checking underflow condition
        printf("Stack is underflow\n");
    }
    else{
        printf("%d popped from stack\n", stack[top]);
        top --;
    }
}

// Display stack
void display(){
    if (top == -1){
        printf("Stack is empty\n");
    }
    else{
        for (int i = top; i >= 0; i--){
            printf("%d\n", stack[i]);
        }
    }
}

// Main function
int main(){
    int choice, value;
    while(1){ // Infinite loop
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            printf("Enter value:\n");
            scanf("%d", &value);
            push(value);
            break;

            case 2:
            pop();
            break;

            case 3:
            display();
            break;

            case 4:
            return 0;

            default:
            printf("Invalid choice\n");
        }
    }
}