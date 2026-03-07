#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node ListNode;
typedef ListNode *ListNodePtr;

void createList(ListNodePtr *sPtr, int value)
{
    ListNodePtr newNode = malloc(sizeof(ListNode));

    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if(*sPtr == NULL){
        *sPtr = newNode;
    }
    else{
        ListNodePtr temp = *sPtr;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void deleteNode(ListNodePtr *sPtr,int value)
{
    if(*sPtr == NULL)
        return;

    ListNodePtr currentPtr = *sPtr;
    ListNodePtr previousPtr = NULL;

    while(currentPtr != NULL && currentPtr->data != value){
        previousPtr = currentPtr;
        currentPtr = currentPtr->next;
    }

    if(currentPtr == NULL){
        printf("Value doesn't exist\n");
    }
    else{
        if(previousPtr == NULL)
            *sPtr = currentPtr->next;
        else
            previousPtr->next = currentPtr->next;

        free(currentPtr);
    }
}

void display(ListNodePtr *sPtr)
{
    if(*sPtr == NULL){
        printf("Empty List");
    }
    else{
        ListNodePtr temp = *sPtr;

        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    ListNodePtr startPtr = NULL;
    int inputs, value;

    scanf("%d",&inputs);

    for(int i=0;i<inputs;i++){
        scanf("%d",&value);
        createList(&startPtr,value);
    }

    int deletenum;
    scanf("%d",&deletenum);

    deleteNode(&startPtr,deletenum);

    display(&startPtr);

    return 0;
}