#include <stdio.h>

void marge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int b[high + 1];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }

    while (j <= high)
    {
        b[k++] = a[j++];
    }

    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
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

void margeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        margeSort(a, low, mid);
        margeSort(a, mid + 1, high);
        marge(a, low, mid, high);
    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 4, 5, 3, 2};
    int size = sizeof(arr) / sizeof(int);
    int low = 0, high = size - 1;
    margeSort(arr, low, high);
    printArray(arr, size);
}