#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* ================= DISPLAY ================= */
void printList() {
    struct node *p = head;
    printf("\n[ ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]");
}

/* ================= INSERTIONS ================= */

// Insert at beginning
void insertatbegin(int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertatend(int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert after given node
void insertafternode(struct node *prevNode, int data) {
    if (prevNode == NULL) return;

    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

/* ================= DELETIONS ================= */

// Delete at beginning
void deleteatbegin() {
    if (head == NULL) return;

    struct node *temp = head;
    head = head->next;
    free(temp);
}

// Delete at end
void deleteatend() {
    if (head == NULL) return;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Delete by key
void deletenode(int key) {
    struct node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

/* ================= SEARCH ================= */

int searchlist(int key) {
    struct node *temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}

/* ================= REVERSE ================= */

void reverseList() {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

/* ================= MAIN ================= */

int main() {

    // Insert operations
    insertatbegin(12);
    insertatbegin(22);
    insertatend(30);
    insertatend(44);
    insertatbegin(50);

    printf("Initial Linked List:");
    printList();

    // Insert after second node
    if (head != NULL && head->next != NULL)
        insertafternode(head->next, 33);

    printf("\nAfter inserting 33:");
    printList();

    // Delete operations
    deleteatbegin();
    deleteatend();
    deletenode(12);

    printf("\nAfter deletions:");
    printList();

    // Search
    if (searchlist(33))
        printf("\nElement 33 found");
    else
        printf("\nElement 33 not found");

    // Reverse
    reverseList();

    printf("\nAfter reversal:");
    printList();

    return 0;
}