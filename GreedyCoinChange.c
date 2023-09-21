#include <stdio.h>

// Swap two number
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int coins[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (coins[j] < coins[j + 1])
            {
                swap(&coins[j], &coins[j + 1]);
            }
        }
    }
}

// for print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Greedy coin change
void greedyCoinChange(int coins[], int n, int amount)
{
    bubbleSort(coins, n);
    int remainingAmount = amount;
    int numberOfCoins;
    int coinCount = 0;

    for (int i = 0; i < n; i++)
    {
        numberOfCoins = remainingAmount / coins[i];
        if (numberOfCoins > 0)
        {
            printf("%d x %d\n", coins[i], numberOfCoins);
            coinCount += numberOfCoins;
        }
        remainingAmount -= coins[i] * numberOfCoins;
    }
    printf("Total coin needed: %d\n", coinCount);
}

int main()
{
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 67;
    greedyCoinChange(coins, n, amount);
}