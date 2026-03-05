// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* current = &dummy;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    current->next = (list1) ? list1 : list2;
    return dummy.next;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct ListNode *list1 = NULL, *current1 = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode *newNode = createNode(val);
        if (!list1) {
            list1 = newNode;
            current1 = newNode;
        } else {
            current1->next = newNode;
            current1 = newNode;
        }
    }

    scanf("%d", &m);
    struct ListNode *list2 = NULL, *current2 = NULL;
    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        struct ListNode *newNode = createNode(val);
        if (!list2) {
            list2 = newNode;
            current2 = newNode;
        } else {
            current2->next = newNode;
            current2 = newNode;
        }
    }

    struct ListNode *mergedList = mergeTwoLists(list1, list2);

    while (mergedList) {
        printf("%d ", mergedList->val);
        mergedList = mergedList->next;
    }
    printf("\n");

    return 0;
}