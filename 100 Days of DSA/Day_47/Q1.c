// Problem: Height of Binary Tree

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;

};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(struct node* root){
    if(root == NULL){
        return -1; // Return -1 for null nodes to count edges
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1; // Add 1 for the current node
}

int main(){
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int treeHeight = height(root);
    printf("Height of the binary tree: %d\n", treeHeight);

    return 0;
}