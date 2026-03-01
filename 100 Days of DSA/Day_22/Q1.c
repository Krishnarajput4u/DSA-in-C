// Problem: Count Nodes in Linked List

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the result

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int main(){
    int num;
    printf("Enter the size of the array : ");
    scanf("%d",&num);
    struct Node* head=NULL;
    struct Node* temp=NULL;
    for(int i=0;i<num;i++){
        int value;
        scanf("%d",&value);
        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=value;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
            temp=head;
        }
        else{
            temp->next=newNode;
            temp=temp->next;
        }
    }
    int count=0;
    temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    printf("Number of nodes in the linked list: %d\n",count);
    return 0;
}
