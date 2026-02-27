// Comparing 2 list

#include<stdio.h>
#include<stdlib.h>

struct listNode{
    int data;
    struct listNode *next;
};
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;
void createList(ListNodePtr *sPtr){
    for(int i=0;i<5;i++){
        ListNodePtr newNode=NULL;
        newNode=(ListNodePtr)malloc(sizeof(ListNode));
        if(newNode==NULL){
            printf("Memory allocation failed .");
        }
        else{
            newNode->data=i+1;
            newNode->next=NULL;
            ListNodePtr previousPtr=NULL,currentPtr=*sPtr;
            while(currentPtr!=NULL && (i+1)>currentPtr->data){
                previousPtr=currentPtr;
                currentPtr=currentPtr->next;
            }
            if(previousPtr==NULL){
                newNode->next=*sPtr;
                *sPtr=newNode;
            }
            else{
                previousPtr->next=newNode;
                newNode->next=currentPtr;
            }
        }
    }
}
int Identical(ListNodePtr *a,ListNodePtr *b){
    ListNodePtr a1=*a;
    ListNodePtr b1=*b;
    while(a1!=NULL && b1!=NULL){
        if(a1->data != b1->data)
            return 1;
        a1=a1->next;
        b1=b1->next;
    }
    if(a1==NULL && b1==NULL){
        return 0;
    }
}
int main(){
    ListNodePtr a=NULL,b=NULL;
    createList(&a);
    createList(&b);

    if(Identical(&a,&b)==0){
        printf("Equal");

    }else{
        printf("Not equal");
    }
}
