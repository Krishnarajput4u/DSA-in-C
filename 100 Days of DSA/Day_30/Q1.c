#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    int power;
    struct node* next;
};

typedef struct node ListNode;
typedef ListNode* ListNodePtr;

void createNode(ListNodePtr *sPtr,int data,int power);
void display(ListNodePtr *sPtr);

int main(){
    ListNodePtr startPtr = NULL;
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        int data,power;
        scanf("%d %d",&data,&power);
        createNode(&startPtr,data,power);
    }
    display(&startPtr);
    return 0;
}

void createNode(ListNodePtr *sPtr,int data,int power){
    ListNodePtr newNode=malloc(sizeof(ListNode));
    if(newNode==NULL){
        printf("Memory Allocation Failed!!");
        return;
    }
    newNode->value=data;
    newNode->power=power;
    newNode->next=NULL;
    if(*sPtr==NULL){
        *sPtr=newNode;
    }
    else{
        ListNodePtr temp=*sPtr;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void display(ListNodePtr *sPtr){
    ListNodePtr temp = *sPtr;

    while(temp != NULL){
        printf("%dx^%d", temp->value, temp->power);

        if(temp->next != NULL){
            printf(" + ");
        }

        temp = temp->next;
    }
}