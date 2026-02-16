#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    printf("Enter the size of the array : ");
    scanf("%d",&num);
    int *arr= malloc(num*sizeof(int));
    for(int i=0;i<num;i++){
        printf("Enter the number : ");
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    int min=arr[0];
    for(int i=1;i<num;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    printf("Maximum number is %d\n", max);
    printf("Minimum number is %d\n", min);
    free(arr);
    return 0;
}