// 

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node ListNode;
typedef ListNode *ListNodePtr;

void push(ListNodePtr *sPtr,int value);
void display(ListNodePtr *sPtr);

int main(){
    ListNodePtr startPtr = NULL;
    int num,value;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&value);
        push(&startPtr,value);
    }
    display(&startPtr);;
    return 0;
}

void push(ListNodePtr *sPtr, int value){
    ListNodePtr newNode = malloc(sizeof(ListNode));

    if(newNode == NULL){
        printf("Memory Overflow");
        return;
    }

    newNode->data = value;

    if(*sPtr == NULL){
        newNode->next = newNode; 
        *sPtr = newNode;
    } else {
        ListNodePtr temp = *sPtr;

        while(temp->next != *sPtr){
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = *sPtr;
    }
}

void display(ListNodePtr *sPtr){
    if(*sPtr == NULL){
        printf("List is Empty !!");
        return;
    }

    ListNodePtr temp = *sPtr;

    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != *sPtr);
}