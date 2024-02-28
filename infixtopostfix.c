//
// Created by antoa on 25-02-2024.
//
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 25
int s[MAX],top=-1;
char post[MAX],b[MAX];

int pre(char a) {
    int b;
    switch (a) {
        case '(': b = 0;
            break;
        case '+':
        case '-': b = 1;
            break;
        case '*':
        case '/': b = 2;
            break;
        case '^': b = 3;
            break;
    }
    return b;
}
int alphanum(char a)
{
    return ((a>='a'&&a<='z')||(a>='A'&&a<='Z'));
}
int opr(char a)
{
    int b=0;
    switch(a)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            b=1;
            break;
    }
    return b;
}
void intopost()
{
    char a,in[25];
    int i,ti=-1,tp=-1;
    s[++top]='(';
    printf("\nEnter the Infix Expression:\n");
    scanf("%s",&in);
    while(in[++ti]!='\0')
    {
        if(alphanum(in[ti]))
        {
            post[++tp]=in[ti];
        }
        else if(opr(in[ti]))
        {
            while(pre(in[ti])<=pre(s[top]))
            {
                post[++tp]=s[top--];
            }
            s[++top]=in[ti];
        }
        else if(in[ti]=='(')
        {
            s[++top]='(';
        }
        else if(in[ti]==')')
        {
            while(s[top]!='(')
            {
                post[++tp]=s[top--];
            }
            top--;
        }
        else
        {
            printf("\nInvalid Expression\n");
        }
    }
    while(s[top]!='(')
    {
        post[++tp]=s[top--];
    }
    post[++tp]='\0';
    printf("\nPostFix Expression is :%s",post);
    for(i=0;i<strlen(post);i++)
    {
        b[i]=post[i];
    }
}
void main()
{
    char a,post[25];
    intopost();
    getch();
}