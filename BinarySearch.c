#include <stdio.h>

int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// int rBinarySearch(int a[], int low, int high, int key)
// {
//     if (low > high)
//     {
//         return -1;
//     }
//     else
//     {
//         int mid = (low + high) / 2;
//         if (a[mid] == key)
//         {
//             return mid;
//         }
//         else if (a[mid] > key)
//         {
//             return rBinarySearch(a, low, mid - 1, key);
//         }
//         else
//         {
//             return rBinarySearch(a, mid + 1, high, key);
//         }
//     }
// }

int main()
{
    int a[] = {9};
    int n = 1;
    int low = 0, high = n - 1;
    int key = 9;
    int result = rBinarySearch(a, low, high, key);
    printf("%d", result);
}