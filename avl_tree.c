//
// Created by antoa on 25-02-2024.
//
#include<stdio.h>
#include<conio.h>
#include <malloc.h>

struct treenode;
typedef struct treenode *position,*avltree,ptrtonode;
struct treenode
{
    int element;
    avltree left;
    avltree right;
    int height;
};
int height(position p)
{
    if(p!=NULL)
        return p->height;
    else
        return 0;
}
int max(int h1,int h2)
{
    if(h1>h2)
        return h1;
    else
        return h2;
}
position singlelerightrotation(position k2)
{
    position k1;
    k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->height=max(height(k2->left),height(k2->right))+1;
    k1->height=max(height(k1->left),height(k1->right))+1;
    return k1;
}
position singlerileftrotation(position k1)
{
    position k2;
    k2=k1->right;
    k1->right=k2->left;
    k2->left=k1;
    k1->height=max(height(k1->left),height(k1->right))+1;
    k2->height=max(height(k2->left),height(k2->right))+1;
    return k2;
}
position doublelerightrotation(position k3)
{
    k3->left=singlerileftrotation(k3->left);
    return singlerileftrotation(k3);
}
position doublerileftrotation(position k3)
{
    k3->right=singlerileftrotation(k3->right);
    return singlerileftrotation(k3);
}
avltree insert(int x,avltree t)
{
    if(t== NULL)
    {
        t=(ptrtonode *)malloc(sizeof(struct treenode));
        if(t== NULL)
        {
            printf("\nOut of space");
        }
        else
        {
            t->element=x;
            t->left=NULL;
            t->right=NULL;
            t->height=0;
        }
    }
    else if(x<t->element)
    {
        t->left=insert(x,t->left);
        if(height(t->left)-height(t->right)== 2)
        if(x<t->left->element)
            t=singlelerightrotation(t);
        else
            t=doublelerightrotation(t);
    }
    else if(x>t->element)
    {
        t->right=insert(x,t->right);
        if(height(t->right)-height(t->left)== 2)
        if(x<t->right->element)
            t=singlerileftrotation(t);
        else
            t=doublerileftrotation(t);
    }
    t->height=max(height(t->left),height(t->right))+1;
    return t;
}
void display(avltree root)
{
    if(root!=NULL)
    {
        display(root->left);
        if(root->element== NULL)
        {
            printf("0");
        }
        else
        {
            printf("\n%d",root->element);
        }
        display(root->right);
    }
}
void main()
{
    int item;
    char ch;
    avltree t;
    position p;
    t=NULL;
    do
    {
        printf("\nEnter the item to be inserted:");
        scanf("%d",&item);
        t=insert(item,t);
        printf("\nThe item is inserted");
        printf("\nDo u want to insert the item again:(y for YES/n for NO)");
        ch=getche();
    }while(ch=='y');
    printf("\nThe AVL Tree is ..... ");
    display(t);
    getch();
}