#include <stdio.h>
#include <stdlib.h>

// Definition of BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into BST
struct Node* insert(struct Node* root, int value) {
    // If tree is empty
    if (root == NULL) {
        return createNode(value);
    }

    // Insert in left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // Insert in right subtree
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Inorder traversal (for checking)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    int n, value;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Print inorder traversal
    inorder(root);

    return 0;
}