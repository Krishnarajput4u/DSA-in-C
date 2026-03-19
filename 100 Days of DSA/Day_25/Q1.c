// Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of nodes)
// - Second line: n space-separated integers (linked list elements)
// - Third line: integer key (element to be counted)

// Output:
// - Print the number of times the key appears in the linked list

// Example:
// Input:
// 6
// 10 20 30 20 40 20
// 20

// Output:
// 3

// Explanation:
// Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. 
// After traversal, print the final count.
#include<stdio.h>
#include<stdlib.h>

struct listnode{
    int data;
    struct listnode *next;
};
typedef struct listnode ListNode;
typedef ListNode *ListNodePtr;

void createlist(ListNodePtr *sPtr,int value);
int counter(ListNodePtr *sPtr,int tofind);

int main(){
    ListNodePtr startPtr=NULL;
    int num,value;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&value);
        createlist(&startPtr,value);
    }
    int tofind;
    scanf("%d",&tofind);
    int count=counter(&startPtr,tofind);
    printf("%d",count);
    return 0;
}

void createlist(ListNodePtr *sPtr,int value){
    ListNodePtr newNode=malloc(sizeof(ListNode));
    if(newNode==NULL){
        printf("Memory allocation failed!! ");
    } else {
        newNode->data=value;
        newNode->next=NULL;
        if(*sPtr==NULL){
            *sPtr=newNode;
        } else{
            ListNodePtr temp=*sPtr;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
}

int counter(ListNodePtr *sPtr,int tofind){
    int count=0;
    ListNodePtr temp=*sPtr;
    while(temp!=NULL){
        if(temp->data==tofind){
            count++;
        }
        temp=temp->next;
    }
    return count;
}