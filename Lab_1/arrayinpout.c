#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    printf("Enter the size of the array : ");
    scanf("%d",&num);
    int *arr=malloc(num*sizeof(int));
    for(int i=0;i<num;i++){
        printf("Enter the number : ");
        scanf("%d",&arr[i]);
    }
    printf("Array elements are : ");
    for(int i=0;i<num;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}