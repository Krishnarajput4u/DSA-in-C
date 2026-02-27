#include<stdio.h>
#include<stdlib.h>

struct listNode{
    int data;
    struct listNode *next;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *sPtr,int value);
void printList(ListNodePtr currentPtr);
void delete(ListNodePtr *sPtr,int value);
int isEmpty(ListNodePtr *sPtr);
void deletionAtEnd(ListNodePtr *sPtr);

int main(){
    ListNodePtr startPtr=NULL;
    int choice,value;   
    do{
        printf("\n1. Insert a value\n");
        printf("2. Print the list\n");
        printf("3. Exit\n");
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
                printf("End.\n");
                break;
            default:
                printf("Invalid Choice -_- .\n");
        }   
    }while(choice!=3);
    return 0;

}

//insert function with value checking
void insert(ListNodePtr *sPtr,int value){
    ListNodePtr newNode=NULL;
    newNode=(ListNodePtr)malloc(sizeof(ListNode));
    if(newNode==NULL){
        printf("Memory allocation failed .");
    }
    else{
        newNode->data=value;
        newNode->next=NULL;
        ListNodePtr previousPtr=NULL,currentPtr=*sPtr;
        while(currentPtr!=NULL && value>currentPtr->data){
            previousPtr=currentPtr;
            currentPtr=currentPtr->next;
        }
        if(previousPtr==NULL){
            newNode->next=*sPtr;
            *sPtr=newNode;
        }
        else{
            previousPtr->next=newNode;
            newNode->next=currentPtr;
        }
    }
}

void delete(ListNodePtr *sPtr,int value){
    ListNodePtr currentPtr;
    ListNodePtr previousPtr;
    if(*sPtr!=NULL && (*sPtr)->data==value){
        currentPtr=*sPtr;
        *sPtr=(*sPtr)->next;
        free(currentPtr);
        printf("Value deleted .\n");
    }
    else{
        previousPtr=*sPtr;
        currentPtr=(*sPtr)->next;

        while(currentPtr!=NULL && currentPtr->data!=value){
            previousPtr=currentPtr;
            currentPtr=currentPtr->next;
        }
        if(currentPtr!=NULL){
            previousPtr->next=currentPtr->next;
            free(currentPtr);
            printf("Value deleted .\n");
        }
        else{
            printf("Value not found .\n");
        }
    }
}

void deletionAtEnd(ListNodePtr *sPtr) {
    if (*sPtr == NULL) {
        return; 
    }

    ListNodePtr currentPtr = *sPtr;
    ListNodePtr previousPtr = NULL;

    if (currentPtr->next == NULL) {
        free(currentPtr);
        *sPtr = NULL;
        return;
    }

    while (currentPtr->next != NULL) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->next;
    }

    free(currentPtr);
    previousPtr->next = NULL;
}

int isEmpty(ListNodePtr *sPtr){
    return *sPtr==NULL;
}