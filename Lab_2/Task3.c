#include<stdio.h>
typedef struct employee{
    int id;
    float salary;
}Employee;

int main(){
    Employee emp1;
    emp1.id=1;
    emp1.salary=50000.0;
    printf("Employee ID: %d\n", emp1.id);
    printf("Employee Salary: %.2f\n", emp1.salary);
    return 0;
}