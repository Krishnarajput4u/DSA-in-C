#include <stdio.h>
#include <stdlib.h> 

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;
typedef Node* NodePtr;

void insert(NodePtr* head, int value);

int main() {
    NodePtr head = NULL;
    int n, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&head, value);
    }

    // Traverse circular linked list
    if (head != NULL) {
        NodePtr temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    return 0;
}

void insert(NodePtr* head, int value) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!!");
        return;
    }

    newNode->data = value;

    // Case 1: Empty list
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;  // Point to itself
    } 
    else {
        NodePtr temp = *head;

        // Traverse to last node
        while (temp->next != *head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = *head;  // Maintain circular link
    }
}