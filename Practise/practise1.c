#include<stdio.h>
#include<stdlib.h>

struct listNode{
    int data;
    struct listNode *next;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void delete(ListNodePtr *sPtr,int value);
void insert(ListNodePtr *sPtr,int value);
void printList(ListNodePtr currentPtr);
int isEmpty(ListNodePtr *sPtr);
void instructions();

int main(){
    int choice,value;
    ListNodePtr startPtr = NULL;
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
                printf("Enter the value to delete : ");
                scanf("%d",&value);
                delete(&startPtr,value);
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
    printf("3. Delete a value\n");
    printf("4. Exit\n");
}

void insert(ListNodePtr *sPtr,int value){
    ListNodePtr newNode=NULL;
    if(newNode==NULL){
        printf("Memory allocation failed .");
    }
    else{
        newNode->data=value;
        newNode->next=*sPtr;
        *sPtr=newNode;
    }
}

void 
