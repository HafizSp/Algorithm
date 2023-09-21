#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (1)
    {
        while (i < high && a[i] < pivot)
            i++;
        while (j > low && a[j] > pivot)
            j--;

        if (i >= j)
        {
            break;
        }
        else
        {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[j], &a[low]);
    return j;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int j = partition(a, low, high);
        quickSort(a, low, j);
        quickSort(a, j + 1, high);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {9, 8, 7, 6, 4, 5, 3, 2};
    int size = sizeof(arr) / sizeof(int);
    int low = 0, high = size - 1;
    quickSort(arr, low, high);
    printArray(arr, size);
}