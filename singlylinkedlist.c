//
// Created by antoa on 25-02-2024.
//
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
    int data;
    struct node *nextpoint;
}*head,*new,*old,*temp;
void insert(){
    int element;
    printf("enter the elemnt to insert");
    scanf("%d",&element);
    if(head==NULL){
        temp = (node *)malloc(sizeof(struct node));
        temp->data=element;
        temp->nextpoint=NULL;
        head = temp;
    }else{
        temp = head;
        while(temp->nextpoint!=NULL){
            temp=temp->nextpoint;
        }
        new = (node *) malloc(sizeof(struct node));
        new->data=element;
        new->nextpoint=NULL;
        temp->nextpoint=new;
    }
}
void delete(){
    int num ,flag =0;
    temp = head;
    printf("enter the element to delete");
    scanf("%d",&num);
    if(temp==NULL){
        printf("list is empty");
    }else {
        while (temp != NULL) {
            if (temp->data == num) {
                if (temp == head) {
                    head = temp->nextpoint;
                } else {
                    old->nextpoint = temp->nextpoint;
                }
                free(temp);
                flag = 1;
            }
            old=temp;
            temp=temp->nextpoint;
        }
        if(flag==0){
            printf("element not found");
        } else{
            printf("element deleted");
        }
    }
}
void display(){
    temp = head;
    if(temp == NULL){
        printf("list is empty");
    } else{
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->nextpoint;
        }
    }
}

void main(){
    int ch;
    char cho;
    do
    {
        printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit");
        printf("\nEnter your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                break;
            case 2:delete();
                break;
            case 3:display();
                break;
            case 4:exit(0);
                break;
            default:
                printf("\nINVALID CHOICE");
        }
        printf("\nDo u want to continue(y for YES/n for NO) :");
        cho=getch();
    }while(cho=='y');
    getch();
}


