#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;

};
struct node *top=NULL;
 
void push(int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=top;
    top=newnode;
    printf("%d pushed into the stack",value);

}

void pop(){
    struct node *temp;
    if(top==NULL){
        printf("stack is underflow");}

    else {
            temp=top;
            printf("%d is popped from stack", top->data);
            top=top->next;
            free(temp);

        }
    }

    void display(){
        struct node *temp=top;
        if(temp==NULL){
            printf("stack is empty");

        }
        else{
            while(temp!=NULL){
                printf("%d\n",temp->data);
                temp=temp->next;

            }
        }
    }

int main(){
    
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    pop();
    display();

}