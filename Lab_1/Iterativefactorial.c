#include<stdio.h>
int factorial(int n){
    int result=1;
    for(int i=1;i<=n;i++){
        result=result*i;
    }
    return result;
}
int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    printf("Factorial of %d is: %d\n",n,factorial(n));
    return 0;
}