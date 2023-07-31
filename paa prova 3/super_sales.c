#include <stdio.h>

#define MAX_OBJECTS 1000
#define MAX_PEOPLE 100

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int weights[], int values[], int n, int maxWeight)
{
    int dp[MAX_OBJECTS + 1][MAX_PEOPLE + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weights[i - 1] <= w)
            {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][maxWeight];
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int N;
        scanf("%d", &N);

        int prices[MAX_OBJECTS];
        int weights[MAX_OBJECTS];

        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &prices[i], &weights[i]);
        }

        int G;
        scanf("%d", &G);

        int maxWeights[MAX_PEOPLE];

        for (int i = 0; i < G; i++)
        {
            scanf("%d", &maxWeights[i]);
        }

        int totalValue = 0;

        for (int i = 0; i < G; i++)
        {
            totalValue += knapsack(weights, prices, N, maxWeights[i]);
        }

        printf("%d\n", totalValue);
    }

    return 0;
}
