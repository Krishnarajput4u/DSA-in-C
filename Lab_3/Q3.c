#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,i,sum=0;
    int*arr;

    scanf("%d",&n);
    arr=calloc(n,sizeof(int));

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    printf("Sum=%d\n",sum);
    free(arr);
    
    return 0;
}