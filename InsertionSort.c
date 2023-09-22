#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int a[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int hole = i;
        int value = a[i];

        while (hole > 0 && a[hole - 1] > value)
        {
            a[hole] = a[hole - 1];
            hole--;
        }
        a[hole] = value;
    }
}

int main()
{
    int arr[] = {5, 3, 4, 1, 2};
    int n = sizeof(arr) / sizeof(int);
    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);
}