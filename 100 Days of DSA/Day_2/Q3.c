/*Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left*/

#include <stdio.h>
int main(){
    int num;
    printf("Enter the size of the array : ");
    scanf("%d",&num);
    int arr[num];
    for(int i=0;i<num;i++){
        printf("Enter the number : ");
        scanf("%d",&arr[i]);
    }
    int target;
    printf("Enter the target :");
    scanf("%d",&target);
    --target;
    for(int i=target;i<num-1;i++){
        arr[i]=arr[i+1];
    }
    for(int i=0;i<num-1;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}