#include<stdio.h>

void func(int *p){
    for(int i=0;i<5;i++){
        printf("%d ",*(p+i));
    }
}

int main(){
    int a[]={1,2,3,4,5};
    func(a);
}