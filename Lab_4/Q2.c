#include<stdio.h>
#include<stdlib.h>

struct listnode{
    int data;
    struct listnode *next;
    struct listnode *prev;
};
typedef struct listnode ListNode;
typedef ListNode *ListNodePtr;

int main(){
    ListNodePtr head = NULL;
    ListNodePtr second = NULL;
    ListNodePtr third = NULL;
    head=(ListNodePtr)malloc(sizeof(ListNode));
    second=(ListNodePtr)malloc(sizeof(ListNode));
    third=(ListNodePtr)malloc(sizeof(ListNode));

    head->data=10;
    head->next=second;
    head->prev=NULL;

    second->data=20;
    second->next=third;
    second->prev=head;
    
    third->data=30;
    third->next=NULL;
    third->prev=second;

    ListNodePtr current = head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    return 0;

}