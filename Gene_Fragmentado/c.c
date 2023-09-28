#include <stdio.h>
#include <string.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    char codigo_genetico[N + 1];
    char gene_messias[M];
    scanf("%s", codigo_genetico);
    scanf("%s", gene_messias);

    int posicao = -1;

    // Encontra a posição da primeira ocorrência do gene do messias no código genético
    for (int i = 0; i <= N - M; i++)
    {
        int match = 1;
        for (int j = 0; j < M; j++)
        {
            if (gene_messias[j] != '_' && gene_messias[j] != codigo_genetico[i + j])
            {
                match = 0;
                break;
            }
        }
        if (match)
        {
            posicao = i + 1;
            break;
        }
    }

    // Verifica se o gene do messias pode estar presente no código genético
    if (posicao != -1)
    {
        if (gene_messias[M - 1] == '_')
        {
            printf("%d\n", posicao + M - 2);
        }
        else
        {
            printf("%d\n", posicao - 1);
        }
    }
    else
    {
        printf("Nao descendente\n");
    }

    return 0;
}
