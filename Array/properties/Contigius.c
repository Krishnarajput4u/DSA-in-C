#include<stdio.h>
int main(){
    int c[]={1,2,3,4,5};
    // for(int i=0;i<5;i++){
    //     printf("%zu \n",&c[i]);
    // }
    int *ptr=&c[1];
    int *ptr1=&c[2];
    printf("%zu\n",ptr);
    printf("%zu",ptr1);
}