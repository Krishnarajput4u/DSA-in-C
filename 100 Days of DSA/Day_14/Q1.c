#include<stdio.h>

int main(){
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    if(rows != cols){
        printf("Not Identity Matrix\n");
        return 0;
    }
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j]!=1 && i==j){
                printf("Not Identity Matrix\n");
                return 0;
            }
            else if(matrix[i][j]!=0 && i!=j){
                printf("Not Identity Matrix\n");
                return 0;
            }
        }
    }
    printf("Identity Matrix\n");
    return 0;
}