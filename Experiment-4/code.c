#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// ==================== PART A - ARRAY QUEUE ====================
int arr[MAX];
int front_a = -1, rear_a = -1;

void array_enqueue(int value) {
    if (rear_a == MAX - 1) {
        printf("Array Queue Overflow!!\n");
        return;
    }
    if (front_a == -1) front_a = 0;
    arr[++rear_a] = value;
}

void array_dequeue() {
    if (front_a == -1) {
        printf("Array Queue Underflow!!\n");
        return;
    }
    printf("Removed: %d\n", arr[front_a]);
    if (front_a == rear_a) front_a = rear_a = -1;
    else front_a++;
}

void array_peek() {
    if (front_a == -1) printf("Array Queue is empty!\n");
    else printf("Front: %d\n", arr[front_a]);
}

void array_display() {
    if (front_a == -1) {
        printf("Array Queue is empty!\n");
        return;
    }
    printf("Array Queue: ");
    for (int i = front_a; i <= rear_a; i++) printf("%d ", arr[i]);
    printf("\n");
}

// ==================== PART A - LINKED LIST QUEUE ====================
struct node { int data; struct node *next; };
typedef struct node* NodePtr;
NodePtr front_ll = NULL;
NodePtr rear_ll = NULL;

void ll_enqueue(int value) {
    NodePtr newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (!front_ll) front_ll = rear_ll = newNode;
    else { rear_ll->next = newNode; rear_ll = newNode; }
}

void ll_dequeue() {
    if (!front_ll) {
        printf("Linked List Queue is empty!\n");
        return;
    }
    NodePtr temp = front_ll;
    printf("Removed: %d\n", temp->data);
    front_ll = front_ll->next;
    free(temp);
    if (!front_ll) rear_ll = NULL;
}

void ll_peek() {
    if (!front_ll) printf("Linked List Queue is empty!\n");
    else printf("Front: %d\n", front_ll->data);
}

void ll_display() {
    if (!front_ll) {
        printf("Linked List Queue is empty!\n");
        return;
    }
    NodePtr temp = front_ll;
    printf("Linked List Queue: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ==================== PART B - CIRCULAR QUEUE ====================
int circ_queue[MAX];
int front_c = -1, rear_c = -1;

void circ_enqueue(int value) {
    if ((rear_c + 1) % MAX == front_c) {
        printf("Circular Queue FULL!\n");
        return;
    }
    if (front_c == -1) front_c = 0;
    rear_c = (rear_c + 1) % MAX;
    circ_queue[rear_c] = value;
}

void circ_dequeue() {
    if (front_c == -1) {
        printf("Circular Queue Empty!\n");
        return;
    }
    printf("Removed: %d\n", circ_queue[front_c]);
    if (front_c == rear_c) front_c = rear_c = -1;
    else front_c = (front_c + 1) % MAX;
}

void circ_display() {
    if (front_c == -1) {
        printf("Circular Queue Empty!\n");
        return;
    }
    printf("Circular Queue: ");
    int i = front_c;
    while (1) {
        printf("%d ", circ_queue[i]);
        if (i == rear_c) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// ==================== MODULE 5 - QUEUE USING TWO STACKS ====================
typedef struct {
    int data[MAX];
    int top;
} Stack;

typedef struct {
    Stack inStack;   // New items are pushed here.
    Stack outStack;  // Items are dequeued from here.
} TwoStackQueue;

TwoStackQueue q;

void init_two_stack_queue() {
    q.inStack.top = -1;
    q.outStack.top = -1;
}

int stack_is_empty(Stack *s) {
    return s->top == -1;
}

int stack_is_full(Stack *s) {
    return s->top == MAX - 1;
}

void stack_push(Stack *s, int value) {
    if (stack_is_full(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->data[++s->top] = value;
}

int stack_pop(Stack *s) {
    if (stack_is_empty(s)) return -1;
    return s->data[s->top--];
}

void move_in_to_out() {
    while (!stack_is_empty(&q.inStack)) {
        stack_push(&q.outStack, stack_pop(&q.inStack));
    }
}

void two_stack_enqueue(int value) {
    if (stack_is_full(&q.inStack)) {
        printf("Queue Overflow!\n");
        return;
    }
    stack_push(&q.inStack, value);
}

void two_stack_dequeue() {
    if (stack_is_empty(&q.outStack)) {
        move_in_to_out();
    }

    if (stack_is_empty(&q.outStack)) {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Removed: %d\n", stack_pop(&q.outStack));
}

void two_stack_display() {
    if (stack_is_empty(&q.inStack) && stack_is_empty(&q.outStack)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue (FIFO): ");

    // outStack top is the current front of queue.
    for (int i = q.outStack.top; i >= 0; i--) {
        printf("%d ", q.outStack.data[i]);
    }

    // inStack bottom has older items than inStack top.
    for (int i = 0; i <= q.inStack.top; i++) {
        printf("%d ", q.inStack.data[i]);
    }

    printf("\n");
}

// ==================== PART B - APPLICATION MODULES ====================
int main() {
    int choice;
    init_two_stack_queue();
    while (1) {
        printf("\n=== Queue Implementation ===\n");
        printf("1. Part A - Queue Operations\n");
        printf("2. Part B - Ticket Counter\n");
        printf("3. Part B - CPU Scheduling\n");
        printf("4. Part B - Printer Queue\n");
        printf("5. Part B - Circular Queue\n");
        printf("6. Module 5 - Queue using Two Stacks\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int subChoice, val;
                while (1) {
                    printf("\n--- Part A: Queue Operations ---\n");
                    printf("1. Array Queue\n");
                    printf("2. Linked List Queue\n");
                    printf("3. Back to Main Menu\n");
                    printf("Enter choice: ");
                    scanf("%d", &subChoice);
                    
                    if (subChoice == 1) {
                        int aChoice;
                        while (1) {
                            printf("\n--- Array Queue Operations ---\n");
                            printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Back\n");
                            printf("Enter choice: ");
                            scanf("%d", &aChoice);
                            if (aChoice == 1) { printf("Enter value: "); scanf("%d", &val); array_enqueue(val); }
                            else if (aChoice == 2) array_dequeue();
                            else if (aChoice == 3) array_peek();
                            else if (aChoice == 4) array_display();
                            else if (aChoice == 5) break;
                        }
                    }
                    else if (subChoice == 2) {
                        int lChoice;
                        while (1) {
                            printf("\n--- Linked List Queue Operations ---\n");
                            printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Back\n");
                            printf("Enter choice: ");
                            scanf("%d", &lChoice);
                            if (lChoice == 1) { printf("Enter value: "); scanf("%d", &val); ll_enqueue(val); }
                            else if (lChoice == 2) ll_dequeue();
                            else if (lChoice == 3) ll_peek();
                            else if (lChoice == 4) ll_display();
                            else if (lChoice == 5) break;
                        }
                    }
                    else if (subChoice == 3) break;
                }
                break;
            }
            case 2: {
                int subChoice, queueType, ch, val;
                while (1) {
                    printf("\n--- Part B: Applications ---\n");
                    printf("1. Ticket Counter\n");
                    printf("2. Back to Main Menu\n");
                    printf("Enter choice: ");
                    scanf("%d", &subChoice);
                    
                    if (subChoice == 1) {
                        printf("\n--- Choose Queue Type ---\n");
                        printf("1. Array Queue\n2. Linked List Queue\n");
                        printf("Enter choice: ");
                        scanf("%d", &queueType);
                        
                        if (queueType == 1) {
                            int innerChoice;
                            while (1) {
                                printf("\n--- Ticket Counter (Array Queue) ---\n");
                                printf("1. Add Customer\n2. Serve Customer\n3. Display\n4. Back\n5. Exit\n");
                                printf("Enter choice: ");
                                scanf("%d", &innerChoice);
                                if (innerChoice == 1) { printf("Enter Customer ID: "); scanf("%d", &val); array_enqueue(val); }
                                else if (innerChoice == 2) array_dequeue();
                                else if (innerChoice == 3) array_display();
                                else if (innerChoice == 4) break;
                                else if (innerChoice == 5) goto exitApp;
                            }
                        }
                        else if (queueType == 2) {
                            int innerChoice;
                            while (1) {
                                printf("\n--- Ticket Counter (Linked List Queue) ---\n");
                                printf("1. Add Customer\n2. Serve Customer\n3. Display\n4. Back\n5. Exit\n");
                                printf("Enter choice: ");
                                scanf("%d", &innerChoice);
                                if (innerChoice == 1) { printf("Enter Customer ID: "); scanf("%d", &val); ll_enqueue(val); }
                                else if (innerChoice == 2) ll_dequeue();
                                else if (innerChoice == 3) ll_display();
                                else if (innerChoice == 4) break;
                                else if (innerChoice == 5) goto exitApp;
                            }
                        }
                    }
                    else if (subChoice == 2) break;
                }
                // Shared exit point for "Exit" option from inner application menus.
                exitApp:;
                break;
            }
            case 3: {
                int n, val, ch;
                while (1) {
                    printf("\n--- CPU Scheduling (FCFS) ---\n");
                    printf("1. Add Processes\n2. Display\n3. Back\n");
                    printf("Enter choice: ");
                    scanf("%d", &ch);
                    if (ch == 1) {
                        printf("Enter number of processes: ");
                        scanf("%d", &n);
                        for (int i = 0; i < n; i++) {
                            printf("Enter Process ID %d: ", i + 1);
                            scanf("%d", &val);
                            array_enqueue(val);
                        }
                        printf("\nProcess Execution Order:\n");
                        while (front_a != -1) array_dequeue();
                    }
                    else if (ch == 2) array_display();
                    else if (ch == 3) break;
                }
                break;
            }
            case 4: {
                int ch, val;
                while (1) {
                    printf("\n--- Printer Queue ---\n");
                    printf("1. Add Job\n2. Print Job\n3. Display Jobs\n4. Back\n");
                    printf("Enter choice: ");
                    scanf("%d", &ch);
                    if (ch == 1) { printf("Enter Job ID: "); scanf("%d", &val); array_enqueue(val); }
                    else if (ch == 2) array_dequeue();
                    else if (ch == 3) array_display();
                    else if (ch == 4) break;
                }
                break;
            }
            case 5: {
                int ch, val;
                while (1) {
                    printf("\n--- Circular Queue ---\n");
                    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back\n");
                    printf("Enter choice: ");
                    scanf("%d", &ch);
                    if (ch == 1) { printf("Enter value: "); scanf("%d", &val); circ_enqueue(val); }
                    else if (ch == 2) circ_dequeue();
                    else if (ch == 3) circ_display();
                    else if (ch == 4) break;
                }
                break;
            }
            case 6: {
                int ch, val;
                while (1) {
                    printf("\n--- Module 5: Queue using Two Stacks ---\n");
                    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back\n");
                    printf("Enter choice: ");
                    scanf("%d", &ch);
                    if (ch == 1) { printf("Enter value: "); scanf("%d", &val); two_stack_enqueue(val); }
                    else if (ch == 2) two_stack_dequeue();
                    else if (ch == 3) two_stack_display();
                    else if (ch == 4) break;
                    else printf("Invalid choice!\n");
                }
                break;
            }
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}