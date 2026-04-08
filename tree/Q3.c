#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

typedef struct node Tree;
typedef Tree *TreePtr;

void instructions(){
    printf("\n1. Add\n2. Delete\n3. Exit\n");
}

void createNode(TreePtr *root,int value);

int main(){
    TreePtr root=NULL;
    int num;
    int value;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&value);
        createNode(&root,value);
    }
    return 0;
}

void createNode(TreePtr *root,int value){
    if(*root==NULL){
        TreePtr newNode=malloc(sizeof(Tree));
        if(newNode==NULL){
            printf("Memory allocation failed!! ");
            return;
        }
        *root=newNode;
        newNode->data=value;
        newNode->right=NULL;
        newNode->left=NULL;
        return;
    } else{
        if(value<(*root)->data){
            createNode(&((*root)->left),value);
        }else{
            createNode(&((*root)->right),value);
        }
    }
}

