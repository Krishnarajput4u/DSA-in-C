// Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

// Input:
// - First line: two integers m and n
// - Next m lines: n integers each

// Output:
// - Print the sum of the primary diagonal elements

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 15

// Explanation:
// 1 + 5 + 9 = 15
#include<stdio.h>

int main(){
    int row,column,sum=0;
    scanf("%d %d",&row,&column);

    if(row!=column){
        printf("Primary diagonal is defined only for square matrices");
        return 0;
    }

    int arr[row][column];

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i=0;i<row;i++){
        sum+=arr[i][i];
    }

    printf("%d",sum);

    return 0;
}