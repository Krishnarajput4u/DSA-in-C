#include<stdio.h>
int iterativeSum(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum += i;
    }
    return sum;
}
int recursiveSum(int n){
    if(n==1){
        return 1;
    }
    return n + recursiveSum(n-1);
}
int main(){
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    int choice;
    if(num<0){
        printf("Not valid");
        return 1;
    }
    printf("Enter your choice ",
    "1. Iterative",
    "2. Recursive");
    if(choice==1){
        printf("Sum of first %d natural numbers is: %d\n",num,iterativeSum(num));
    }
    else{
        printf("Sum of first %d natural numbers is: %d\n",num,recursiveSum(num));
    }
    return 0;
}