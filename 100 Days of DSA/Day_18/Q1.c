#include<stdio.h>
#include<stdlib.h>

void reverse(int *arr,int start,int end){
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

void kshift(int *arr,int k,int num){
    reverse(arr,0,num);
    reverse(arr,0,k);
    reverse(arr,k,num);
}
int main(){
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    int *arr=malloc(num*sizeof(int));
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    int shift;
    printf("Enter the number by which you want to right shift the array : ");
    scanf("%d",&shift);
    kshift(arr,shift,num);
    for(int i=0;i<num;i++){
        printf("%d ",arr[i]);
    }
}