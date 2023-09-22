#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int profits[], int weights[], int n, int maxWeight)
{
    int dp[n + 1][maxWeight + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (w < weights[i])
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                dp[i][w] = max(dp[i - 1][w], profits[i] + dp[i - 1][w - weights[i]]);
            }
            printf("%d\t", dp[i][w]);
        }
        printf("\n");
    }
    return dp[n][maxWeight];
}

int main()
{
    int weights[] = {0, 3, 4, 5, 6};
    int profits[] = {0, 2, 3, 4, 1};
    int W = 8; // maximum weight of bag
    int n = 4; // number of items
    printf("Max profits: %d", knapsack(profits, weights, n, W));
    return 0;
}