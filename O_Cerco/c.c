#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct CorpoCeleste
{
    int x;
    int y;
};

double calcularDistancia(struct CorpoCeleste a, struct CorpoCeleste b)
{
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int numeroDeNaves(int N, int L, struct CorpoCeleste corpos[])
{
    int naves = 0;
    int i = 0;

    while (i < N)
    {
        int j = i + 1;
        while (j < N && calcularDistancia(corpos[i], corpos[j]) <= L)
        {
            j++;
        }
        naves++; // Coloca uma nave no corpo atual

        if (j < N)
        {
            // Calcula a quantidade de naves estacionárias necessárias entre os corpos
            double distanciaTotal = calcularDistancia(corpos[i], corpos[j]);
            int navesEstacionarias = ceil(distanciaTotal / L) - 1;
            naves += navesEstacionarias;
        }

        i = j;
    }

    return naves;
}

int main()
{
    int casos;
    scanf("%d", &casos);

    for (int caso = 0; caso < casos; caso++)
    {
        int N, L;
        scanf("%d %d", &N, &L);

        struct CorpoCeleste corpos[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &corpos[i].x, &corpos[i].y);
        }

        int resultado = numeroDeNaves(N, L, corpos);
        printf("%d\n", resultado);
    }

    return 0;
}
