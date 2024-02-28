//
// Created by antoa on 25-02-2024.
//
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define maxs 5
int stack[maxs];
int top = -1;
void push(){
    int element;
    if(top>=maxs-1){
        printf("stack is full");
    }else{
        printf("enter the element to be push :  ");
        scanf("%d",&element);
        top = top + 1;
        stack[top]=element;
    }
}
void pop(){
    int poped;
    if(top==-1){
        printf("stack is empty");
    }else{
        poped = stack[top];
        top=top-1;
        printf("popped element is %d ", poped);
    }
}
void display(){
    int i=0;
    if(top==-1)
    {
        printf("\nThe Stack is Empty\n\n");
    }
    else
    {
        while(i<=top)
        {
            printf("%d\t",stack[i]);
            i++;
        }
    }
}

void main(){
    int choice;
    while(choice!=5){
        printf("1.push\n2.pop\n3.display\n4.exit\n");
        printf("enter your choice");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
        }
        getch();
    }
}