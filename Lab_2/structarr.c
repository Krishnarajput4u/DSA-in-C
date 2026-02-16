#include<stdio.h>
struct student{
    int roll;
    float marks;
};
int main(){
    struct student s1[3];
    for(int i=0;i<3;i++){
        printf("Enter roll number and marks for student %d : ", i+1);
        scanf("%d %f", &s1[i].roll, &s1[i].marks);
    }
    for(int i=0;i<3;i++){
        printf("Student %d - Roll number: %d, Marks: %.2f\n", i+1, s1[i].roll, s1[i].marks);
    }
    return 0;
}