//
// Created by antoa on 25-02-2024.
//
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct link
{
    int coeff;
    int pow;
    struct link *next;
};
struct link *poly1=NULL,*poly2=NULL,*poly=NULL;

void create(struct link *node)
{
    char ch;
    int i=3;
    while(i<=3&&i>=0)
    {
        printf("\nEnter the coefficient of X^%d :",i);
        scanf("%d",&node->coeff);
        node->pow=i;
        node->next=(struct link*)malloc(sizeof(struct link));
        node=node->next;
        node->next=NULL;
        i--;
    }
}
void show(struct link *node)
{
    while(node->next!=NULL)
    {
        printf("%dx^%d",node->coeff,node->pow);
        node=node->next;
        if(node->next!=NULL)
            printf(" + ");
    }
}
void polyadd(struct link *poly1,struct link *poly2,struct link *poly)
{
    while(poly1->next && poly2->next)
    {
        if(poly1->pow>poly2->pow)
        {
            poly->pow=poly1->pow;
            poly->coeff=poly1->coeff;
            poly1=poly1->next;
        }
        else if(poly1->pow<poly2->pow)
        {
            poly->pow=poly2->pow;
            poly->coeff=poly2->coeff;
            poly2=poly2->next;
        }
        else
        {
            poly->pow=poly1->pow;
            poly->coeff=poly1->coeff+poly2->coeff;
            poly1=poly1->next;
            poly2=poly2->next;
        }
        poly->next=(struct link *)malloc(sizeof(struct link));
        poly=poly->next;
        poly->next=NULL;
    }
    while(poly1->next || poly2->next)
    {
        if(poly1->next)
        {
            poly->pow=poly1->pow;
            poly->coeff=poly1->coeff;
            poly1=poly1->next;
        }
        if(poly2->next)
        {
            poly->pow=poly2->pow;
            poly->coeff=poly2->coeff;
            poly2=poly2->next;
        }
        poly->next=(struct link *)malloc(sizeof(struct link));
        poly=poly->next;
        poly->next=NULL;
    }
}
void main()
{
    char ch;
    do
    {

        poly1=(struct link *)malloc(sizeof(struct link));
        poly2=(struct link *)malloc(sizeof(struct link));
        poly=(struct link *)malloc(sizeof(struct link));
        printf("\nThe First Polynomial Number:");
        create(poly1);
        printf("\nThe Second Polynomial Number:");
        create(poly2);
        printf("\nResult\n\nThe First Polynomial Number:");
        show(poly1);
        printf("\nThe Second Polynomial Number:");
        show(poly2);
        polyadd(poly1,poly2,poly);
        printf("\nAdded polynomial Number:");
        show(poly);
        printf("\nDo u want to continue (y for YES n for NO):");
        ch=getch();
    }while(ch=='y');
}