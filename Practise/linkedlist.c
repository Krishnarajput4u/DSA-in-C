#include<stdio.h>
#include<stdlib.h>

struct listNode{
    int data;
    struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void delete(ListNodePtr *sPtr,int value);
void insert(ListNodePtr *sPtr,int value);
void printList(ListNodePtr *currentPtr);
int isEmpty();
void instructions(){
    printf("1. Insert\n2. Delete\n3.Print\n4.Exit\n");
}



int main(){
    int choice,value;
    ListNodePtr startPtr=NULL;
    do{
        instructions();
        printf("Enter the choice : ");
        scanf("%d,&choice");
        switch(choice){
            case 1:
                printf("Enter the Value : ");
                scanf("%d",&value);
                insert(&startPtr,value);
                break;
            case 2:
                printf("Enter the Value :");
                scanf("%d",&value);
                delete(&startPtr,&value);
                break;
            case 3:
                printList(&startPtr);
                break;
            case 4:
                printf("Thank you \n");
                break;
            default:
                printf("Invalid Choice -_- !!\n");
        }
    }while(choice!=4);
    return 0;
}


void insert(ListNodePtr *sPtr,int value){
    ListNodePtr newPtr;
    newPtr=malloc(sizeof(ListNode));
    if(newPtr==NULL){
        printf("Unable to allocate memory ");
    } else{
        newPtr->data=value;
        newPtr->nextPtr=*sPtr;
        *sPtr=newPtr;
    }
}