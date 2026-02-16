#include<stdio.h>
typedef struct student{
    int roll;
    float marks;
}Student;

int main(){
    int num;
    printf("Enter the number of students : ");
    scanf("%d",&num);
    Student *s= malloc(num*sizeof(Student));
    for(int i=0;i<num;i++){
        printf("Enter roll number and marks for student %d : ", i+1);
        scanf("%d %f", &s[i].roll, &s[i].marks);
    }
    float max=s[0].marks;
    int max_index=0;
    for(int i=0;i<num;i++){
        if(s[i].marks>max){
            max=s[i].marks;
            max_index=i;
        }
    }
    printf("The highest marks of the student %d are : %.2f\n", s[max_index].roll, max);
    free(s);
    return 0;
}