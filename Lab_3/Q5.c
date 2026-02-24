#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    int*arr=(int*)malloc(num*sizeof(int));
    if(arr==NULL){
        printf("Memory not allocated.\n");
        return 1;
    }
    printf("Enter the elements:\n");
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    for(int i=1;i<num;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    printf("The largest element is: %d\n",max);
    free(arr);
    return 0;
}