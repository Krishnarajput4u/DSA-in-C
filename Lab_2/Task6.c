#include<stdio.h>
struct s{
    int i;
    float f;
};
union u{
    int i;
    float f;
};
int main(){
    printf("Size of structure: %lu bytes\n", sizeof(struct s));
    printf("Size of union: %lu bytes\n", sizeof(union u));
    return 0;
}