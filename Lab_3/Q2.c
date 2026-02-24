#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i;
    int *arr;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));

    printf("Enter the elements: ");
    if(arr==NULL){
        printf("Memory not allocated.\n");
        return 1;
    }
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The elements are: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}