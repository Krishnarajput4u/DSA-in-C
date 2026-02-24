#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i;
    int*arr;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    arr=(int*)calloc(n,sizeof(int));
    if(arr==NULL){
        printf("Memory not allocated.\n");
        return 1;
    }
    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The elements are:\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}