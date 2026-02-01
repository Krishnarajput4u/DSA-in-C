#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    printf("Enter the size of the array : ");
    scanf("%d",&num);
    int *arr = (int *)malloc((num+1) * sizeof(int));
    for(int i=0;i<num;i++){
        printf("Enter the number : ");
        scanf("%d",&arr[i]);
    }
    int index;
    printf("Enter the index Number where you want to enter the number : ");
    scanf("%d",&index);
    int num1;
    printf("Enter the number : ");
    scanf("%d",&num1);
    for(int i=num;i>=index;i--){
        arr[i]=arr[i-1];
    }
    arr[index-1]=num1;
    for(int i=0;i<num+1;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}