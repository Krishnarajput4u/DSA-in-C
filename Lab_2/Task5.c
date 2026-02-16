#include<stdio.h>
union Data{
    int i;
    float f;
};
// diff bw structure and union
int main(){
    union Data data;
    data.i=10;
    printf("Integer value: %d\n", data.i);
    data.f=3.14;
    printf("Float value: %.2f\n", data.f);
    printf("Integer value after assigning float: %d\n", data.i);
    return 0;
}