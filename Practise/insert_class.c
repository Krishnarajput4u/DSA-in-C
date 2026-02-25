#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;



void insertatBeginning(int data){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));

    if(newNode==NULL){
        printf("Memory allocation faled");
    }
    else {
        newNode->data=data;
        newNode->next=head;
        head=newNode;
    }
}

void insertatEnd(int data){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory allocation faled");
    }
    else{
        newNode->data=data;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
        }
        else{
            struct node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
}

int main(){
    int choice,value;
    do{
        printf("\n1. Insert a value at the beginning\n");
        printf("2. Insert a value at the end\n");
        printf("3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value : ");
                scanf("%d",&value);
                insertatBeginning(value);
                break;
            case 2:
                printf("Enter the value : ");
                scanf("%d",&value);
                insertatEnd(value);
                break;
            case 3:
                printf("End.\n");
                break;
            default:
                printf("Invalid Choice -_- .\n");
        }
    }while(choice!=3);
    return 0;
}