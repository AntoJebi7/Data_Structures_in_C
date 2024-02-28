//
// Created by antoa on 25-02-2024.
//
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;
void insert();
void delete();
void display();

void main ()
{
    int choice;
    while(choice != 4)
    {
        printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",& choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nEnter valid choice");
        }
    }
}
void insert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOVERFLOW");
        return;
    }
    else
    {
        printf("\nEnter value:");
        scanf("%d",&item);
        ptr -> data = item;
        if(front == NULL)
        {
            front = ptr;
            rear = ptr;
            front -> next = NULL;
            rear -> next = NULL;
        }
        else
        {
            rear -> next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}
void delete ()
{
    struct node *ptr;
    if(front == NULL)
    {
        printf("\nUNDERFLOW");
        return;
    }
    else
    {
        ptr = front;
        front = front -> next;
        free(ptr);
    }
    printf("The Element is Deleted");
}
void display()
{
    struct node *ptr;
    ptr = front;
    if(front == NULL)
    {
        printf("\nEmpty queue");
    }
    else
    {
        printf("\nprinting values ..... \n");
        while(ptr != NULL)
        {
            printf("%d \t",ptr -> data);
            ptr = ptr -> next;
        }}
}