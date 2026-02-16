#include<stdio.h>
#include<stdlib.h>

struct listNode{
    int data;
    struct listNode *nextPtr; 
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *sPtr, int value);
void delete(ListNodePtr *sPtr, int value);
void printList(ListNodePtr currentPtr);
int isEmpty(ListNodePtr sPtr);

int main(){
    ListNodePtr startPtr =NULL;
    int choice,item;

    do{
        printf("\nEnter your choice:\n");
        printf("1 Insert\n");
        printf("Delete\n");
        printf("3 Print\n");
        printf("4 Exit\n");
        printf("? ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the value to insert : ");
                scanf("%d",&item);
                insert(&startPtr,item);
                break;
            case 2:
                printf("Enter the value to delte : ");
                scanf("%d",&item);
                delete(&startPtr,&item);
                break;
            case 3:
                printList(startPtr);
                break;
            case 4:
                printf("End of run.\n");
                break;
            default:
                printf("Invalid choice");
        }   
    } while(choice!=4);
    return 0;
}

void insert(ListNodePtr *sPtr , int value){
    ListNodePtr newPtr;
    newPtr=malloc(sizeof(ListNode));

    if(newPtr!=NULL){
        newPtr->data=value;
        newPtr->nextPtr=*sPtr;
        *sPtr=newPtr;    
    } else{
        printf("Memory not available.\n");
    }
}

void delete(ListNodePtr *sPtr,int value){
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;

    if(*sPtr != NULL && (*sPtr)->data ==value){
        currentPtr=*sPtr;
        *sPtr=(*sPtr)->nextPtr;
        free(currentPtr);
        printf("Value deleted.\n");
    } else {
        previousPtr = *sPtr;
        currentPtr= (*sPtr)->nextPtr;

        while(currentPtr != NULL && currentPtr->data != value){
            previousPtr =currentPtr;
            currentPtr=currentPtr->nextPtr;
        }

        if (currentPtr != NULL){
            previousPtr->nextPtr=currentPtr->nextPtr;
            free(currentPtr);
            printf("Value deleted.\n");

        } else{
            printf("Value not found.\n");
        }
    }
}

void printList(ListNodePtr currentPtr){
    if(isEmpty(currentPtr)){
        printf("List is empty.\n");
    } else {
        printf("The list is:\n");

        while(currentPtr != NULL){
            printf("%d -->",currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        printf("NULL\n");
    }
}

int isEmpty(ListNodePtr sPtr){
    return sPtr == NULL;
}