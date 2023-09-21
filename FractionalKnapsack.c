#include <stdio.h>

// Swap two number
void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(double profits[], double weights[], double p2w[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (p2w[j] < p2w[j + 1])
            {
                swap(&p2w[j], &p2w[j + 1]);
                swap(&weights[j], &weights[j + 1]);
                swap(&profits[j], &profits[j + 1]);
            }
        }
    }
}

void printArray(double arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.1f                    ", arr[i]);
    }
    printf("\n");
}

double fractionalKnapsack(double profits[], double weights[], int maxWeight, int n)
{
    double p2w[n];
    for (int i = 0; i < n; i++)
    {
        p2w[i] = profits[i] / weights[i];
    }

    // printArray(profits, n);
    // printArray(weights, n);
    // printArray(p2w, n);

    bubbleSort(profits, weights, p2w, n);

    // printArray(profits, n);
    // printArray(weights, n);
    // printArray(p2w, n);

    double remainingWeight = maxWeight;
    double totalProfit = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (remainingWeight >= weights[i])
        {
            remainingWeight -= weights[i];
            totalProfit += profits[i];
        }
        else
        {
            double fraction = remainingWeight / weights[i];
            totalProfit += fraction * profits[i];
            break;
        }
    }

    return totalProfit;
}

int main()
{
    double weights[] = {2, 3, 5, 7, 1, 4, 1};
    double profits[] = {10, 5, 15, 7, 6, 18, 3};
    int maxWeight = 15;
    int n = 7;
    double result = fractionalKnapsack(profits, weights, maxWeight, n);
    printf("%.2f", result);
}