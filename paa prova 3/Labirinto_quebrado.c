#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int N, M;
char maze[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

bool isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == '.' && !visited[x][y]);
}

bool solveMaze(int x, int y)
{
    if (x == N - 1 && y == M - 1)
    {
        return true; // Chegou ao destino
    }

    visited[x][y] = true;

    // Verifica todas as quatro direções possíveis
    if (isSafe(x + 1, y) && solveMaze(x + 1, y))
    {
        return true;
    }
    if (isSafe(x - 1, y) && solveMaze(x - 1, y))
    {
        return true;
    }
    if (isSafe(x, y + 1) && solveMaze(x, y + 1))
    {
        return true;
    }
    if (isSafe(x, y - 1) && solveMaze(x, y - 1))
    {
        return true;
    }

    return false; // Não encontrou uma solução
}

bool isSolvable()
{
    // Verifica se o labirinto tem pelo menos uma célula e se a célula inicial é um caminho livre
    if (N == 0 || M == 0 || maze[0][0] == '#')
    {
        return false;
    }

    // Inicializa a matriz visited
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
        }
    }

    return solveMaze(0, 0);
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf("%s", maze[i]);
    }

    if (isSolvable())
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}
