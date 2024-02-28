//
// Created by antoa on 25-02-2024.
//
#include<stdio.h>
#include<conio.h>
void SelectionSort (int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = i+1; j < n; ++j)
        {
            if (arr[i] > arr[j])
            {
                arr[i] = arr[i]+arr[j];
                arr[j] = arr[i]-arr[j];
                arr[i] = arr[i]-arr[j];
            }
        }
    }
}
int main()
{
    int n, i;
    printf("\nEnter the number of data element to be sorted: ");
    scanf("%d",&n);
    int arr[10];
    for(i = 0; i <n ; i++)
    {
        printf("Enter %d element:",i+1);
        scanf("%d",&arr[i]);
    }
    SelectionSort(arr, n);
    printf("\nSorted Data:\n");
    for (i = 0; i < n; i++)
        printf("%d \t ",arr[i]);
    getch();
}