#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node ListNode;
typedef ListNode *ListNodePtr;

void instructions();
void insertatBeginning(ListNodePtr *sPtr, int value);
void reverse(ListNodePtr *sPtr);
void insert(ListNodePtr *sPtr,int value);
void printList(ListNodePtr sPtr);
void insertAtLast(ListNodePtr *sPtr, int value);

int main() {
    ListNodePtr startPtr = NULL;
    int choice,value;
    do{
        instructions();
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value : ");
                scanf("%d",&value);
                insert(&startPtr,value);
                printList(startPtr);
                break;
            case 2:
                printList(startPtr);
                break;
            case 3:
                reverse(&startPtr);
                printList(startPtr);
                break;
            case 4:
                printf("End.\n");
                break;
            default:
                printf("Invalid Choice -_- .\n");
        }
    }while(choice!=4);

    

    return 0;
}

void instructions(){
    printf("\n1. Insert a value\n");
    printf("2. Print the list\n");
    printf("3. Reverse the list\n");
    printf("4. Exit\n");
}

void insert(ListNodePtr *sPtr,int value) {
    ListNodePtr newNode = malloc(sizeof(ListNode));

    if (newNode == NULL) {
        printf("Unable to allocate memory\n");
    } else {
        newNode->data = value;
        newNode->next = *sPtr;
        *sPtr = newNode;
    }
}

void printList(ListNodePtr sPtr) {
    if (sPtr == NULL) {
        printf("List is Empty.\n");
    } else {
        printf("The list is: \n");
        while (sPtr != NULL) {
            printf("%d --> ", sPtr->data);
            sPtr = sPtr->next;
        }
        printf("NULL\n");
    }
}

void reverse(ListNodePtr *sPtr) {
    ListNodePtr prev = NULL;
    ListNodePtr current = *sPtr;
    ListNodePtr next = NULL;

    while (current != NULL) {
        next = current->next; // Store next
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    *sPtr = prev; // Update head to new first node
}

void insertatBeginning(ListNodePtr *sPtr, int value) {
    ListNodePtr newNode = malloc(sizeof(ListNode));

    if (newNode != NULL) {
        newNode->data = value;
        newNode->next = *sPtr;   // point to old head
        *sPtr = newNode;        // update head
    } else {
        printf("Memory not available\n");
    }
}

void insertAtLast(ListNodePtr *sPtr, int value) {
    ListNodePtr newNode = malloc(sizeof(ListNode));

    if (newNode == NULL) {
        printf("Memory not available\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if (*sPtr == NULL) {
        *sPtr = newNode;
    }
    else {
        ListNodePtr current = *sPtr;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }
}