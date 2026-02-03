#include<stdio.h>
int main(){
    int num;
    printf("Enter the number of inputs you want to enter : ");
    scanf("%d",&num);
    int input;
    int sum=0,i;
    for(i=1;i<=num;i++){
        scanf("%d",&input);
        sum+=input;
    }
    printf("Sum is %d Average is %d",sum,sum/num);
}