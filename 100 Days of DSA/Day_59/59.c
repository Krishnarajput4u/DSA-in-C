#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n, int i) {
    if (i >= n) return NULL;

    struct TreeNode* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Count nodes
int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check complete binary tree
int isComplete(struct TreeNode* root, int index, int total) {
    if (!root) return 1;

    if (index >= total) return 0;

    return isComplete(root->left, 2*index + 1, total) &&
           isComplete(root->right, 2*index + 2, total);
}

// Check heap property
int isMinHeap(struct TreeNode* root) {
    if (!root->left && !root->right)
        return 1;

    if (!root->right) {
        return (root->val <= root->left->val) &&
               isMinHeap(root->left);
    }

    return (root->val <= root->left->val &&
            root->val <= root->right->val &&
            isMinHeap(root->left) &&
            isMinHeap(root->right));
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n, 0);

    int total = countNodes(root);

    if (isComplete(root, 0, total) && isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}