#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>         

#define MAX 100        // Common maximum size for stacks/expressions

// ===================== STACK (ARRAY) =====================
int stackA[MAX], topA = -1; // topA = -1 means stack is empty

void pushA(int x) {          
    if (topA == MAX - 1)      
        printf("Overflow\n"); // Cannot insert because stack is full
    else {
        stackA[++topA] = x; // Move top up, then store value
        printf("Pushed: %d\n", x);
    }
}

int popA() {
    if (topA == -1) {
        printf("Underflow\n"); // Cannot remove from empty stack
        return -1; // Sentinel for invalid pop
    }
    return stackA[topA--]; // Return current top, then move top down
}

void peekA() {
    if (topA == -1)
        printf("Empty Stack\n");
    else
        printf("Top: %d\n", stackA[topA]);
}

void displayA() {
    if (topA == -1)
        printf("Empty Stack\n");
    else {
        printf("Stack: ");
        for (int i = topA; i >= 0; i--) // Print top to bottom
            printf("%d ", stackA[i]);
        printf("\n");
    }
}

// ===================== STACK (LINKED LIST) =====================
struct Node {
    int data;          // Value stored in node
    struct Node* next; // Link to next node
};

struct Node* topL = NULL;  // Head node works as top of stack

void pushL(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node)); // Allocate node
    n->data = x;
    n->next = topL; // New node points to old top
    topL = n;       // Update top
    printf("Pushed: %d\n", x);
}

void popL() {
    if (!topL) {   
        printf("Underflow\n");
        return;
    }
    struct Node* temp = topL;     // Keep old top for free()
    printf("Popped: %d\n", temp->data);
    topL = topL->next; // Move top down
    free(temp);     
}

void peekL() {
    if (!topL)
        printf("Empty Stack\n");
    else
        printf("Top: %d\n", topL->data);
}

void displayL() {
    if (!topL) {
        printf("Empty Stack\n");
        return;
    }
    struct Node* t = topL;
    printf("Stack: ");
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

// ===================== HELPER =====================
int prec(char c) {
    if (c=='+'||c=='-') return 1; // Lower precedence
    if (c=='*'||c=='/') return 2; // Higher precedence
    return 0;
}

// ===================== MODULE 1: INFIX → POSTFIX =====================
void infixToPostfix() {
    char exp[MAX], stack[MAX], res[MAX];
    int top=-1, k=0; // top for operator stack, k for result index

    printf("Enter infix: ");
    scanf("%s", exp); // Read expression without spaces

    for(int i=0; exp[i]; i++) {
        char c = exp[i];

        if(isalnum(c)) // Operand goes directly to output
            res[k++]=c;

        else if(c=='(')     // push onto stack as controls precedence of operators
            stack[++top]=c;

        else if(c==')') {
            while(top!=-1 && stack[top]!='(')
                res[k++]=stack[top--];  
            top--; // Discard '('
        }
//(2+3)*5  --- 23+5*
        else {
            while(top!=-1 && prec(stack[top])>=prec(c))  
                res[k++]=stack[top--]; // Pop stronger/equal operators
            stack[++top]=c;
        }
    }

    while(top!=-1)
        res[k++]=stack[top--];   // Pop remaining operators

    res[k]='\0'; // Null-terminate C string

    printf("Postfix: %s\n", res);
}

// ===================== MODULE 2: POSTFIX EVALUATION =====================
void evalPostfix() {
    char exp[MAX];
    int stack[MAX], top=-1;

    printf("Enter postfix: ");
    scanf("%s", exp);

    for(int i=0; exp[i]; i++) {
        if(isdigit(exp[i]))
            stack[++top]=exp[i]-'0';   // Convert digit char to integer
        else {
            int b=stack[top--]; // Right operand
            int a=stack[top--]; // Left operand

            switch(exp[i]) {    
                case '+': stack[++top]=a+b; break;
                case '-': stack[++top]=a-b; break;
                case '*': stack[++top]=a*b; break;
                case '/': stack[++top]=a/b; break;
            }
        }
    }
    printf("Result: %d\n", stack[top]); // Final answer remains at top
}

// ===================== MODULE 3: INFIX → PREFIX =====================
void reverse(char* exp) {
    int n=strlen(exp);
    for(int i=0;i<n/2;i++) { // Swap from both ends
        char t=exp[i];
        exp[i]=exp[n-i-1];
        exp[n-i-1]=t;
    }
}

void infixToPrefix() {
    char exp[MAX];
    printf("Enter infix: ");
    scanf("%s", exp);

    reverse(exp); // Step 1: reverse infix string

    for(int i=0; exp[i]; i++) {
        if(exp[i]=='(') exp[i]=')';      // Swap brackets after reverse
        else if(exp[i]==')') exp[i]='(';
    }

    char stack[MAX], res[MAX];
    int top=-1, k=0;

    for(int i=0; exp[i]; i++) {
        char c=exp[i];

        if(isalnum(c)) // Operand to output
            res[k++]=c;

        else if(c=='(')
            stack[++top]=c;

        else if(c==')') {
            while(top!=-1 && stack[top]!='(')
                res[k++]=stack[top--];
            top--; // Remove matching '('
        }

        else {
            while(top!=-1 && prec(stack[top])>=prec(c))
                res[k++]=stack[top--];
            stack[++top]=c;
        }
    }

    while(top!=-1)
        res[k++]=stack[top--];

    res[k]='\0'; // Terminate postfix of reversed expression

    reverse(res); // Step 2: reverse to obtain prefix
    printf("Prefix: %s\n", res);
}

// ===================== MODULE 4: PREFIX EVALUATION =====================
void evalPrefix() {
    char exp[MAX];
    int stack[MAX], top=-1;

    printf("Enter prefix: ");
    scanf("%s", exp);

    for(int i=strlen(exp)-1; i>=0; i--) {     // Scan prefix right to left
        if(isdigit(exp[i]))
            stack[++top]=exp[i]-'0';
        else {
            int a=stack[top--]; // First popped is left operand here
            int b=stack[top--]; // Second popped is right operand

            switch(exp[i]) {
                case '+': stack[++top]=a+b; break;
                case '-': stack[++top]=a-b; break;
                case '*': stack[++top]=a*b; break;
                case '/': stack[++top]=a/b; break;
            }
        }
    }
    printf("Result: %d\n", stack[top]);
}

// ===================== MODULE 5: STRING REVERSE =====================
void reverseString() {
    char str[MAX], stack[MAX];
    int top=-1;

    printf("Enter string: ");
    scanf("%s", str); // Reads one word (no spaces)

    for(int i=0; str[i]; i++)
        stack[++top]=str[i]; // Push all characters

    printf("Reversed: ");
    while(top!=-1)
        printf("%c", stack[top--]); // Pop in reverse order
    printf("\n");
}

// ===================== MODULE 6: UNDO / REDO =====================
char undoS[MAX][50], redoS[MAX][50];
int uTop=-1, rTop=-1; // Tops for undo and redo stacks

void type() {
    char text[200];
    printf("Enter text (space separated, e.g., A B C): ");
    while(getchar() != '\n'); // Clear leftover newline from previous scanf
    fgets(text, sizeof(text), stdin); // Read a full input line

    
    char *token = strtok(text, " \n"); // Split by spaces/newline
    int count = 0;
    while(token != NULL) {
        strcpy(undoS[++uTop], token);  // Push each typed token to undo stack
        count++;
        token = strtok(NULL, " \n");
    }

    rTop = -1; // clear redo stack

 
    printf("Typed: ");
    for(int i = uTop - count + 1; i <= uTop; i++) // Print only new tokens
        printf("%s ", undoS[i]);
    printf("\n");
}

void undo() {
    if(uTop == -1) {
        printf("Nothing to undo\n");
        return;
    }
    strcpy(redoS[++rTop], undoS[uTop]); // Move last action undo->redo
    printf("Undo \"%s\" removed\n", undoS[uTop]);
    printf("%")
    uTop--;
}

void redo() {
    if(rTop == -1) {
        printf("Nothing to redo\n");
        return;
    }
    strcpy(undoS[++uTop], redoS[rTop]); // Move last action redo->undo
    printf("Redo \"%s\" restored\n", redoS[rTop]);
    rTop--;
}

void undoRedoMenu() {
    int ch;
    while(1) {
        printf("\n--- Undo/Redo Menu ---\n");
        printf("1. Type\n2. Undo\n3. Redo\n0. Back\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: type(); break;
            case 2: undo(); break;
            case 3: redo(); break;
            case 0: return;
            default: printf("Invalid choice\n");
        }
    }
}

// ===================== MODULE 7: BALANCED PARENTHESES =====================
void checkBalance() {
    char exp[MAX], stack[MAX];
    int top=-1;

    printf("Enter expression: ");
    scanf("%s", exp);

    for(int i=0; exp[i]; i++) {
        if(exp[i]=='(')
            stack[++top]='(';
        else if(exp[i]==')') {
            if(top==-1) {
                printf("Not Balanced\n"); // Closing bracket before opening
                return;
            }
            top--; // Match one opening bracket
        }
    }

    if(top==-1)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
}

// ===================== MAIN =====================
int main() {
    int ch, val;

    while(1) {
        printf("\n===== SMART STACK SYSTEM =====\n");
        printf("1. Stack (Array)\n2. Stack (Linked List)\n");
        printf("3. Infix - Postfix\n4. Postfix Evaluation\n");
        printf("5. Infix - Prefix\n6. Prefix Evaluation\n");
        printf("7. String Reverse\n8. Undo/Redo\n");
        printf("9. Parentheses Check\n0. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1:
                // Sub-menu for array-based stack operations
                printf("\n1.Push 2.Pop 3.Peek 4.Display\n");
                printf("Enter choice: ");
                scanf("%d",&ch);

                if(ch==1){
                    printf("Enter value: ");
                    scanf("%d",&val);
                    pushA(val);
                }
                else if(ch==2)
                    printf("Popped: %d\n", popA());
                else if(ch==3)
                    peekA();
                else if(ch==4)
                    displayA();
                break;

            case 2:
                // Sub-menu for linked-list-based stack operations
                printf("\n1.Push 2.Pop 3.Peek 4.Display\n");
                printf("Enter choice: ");
                scanf("%d",&ch);

                if(ch==1){
                    printf("Enter value: ");
                    scanf("%d",&val);
                    pushL(val);
                }
                else if(ch==2)
                    popL();
                else if(ch==3)
                    peekL();
                else if(ch==4)
                    displayL();
                break;

            case 3: infixToPostfix(); break;
            case 4: evalPostfix(); break;
            case 5: infixToPrefix(); break;
            case 6: evalPrefix(); break;
            case 7: reverseString(); break;
            case 8: undoRedoMenu(); break;
            case 9: checkBalance(); break;

            case 0: exit(0); // Terminate program
            default: printf("Invalid choice\n");
        }
    }
}