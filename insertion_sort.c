//
// Created by antoa on 25-02-2024.
//
#include<stdio.h>
#include<conio.h>
void insert(int[],int);
void main(){
    int a[20],i,n;
    printf("\nEnter the size of an array:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter the %d element in the array:",i+1);
        scanf("%d",&a[i]);
    }
    insert(a,n);
    getch();
}
void insert(int a[],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=a[i];
        for(j=i-1;j>=0;j--){
            if(a[j]>temp){
                a[j+1]=a[j];
            }
            else
                break;
        }
        a[j+1]=temp;
    }
    printf("\nData After Insertion sort\n");
    for(i=0;i<n;i++)
        printf("%d\t", a[i]);
}