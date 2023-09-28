#include <stdio.h>
#include <stdlib.h>

// Função para processar o bitmap
void processBitmap(int **bitmap, int numRows, int numCols)
{
    if (numRows == 1 && numCols == 1)
    {
        printf("%d", bitmap[0][0]);
        return;
    }

    int allOnes = 1;
    int allZeros = 1;

    // Verifica se todos os elementos são iguais a 1 ou iguais a 0
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (bitmap[i][j] == 0)
            {
                allOnes = 0;
            }
            else
            {
                allZeros = 0;
            }
        }
    }

    if (allOnes)
    {
        printf("1");
    }
    else if (allZeros)
    {
        printf("0");
    }
    else
    {
        printf("D");

        // Divide o bitmap em 4 quadrantes
        int newRows = numRows / 2;
        int newCols = numCols / 2;
        int **quadrant = (int **)malloc(newRows * sizeof(int *));
        for (int i = 0; i < newRows; i++)
        {
            quadrant[i] = (int *)malloc(newCols * sizeof(int));
        }

        // Processa os 4 quadrantes
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int row = 0; row < newRows; row++)
                {
                    for (int col = 0; col < newCols; col++)
                    {
                        quadrant[row][col] = bitmap[i * newRows + row][j * newCols + col];
                    }
                }
                processBitmap(quadrant, newRows, newCols);
            }
        }

        // Libera a memória alocada para o quadrante
        for (int i = 0; i < newRows; i++)
        {
            free(quadrant[i]);
        }
        free(quadrant);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        int numRows, numCols;
        scanf("%d %d", &numRows, &numCols);

        int **bitmap = (int **)malloc(numRows * sizeof(int *));
        for (int i = 0; i < numRows; i++)
        {
            bitmap[i] = (int *)malloc(numCols * sizeof(int));
            for (int j = 0; j < numCols; j++)
            {
                char c;
                scanf(" %c", &c);
                bitmap[i][j] = c - '0';
            }
        }

        processBitmap(bitmap, numRows, numCols);
        printf("\n");

        // Libera a memória alocada para o bitmap
        for (int i = 0; i < numRows; i++)
        {
            free(bitmap[i]);
        }
        free(bitmap);
    }

    return 0;
}
