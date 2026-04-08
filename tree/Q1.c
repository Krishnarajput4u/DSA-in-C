#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node* right;
    struct node* left;
};

typedef struct node Tree;
typedef Tree *TreePtr;

void instructions(){
    printf("\n1. Add\n2. Delete\n3. Exit\n");
}

void createNode(TreePtr *root,char data);
void traverse(TreePtr *root,char data);
void delete(TreePtr *root,char value);

int main(){
    TreePtr root=NULL;
    int choice;
    char value;
    while(1){
        instruction();
        switch(choice){
            case 1:
                printf("Enter the value : ");
                scanf("%c",&value);
                createNode(&root,value);
                break;
            case 2:
                printf("Enter the value : ");
                scanf("%c",&value);
                delete(&root,value);
                break;
            case 3:
                printf("Thank you !!");
                return 0;
        }
    }
}

void createNode(TreePtr *root,char data){

}

void traverse(TreePtr *root,char data){

}
void delete(TreePtr *root,char value){
    
}