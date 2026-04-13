// Problem: Level Order Traversal

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

void levelOrderTraversal(struct node* root){
    if(root == NULL){
        return;
    }
    struct node* queue[100]; // Assuming a maximum of 100 nodes in the tree
    int front = 0, rear = 0;

    queue[rear++] = root; // Enqueue the root node

    while(front < rear){
        struct node* currentNode = queue[front++]; // Dequeue a node
        printf("%d ", currentNode->data); // Process the current node

        // Enqueue left and right children if they exist
        if(currentNode->left != NULL){
            queue[rear++] = currentNode->left;
        }
        if(currentNode->right != NULL){
            queue[rear++] = currentNode->right;
        }
    }
}

int main(){
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Level order traversal of the binary tree: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}