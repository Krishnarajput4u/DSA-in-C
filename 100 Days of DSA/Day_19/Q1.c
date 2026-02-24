#include<stdio.h>
#include<stdlib.h>

int absVal(int x){
    return (x < 0) ? -x : x;
}

int main(){
    int num;
    printf("Enter the size of the array : ");
    scanf("%d",&num);

    if(num < 2){
        printf("Need at least 2 elements.");
        return 0;
    }

    int *arr = malloc(num * sizeof(int));

    for(int i = 0; i < num; i++){
        scanf("%d", &arr[i]);
    }

    int element1 = arr[0], element2 = arr[1];
    int minSum = arr[0] + arr[1];

    for(int i = 0; i < num - 1; i++){
        for(int j = i + 1; j < num; j++){
            int currentSum = arr[i] + arr[j];

            if(absVal(currentSum) < absVal(minSum)){
                minSum = currentSum;
                element1 = arr[i];
                element2 = arr[j];
            }
        }
    }

    printf("The pair whose sum is closest to zero is: %d %d",
           element1, element2);

    free(arr);
    return 0;
}