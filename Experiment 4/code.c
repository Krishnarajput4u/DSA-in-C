#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// ==================== PART A - ARRAY QUEUE ====================
int arr[MAX];
int front_a = -1, rear_a = -1;

// Add an item at the rear of the array queue.
void array_enqueue(int value) {
    if (rear_a == MAX - 1) {
        printf("Array Queue Overflow!!\n");
        return;
    }
    if (front_a == -1) front_a = 0;
    arr[++rear_a] = value;
}

// Remove an item from the front of the array queue.
void array_dequeue() {
    if (front_a == -1) {
        printf("Array Queue Underflow!!\n");
        return;
    }
    printf("Removed: %d\n", arr[front_a]);
    if (front_a == rear_a) front_a = rear_a = -1;
    else front_a++;
}

// Show the current front item of the array queue.
void array_peek() {
    if (front_a == -1) printf("Array Queue is empty!\n");
    else printf("Front: %d\n", arr[front_a]);
}

// Print all items from front to rear in the array queue.
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

// Insert a new node at the rear of the linked-list queue.
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

// Delete the front node from the linked-list queue.
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

// Show the current front node value.
void ll_peek() {
    if (!front_ll) printf("Linked List Queue is empty!\n");
    else printf("Front: %d\n", front_ll->data);
}

// Traverse and print all nodes in the linked-list queue.
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

// ==================== PART A - CIRCULAR LINKED LIST QUEUE ====================
NodePtr circ_front = NULL;
NodePtr circ_rear = NULL;

// Insert into circular linked-list queue at the rear.
void circ_ll_enqueue(int value) {
    NodePtr newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    
    if (!circ_front) {
        circ_front = circ_rear = newNode;
        newNode->next = newNode;  // Point to itself
    } else {
        newNode->next = circ_front;  // New node points to front
        circ_rear->next = newNode;   // Rear points to new node
        circ_rear = newNode;         // Update rear
    }
}

// Remove the front node while preserving circular links.
void circ_ll_dequeue() {
    if (!circ_front) {
        printf("Circular Linked List Queue is empty!\n");
        return;
    }
    
    printf("Removed: %d\n", circ_front->data);
    
    if (circ_front == circ_rear) {
        // Only one node
        free(circ_front);
        circ_front = circ_rear = NULL;
    } else {
        NodePtr temp = circ_front;
        circ_front = circ_front->next;
        circ_rear->next = circ_front;  // Update rear's next pointer
        free(temp);
    }
}

// Show the front element in circular linked-list queue.
void circ_ll_peek() {
    if (!circ_front) printf("Circular Linked List Queue is empty!\n");
    else printf("Front: %d\n", circ_front->data);
}

// Display circular linked-list queue once around the loop.
void circ_ll_display() {
    if (!circ_front) {
        printf("Circular Linked List Queue is empty!\n");
        return;
    }
    
    printf("Circular Linked List Queue: ");
    NodePtr temp = circ_front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != circ_front);
    printf("\n");
}

// ==================== PART B - CIRCULAR QUEUE ====================
int circ_queue[MAX];
int front_c = -1, rear_c = -1;

// Enqueue into array-based circular queue.
void circ_enqueue(int value) {
    if ((rear_c + 1) % MAX == front_c) {
        printf("Circular Queue FULL!\n");
        return;
    }
    if (front_c == -1) front_c = 0;
    rear_c = (rear_c + 1) % MAX;
    circ_queue[rear_c] = value;
}

// Dequeue from array-based circular queue.
void circ_dequeue() {
    if (front_c == -1) {
        printf("Circular Queue Empty!\n");
        return;
    }
    printf("Removed: %d\n", circ_queue[front_c]);
    if (front_c == rear_c) front_c = rear_c = -1;
    else front_c = (front_c + 1) % MAX;
}

// Display all values in circular queue from front to rear.
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

// ==================== QUEUE RESET FUNCTIONS ====================
// Reset array queue indexes.
void reset_array_queue() {
    front_a = -1;
    rear_a = -1;
}

// Free all linked-list queue nodes and reset pointers.
void reset_linked_list_queue() {
    while (front_ll) {
        NodePtr temp = front_ll;
        front_ll = front_ll->next;
        free(temp);
    }
    front_ll = NULL;
    rear_ll = NULL;
}

// Reset circular array queue indexes.
void reset_circular_queue() {
    front_c = -1;
    rear_c = -1;
}

// Free every node from circular linked-list queue safely.
void reset_circular_linked_list_queue() {
    if (!circ_front) return;
    
    NodePtr temp = circ_front->next;
    circ_front->next = NULL;  // Break the circular link
    
    while (temp) {
        NodePtr next = temp->next;
        free(temp);
        temp = next;
    }
    
    free(circ_front);
    circ_front = NULL;
    circ_rear = NULL;
}

// ==================== MODULE 5 - QUEUE USING TWO STACKS ====================
typedef struct stack_node {
    int data;
    struct stack_node *next;
} StackNode;

typedef struct {
    StackNode *top;
} Stack;

typedef struct {
    Stack inStack;   // New items are pushed here.
    Stack outStack;  // Items are dequeued from here.
} TwoStackQueue;

TwoStackQueue q;

// Initialize both internal stacks as empty.
void init_two_stack_queue() {
    q.inStack.top = NULL;
    q.outStack.top = NULL;
}

// Return 1 if stack has no items.
int stack_is_empty(Stack *s) {
    return s->top == NULL;
}

// Push a value onto a linked-list stack.
void stack_push(Stack *s, int value) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop and return top value; return -1 when empty.
int stack_pop(Stack *s) {
    if (stack_is_empty(s)) {
        return -1;
    }
    StackNode *temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

// Free all nodes in a linked-list stack.
void clear_stack(Stack *s) {
    while (!stack_is_empty(s)) {
        stack_pop(s);
    }
}

// Transfer elements so queue dequeue order is preserved.
void move_in_to_out() {
    while (!stack_is_empty(&q.inStack)) {
        stack_push(&q.outStack, stack_pop(&q.inStack));
    }
}

// Enqueue into two-stack queue by pushing into input stack.
void two_stack_enqueue(int value) {
    stack_push(&q.inStack, value);
}

// Dequeue from two-stack queue, moving elements when required.
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

// Print stack values from top to bottom.
void print_stack_top_to_bottom(StackNode *top) {
    StackNode *curr = top;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

// Print stack values from bottom to top using recursion.
void print_stack_bottom_to_top(StackNode *top) {
    if (!top) {
        return;
    }
    print_stack_bottom_to_top(top->next);
    printf("%d ", top->data);
}

// Print queue order by reading output stack first, then input stack.
void two_stack_display() {
    if (stack_is_empty(&q.inStack) && stack_is_empty(&q.outStack)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue (FIFO): ");

    // outStack top is the current front of queue.
    print_stack_top_to_bottom(q.outStack.top);

    // inStack bottom has older items than inStack top.
    print_stack_bottom_to_top(q.inStack.top);

    printf("\n");
}

// Reset queue implemented using two linked-list stacks.
void reset_two_stack_queue() {
    clear_stack(&q.inStack);
    clear_stack(&q.outStack);
}

// ==================== PART B - APPLICATION MODULES ====================
int main() {
    int choice;
    init_two_stack_queue();

    // Main application loop.
    while (1) {
        printf("\n=== Queue Implementation ===\n");
        printf("1. Part A - Queue Operations(Array and Linked List)\n");
        printf("2. Part B - Ticket Counter\n");
        printf("3. Part B - CPU Scheduling\n");
        printf("4. Part B - Printer Queue\n");
        printf("5. Part B - Circular Queue\n");
        printf("6. Module 5 - Queue using Two Stacks\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Route control to selected module.
        switch (choice) {
            case 1: {
                int subChoice, val;
            // Start module with clean queue state.
                reset_array_queue();
                reset_linked_list_queue();
                while (1) {
                    printf("\n--- Part A: Queue Operations ---\n");
                    printf("1. Array Queue\n");
                    printf("2. Linked List Queue\n");
                    printf("3. Back to Main Menu\n");
                    printf("Enter choice: ");
                    scanf("%d", &subChoice);
                    
                    // Choose array-queue or linked-list queue operations.
                    switch(subChoice){
                        case 1: {
                            int aChoice;
                            while (1) {
                                printf("\n--- Array Queue Operations ---\n");
                                printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Back\n");
                                printf("Enter choice: ");
                                scanf("%d", &aChoice);

                                // Array queue operations menu.
                                switch (aChoice) {
                                    case 1:
                                        printf("Enter value: ");
                                        scanf("%d", &val);
                                        array_enqueue(val);
                                        break;
                                    case 2:
                                        array_dequeue();
                                        break;
                                    case 3:
                                        array_peek();
                                        break;
                                    case 4:
                                        array_display();
                                        break;
                                    case 5:
                                        break;
                                    default:
                                        printf("Invalid input!\n");
                                }

                                // Back to Part A menu.
                                if (aChoice == 5) break;
                            }
                            break;
                        }
                    
                        case 2: {
                            int lChoice;
                            while (1) {
                                printf("\n--- Linked List Queue Operations ---\n");
                                printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Back\n");
                                printf("Enter choice: ");
                                scanf("%d", &lChoice);

                                // Linked-list queue operations menu.
                                switch (lChoice) {
                                    case 1:
                                        printf("Enter value: ");
                                        scanf("%d", &val);
                                        ll_enqueue(val);
                                        break;
                                    case 2:
                                        ll_dequeue();
                                        break;
                                    case 3:
                                        ll_peek();
                                        break;
                                    case 4:
                                        ll_display();
                                        break;
                                    case 5:
                                        break;
                                    default:
                                        printf("Invalid input!\n");
                                }

                                // Back to Part A menu.
                                if (lChoice == 5) break;
                            }
                            break;
                        }
                    
                        case 3: 
                            break;
                        default: printf("Invalid input!\n");
                    }
                    // Return to main menu from Part A.
                    if (subChoice == 3) break;
                }
                break;
            }
            case 2: {
                int subChoice, queueType, val;
                // Start module with clean queue state.
                reset_array_queue();
                reset_linked_list_queue();
                while (1) {
                    printf("\n--- Part B: Applications ---\n");
                    printf("1. Ticket Counter\n");
                    printf("2. Back to Main Menu\n");
                    printf("Enter choice: ");
                    scanf("%d", &subChoice);

                    switch (subChoice) {
                        case 1:
                            printf("\n--- Choose Queue Type ---\n");
                            printf("1. Array Queue\n2. Linked List Queue\n");
                            printf("Enter choice: ");
                            scanf("%d", &queueType);

                            // Select implementation type.
                            switch (queueType) {
                                case 1: {
                                    int innerChoice;
                                    while (1) {
                                        printf("\n--- Ticket Counter (Array Queue) ---\n");
                                        printf("1. Add Customer\n2. Serve Customer\n3. Display\n4. Back\n5. Exit\n");
                                        printf("Enter choice: ");
                                        scanf("%d", &innerChoice);

                                        // Ticket counter actions using array queue.
                                        switch (innerChoice) {
                                            case 1:
                                                printf("Enter Customer ID: ");
                                                scanf("%d", &val);
                                                array_enqueue(val);
                                                break;
                                            case 2:
                                                array_dequeue();
                                                break;
                                            case 3:
                                                array_display();
                                                break;
                                            case 4:
                                                break;
                                            case 5:
                                                goto exitApp;
                                            default:
                                                printf("Invalid input!\n");
                                        }

                                        // Back to queue type selection.
                                        if (innerChoice == 4) break;
                                    }
                                    break;
                                }
                                case 2: {
                                    int innerChoice;
                                    while (1) {
                                        printf("\n--- Ticket Counter (Linked List Queue) ---\n");
                                        printf("1. Add Customer\n2. Serve Customer\n3. Display\n4. Back\n5. Exit\n");
                                        printf("Enter choice: ");
                                        scanf("%d", &innerChoice);

                                        // Ticket counter actions using linked-list queue.
                                        switch (innerChoice) {
                                            case 1:
                                                printf("Enter Customer ID: ");
                                                scanf("%d", &val);
                                                ll_enqueue(val);
                                                break;
                                            case 2:
                                                ll_dequeue();
                                                break;
                                            case 3:
                                                ll_display();
                                                break;
                                            case 4:
                                                break;
                                            case 5:
                                                goto exitApp;
                                            default:
                                                printf("Invalid input!\n");
                                        }

                                        // Back to queue type selection.
                                        if (innerChoice == 4) break;
                                    }
                                    break;
                                }
                                default:
                                    printf("Invalid input!\n");
                            }
                            break;
                        case 2:
                            break;
                        default:
                            printf("Invalid input!\n");
                    }

                    // Return to main menu from Ticket Counter module.
                    if (subChoice == 2) break;
                }
                // Shared exit point for "Exit" option from inner application menus.
                exitApp:;
                break;
            }
            case 3: {
                int subChoice, queueType, val, n, ch;
                // Start module with clean queue state.
                reset_array_queue();
                reset_linked_list_queue();
                while (1) {
                    printf("\n--- CPU Scheduling (FCFS) ---\n");
                    printf("1. Choose Queue Type\n");
                    printf("2. Back to Main Menu\n");
                    printf("Enter choice: ");
                    scanf("%d", &subChoice);

                    switch (subChoice) {
                        case 1:
                            printf("\n--- Choose Queue Type ---\n");
                            printf("1. Array Queue\n2. Linked List Queue\n");
                            printf("Enter choice: ");
                            scanf("%d", &queueType);

                            // Select implementation type for FCFS queue.
                            switch (queueType) {
                                case 1: {
                                    while (1) {
                                        printf("\n--- CPU Scheduling (Array Queue) ---\n");
                                        printf("1. Add Processes\n2. Display\n3. Remove Process\n4. Back\n");
                                        printf("Enter choice: ");
                                        scanf("%d", &ch);

                                        // CPU scheduling actions using array queue.
                                        switch (ch) {
                                            case 1:
                                                printf("Enter number of processes: ");
                                                scanf("%d", &n);
                                                for (int i = 0; i < n; i++) {
                                                    printf("Enter Process ID %d: ", i + 1);
                                                    scanf("%d", &val);
                                                    array_enqueue(val);
                                                }
                                                break;
                                            case 2:
                                                array_display();
                                                break;
                                            case 3:
                                                array_dequeue();
                                                break;
                                            case 4:
                                                break;
                                            default:
                                                printf("Invalid input!\n");
                                        }

                                        // Back to queue type selection.
                                        if (ch == 4) break;
                                    }
                                    break;
                                }
                                case 2: {
                                    while (1) {
                                        printf("\n--- CPU Scheduling (Linked List Queue) ---\n");
                                        printf("1. Add Processes\n2. Display\n3. Remove Process\n4. Back\n");
                                        printf("Enter choice: ");
                                        scanf("%d", &ch);

                                        // CPU scheduling actions using linked-list queue.
                                        switch (ch) {
                                            case 1:
                                                printf("Enter number of processes: ");
                                                scanf("%d", &n);
                                                for (int i = 0; i < n; i++) {
                                                    printf("Enter Process ID %d: ", i + 1);
                                                    scanf("%d", &val);
                                                    ll_enqueue(val);
                                                }
                                                break;
                                            case 2:
                                                ll_display();
                                                break;
                                            case 3:
                                                ll_dequeue();
                                                break;
                                            case 4:
                                                break;
                                            default:
                                                printf("Invalid input!\n");
                                        }

                                        // Back to queue type selection.
                                        if (ch == 4) break;
                                    }
                                    break;
                                }
                                default:
                                    printf("Invalid input!\n");
                            }
                            break;
                        case 2:
                            break;
                        default:
                            printf("Invalid input!\n");
                    }

                    // Return to main menu from CPU scheduling module.
                    if (subChoice == 2) break;
                }
                break;
            }
            case 4: {
                int subChoice, queueType, val, ch;
                // Start module with clean queue state.
                reset_array_queue();
                reset_linked_list_queue();
                while (1) {
                    printf("\n--- Printer Queue ---\n");
                    printf("1. Choose Queue Type\n");
                    printf("2. Back to Main Menu\n");
                    printf("Enter choice: ");
                    scanf("%d", &subChoice);

                    switch (subChoice) {
                        case 1:
                            printf("\n--- Choose Queue Type ---\n");
                            printf("1. Array Queue\n2. Linked List Queue\n");
                            printf("Enter choice: ");
                            scanf("%d", &queueType);

                            // Select implementation type for printer queue.
                            switch (queueType) {
                                case 1: {
                                    while (1) {
                                        printf("\n--- Printer Queue (Array) ---\n");
                                        printf("1. Add Job\n2. Print Job\n3. Display Jobs\n4. Back\n");
                                        printf("Enter choice: ");
                                        scanf("%d", &ch);

                                        // Printer queue actions using array queue.
                                        switch (ch) {
                                            case 1:
                                                printf("Enter Job ID: ");
                                                scanf("%d", &val);
                                                array_enqueue(val);
                                                break;
                                            case 2:
                                                array_dequeue();
                                                break;
                                            case 3:
                                                array_display();
                                                break;
                                            case 4:
                                                break;
                                            default:
                                                printf("Invalid input!\n");
                                        }

                                        // Back to queue type selection.
                                        if (ch == 4) break;
                                    }
                                    break;
                                }
                                case 2: {
                                    while (1) {
                                        printf("\n--- Printer Queue (Linked List) ---\n");
                                        printf("1. Add Job\n2. Print Job\n3. Display Jobs\n4. Back\n");
                                        printf("Enter choice: ");
                                        scanf("%d", &ch);

                                        // Printer queue actions using linked-list queue.
                                        switch (ch) {
                                            case 1:
                                                printf("Enter Job ID: ");
                                                scanf("%d", &val);
                                                ll_enqueue(val);
                                                break;
                                            case 2:
                                                ll_dequeue();
                                                break;
                                            case 3:
                                                ll_display();
                                                break;
                                            case 4:
                                                break;
                                            default:
                                                printf("Invalid input!\n");
                                        }

                                        // Back to queue type selection.
                                        if (ch == 4) break;
                                    }
                                    break;
                                }
                                default:
                                    printf("Invalid input!\n");
                            }
                            break;
                        case 2:
                            break;
                        default:
                            printf("Invalid input!\n");
                    }

                    // Return to main menu from printer queue module.
                    if (subChoice == 2) break;
                }
                break;
            }
            case 5: {
                int subChoice, queueType, val, ch;
                // Start module with clean queue state.
                reset_circular_queue();
                reset_circular_linked_list_queue();
                while (1) {
                    printf("\n--- Circular Queue ---\n");
                    printf("1. Choose Queue Type\n");
                    printf("2. Back to Main Menu\n");
                    printf("Enter choice: ");
                    scanf("%d", &subChoice);

                    switch (subChoice) {
                        case 1:
                            printf("\n--- Choose Queue Type ---\n");
                            printf("1. Array Circular Queue\n2. Circular Linked List Queue\n");
                            printf("Enter choice: ");
                            scanf("%d", &queueType);

                            // Select circular queue implementation type.
                            switch (queueType) {
                                case 1: {
                                    while (1) {
                                        printf("\n--- Circular Queue (Array) ---\n");
                                        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back\n");
                                        printf("Enter choice: ");
                                        scanf("%d", &ch);

                                        // Circular queue actions using array implementation.
                                        switch (ch) {
                                            case 1:
                                                printf("Enter value: ");
                                                scanf("%d", &val);
                                                circ_enqueue(val);
                                                break;
                                            case 2:
                                                circ_dequeue();
                                                break;
                                            case 3:
                                                circ_display();
                                                break;
                                            case 4:
                                                break;
                                            default:
                                                printf("Invalid input!\n");
                                        }

                                        // Back to queue type selection.
                                        if (ch == 4) break;
                                    }
                                    break;
                                }
                                case 2: {
                                    while (1) {
                                        printf("\n--- Circular Queue (Circular Linked List) ---\n");
                                        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back\n");
                                        printf("Enter choice: ");
                                        scanf("%d", &ch);

                                        // Circular queue actions using circular linked list.
                                        switch (ch) {
                                            case 1:
                                                printf("Enter value: ");
                                                scanf("%d", &val);
                                                circ_ll_enqueue(val);
                                                break;
                                            case 2:
                                                circ_ll_dequeue();
                                                break;
                                            case 3:
                                                circ_ll_display();
                                                break;
                                            case 4:
                                                break;
                                            default:
                                                printf("Invalid input!\n");
                                        }

                                        // Back to queue type selection.
                                        if (ch == 4) break;
                                    }
                                    break;
                                }
                                default:
                                    printf("Invalid input!\n");
                            }
                            break;
                        case 2:
                            break;
                        default:
                            printf("Invalid input!\n");
                    }

                    // Return to main menu from circular queue module.
                    if (subChoice == 2) break;
                }
                break;
            }
            case 6: {
                int ch, val;
                reset_two_stack_queue();
                while (1) {
                    printf("\n--- Module 5: Queue using Two Stacks ---\n");
                    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back\n");
                    printf("Enter choice: ");
                    scanf("%d", &ch);

                    // Two-stack queue operation menu.
                    switch (ch) {
                        case 1:
                            printf("Enter value: ");
                            scanf("%d", &val);
                            two_stack_enqueue(val);
                            break;
                        case 2:
                            two_stack_dequeue();
                            break;
                        case 3:
                            two_stack_display();
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid input!\n");
                    }

                    // Return to main menu from module 5.
                    if (ch == 4) break;
                }
                break;
            }
            case 7: exit(0);
            default: printf("Invalid input!\n");
        }
    }
    return 0;
}