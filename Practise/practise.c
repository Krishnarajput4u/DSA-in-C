#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node *next;

}*header;

void createList(int n);

int main(){
    int n;
    printf("Enter the total number of nodes : ");
    scanf("%d",&n);
    createList(n);
    return 0;
}

void createList(int n){
    
}