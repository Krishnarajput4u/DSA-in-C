#include<stdio.h>
int main(){
    int arr[]={2,3,4,5,6};
    int n= sizeof(arr)/sizeof(arr[0]);
    printf("%d",n);
}