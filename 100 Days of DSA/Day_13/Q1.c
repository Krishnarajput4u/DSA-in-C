// Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

// Input:
// - First line: two integers r and c representing the number of rows and columns
// - Next r lines: c integers each representing the matrix elements

// Output:
// - Print all visited elements in the order of traversal, separated by spaces

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 1 2 3 6 9 8 7 4 5

// Explanation:
// The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

// Test Cases:

// Test Case 1:
// Input:
// 2 3
// 1 2 3
// 4 5 6
// Output:
// 1 2 3 6 5 4

// Test Case 2:
// Input:
// 3 1
// 7
// 8
// 9
// Output:
// 7 8 9

#include <stdio.h>
#include <stdbool.h>

int main(){
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    while(top <= bottom && left <= right){
        // Traverse from left to right
        for(int i = left; i <= right; i++){
            printf("%d ", matrix[top][i]);
        }
        top++;

        // Traverse from top to bottom
        for(int i = top; i <= bottom; i++){
            printf("%d ", matrix[i][right]);
        }
        right--;

        if(top <= bottom){
            // Traverse from right to left
            for(int i = right; i >= left; i--){
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        if(left <= right){
            // Traverse from bottom to top
            for(int i = bottom; i >= top; i--){
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }

    return 0;
}