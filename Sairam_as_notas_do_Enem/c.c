#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (arr[middle] == target)
        {
            return middle;
        }
        else if (arr[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return -1;
}

int main()
{
    int n, m, i;
    scanf("%d", &n);
    int cpfs[n];
    int notas[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &cpfs[i]);
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &notas[i]);
    }

    scanf("%d", &m);

    int cpf;
    int encontrado;

    while (m > 0)
    {
        scanf("%d", &cpf);

        encontrado = binarySearch(cpfs, n, cpf);

        if (encontrado == -1)
        {
            printf("NAO SE APRESENTOU\n");
        }
        else
        {
            printf("%d\n", notas[encontrado]);
        }
        m = m - 1;
    }

    return 0;
}