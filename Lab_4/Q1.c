#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node ListNode;
typedef ListNode *ListNodePtr;

void search(ListNodePtr current, int value){
    while(current!=NULL){
        if(current->data==value){
            printf("Value %d found in the list.\n", value);
            return;
        }
        current=current->next;
    }
    printf("Value %d not found in the list.\n", value);
}

int main(){
    ListNodePtr head = NULL;
    ListNodePtr second = NULL;
    ListNodePtr third = NULL;
    head=(ListNodePtr)malloc(sizeof(ListNode));
    second=(ListNodePtr)malloc(sizeof(ListNode));
    third=(ListNodePtr)malloc(sizeof(ListNode));

    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    ListNodePtr current = head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    return 0;

}