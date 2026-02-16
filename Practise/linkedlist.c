#include<stdio.h>

struct listnode{
    int data;
    struct listnode* next;
};

typedef struct listnode ListNode;
typedef ListNode *ListNodeptr;

void insert(ListNodeptr *sPtr,int value);
void instructions(void);
void delete(ListNodeptr *sPtr,int value);
int isEmpty(ListNodeptr *sPtr);
void display(ListNodeptr currentptr);

int main(){
    int choice,value;
    ListNodeptr startptr=NULL;
    do{
        printf("\nEnter your choice:\n");
        printf("1 Insert\n");
        printf("2 Delete\n");
        printf("3 Print\n");
        printf("4 Exit\n");
        printf("? ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter an integer: ");
                scanf("%d",&value);
                insert(&startptr,value);
                break;
            case 2:
                printf("Enter an integer: ");
                scanf("%d",&value);
                delete(&startptr,value);
                break;
            case 3:
                display(startptr);
                break;
            case 4:
                printf("End of run.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }while(choice != 4);
    return 0;
}

void insert(ListNodeptr *sPtr,int value){
    ListNodeptr newptr;
    newptr=malloc(sizeof(ListNode));
    if(newptr!=NULL){
        newptr->data=value;
        newptr->next=*sPtr;
        *sPtr=newptr;
    }
    else{
        printf("%d not inserted. No memory available.\n",value);
    }
}

void delete(ListNodeptr *sPtr,int value){
    ListNodeptr previousptr;
    ListNodeptr currentptr;
    ListNodeptr tempPtr;

    if(isEmpty(sPtr)){
        printf("List is empty.\n");
    }
    else{
        if((*sPtr)->data==value){
            tempPtr=*sPtr;
            *sPtr=(*sPtr)->next;
            free(tempPtr);
        }
        else{
            previousptr=*sPtr;
            currentptr=(*sPtr)->next;

            while(currentptr!=NULL && currentptr->data!=value){
                previousptr=currentptr;
                currentptr=currentptr->next;
            }
            if(currentptr!=NULL){
                tempPtr=currentptr;
                previousptr->next=currentptr->next;
                free(tempPtr);
            }
            else{
                printf("%d not found.\n",value);
            }
        }
    }
}

int isEmpty(ListNodeptr *sPtr){
    return *sPtr==NULL;
}

void display(ListNodeptr currentptr){
    if(isEmpty(&currentptr)){
        printf("List is empty.\n");
    }
    else{
        printf("The list is:\n");
        while(currentptr!=NULL){
            printf("%d --> ",currentptr->data);
            currentptr=currentptr->next;
        }
        printf("NULL\n");
    }
}

