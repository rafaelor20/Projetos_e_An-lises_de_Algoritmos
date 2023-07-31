#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 25

typedef struct
{
    char name[MAX_NAME_LENGTH];
    float price;
} Item;

int compareItems(const void *a, const void *b)
{
    const Item *itemA = (const Item *)a;
    const Item *itemB = (const Item *)b;

    return strcmp(itemA->name, itemB->name);
}

void buyItems(float budget, Item items[], int n)
{
    qsort(items, n, sizeof(Item), compareItems);

    int *dp = (int *)malloc((budget + 1) * sizeof(int));
    int *selected = (int *)calloc(n, sizeof(int));

    for (int i = 0; i <= budget; i++)
    {
        dp[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = (int)budget; j >= (int)items[i].price; j--)
        {
            if (dp[j] < dp[j - (int)items[i].price] + (int)items[i].price)
            {
                dp[j] = dp[j - (int)items[i].price] + (int)items[i].price;
                selected[i] = 1;
            }
        }
    }

    int count = 0;
    float remainingBudget = budget;
    for (int i = 0; i < n; i++)
    {
        if (selected[i])
        {
            printf("%s %.2f\n", items[i].name, items[i].price);
            count++;
            remainingBudget -= items[i].price;
        }
    }

    if (remainingBudget < 0)
    {
        remainingBudget = 0;
    }
    printf("%.2f\n", remainingBudget);

    free(dp);
    free(selected);
}

int main()
{
    float budget;
    int n;
    Item items[MAX_ITEMS];

    scanf("%f", &budget);
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s%f", items[i].name, &items[i].price);
    }

    buyItems(budget, items, n);

    return 0;
}
