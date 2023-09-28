#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

struct Ponto {
    int x, y, z;
};

void trocar(struct Ponto *a, struct Ponto *b) {
    struct Ponto aux = *a;
    *a = *b;
    *b = aux;
}

float distancia(struct Ponto a, struct Ponto b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

float menor(float x, float y) {
    return (x < y) ? x : y;
}

void quicksort_X(struct Ponto *vetor, int inicio, int fim);
int particiona_X(struct Ponto *vetor, int inicio, int fim);
void quicksort_Y(struct Ponto *vetor, int inicio, int fim);
int particiona_Y(struct Ponto *vetor, int inicio, int fim);

float closest_pair(struct Ponto *vetorA, struct Ponto *vetorB, int tamanho);

void imprimir_pontos(struct Ponto *vetorA, struct Ponto *vetorB, int tamanho, float menor_distancia) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (distancia(vetorA[i], vetorA[j]) == menor_distancia && vetorA[i].z != vetorA[j].z) {
                printf("%d %d %d %d\n", vetorA[i].x, vetorA[i].y, vetorA[j].x, vetorA[j].y);
            }
        }
    }
}

int main() {
    struct Ponto P[50000];
    struct Ponto Q[50000];
    int N;
    int x, y, z;

    scanf("%i", &N);

    for (int i = 0; i < N; i++) {
        scanf("%i %i %i", &x, &y, &z);
        P[i].x = x;
        P[i].y = y;
        P[i].z = z;
        Q[i].x = x;
        Q[i].y = y;
        Q[i].z = z;
    }

    int n = N;

    quicksort_X(P, 0, n - 1);
    quicksort_Y(Q, 0, n - 1);

    float menor_distancia = closest_pair(P, Q, n);
    //printf("A distância mais próxima é %f\n", menor_distancia);

    imprimir_pontos(P, Q, n, menor_distancia);

    return 0;
}

void quicksort_X(struct Ponto *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particiona_X(vetor, inicio, fim);
        quicksort_X(vetor, inicio, pivo - 1);
        quicksort_X(vetor, pivo + 1, fim);
    }
}

int particiona_X(struct Ponto *vetor, int inicio, int fim) {
    struct Ponto pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j].x <= pivo.x) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[fim]);
    return i + 1;
}

void quicksort_Y(struct Ponto *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particiona_Y(vetor, inicio, fim);
        quicksort_Y(vetor, inicio, pivo - 1);
        quicksort_Y(vetor, pivo + 1, fim);
    }
}

int particiona_Y(struct Ponto *vetor, int inicio, int fim) {
    struct Ponto pivo = vetor[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (vetor[j].y <= pivo.y) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[fim]);
    return i + 1;
}

float closest_pair(struct Ponto *vetorA, struct Ponto *vetorB, int tamanho) {
    if (tamanho < 3) {
        float menor_distancia = FLT_MAX;
        for (int i = 0; i < tamanho; i++) {
            for (int j = i + 1; j < tamanho; j++) {
                if (vetorA[i].z != vetorA[j].z) {
                    if (distancia(vetorA[i], vetorA[j]) < menor_distancia) {
                        menor_distancia = distancia(vetorA[i], vetorA[j]);
                    }
                }
            }
        }
        return menor_distancia;
    }

    int meio = tamanho / 2;
    struct Ponto ponto_meio = vetorA[meio];
    struct Ponto A1[meio];
    struct Ponto B1[meio];
    struct Ponto Ar[tamanho - meio];
    struct Ponto Br[tamanho - meio];

    for (int i = 0; i < meio; i++) {
        A1[i] = vetorA[i];
        B1[i] = vetorB[i];
    }

    for (int i = 0; i < tamanho - meio; i++) {
        Ar[i] = vetorA[i + meio];
        Br[i] = vetorB[i + meio];
    }

    int n = 0;
    float esq = closest_pair(A1, B1, meio);
    float dir = closest_pair(Ar, Br, tamanho - meio);
    float m = menor(dir, esq);

    struct Ponto S[tamanho];
    for (int i = 0; i < tamanho; i++) {
        if (abs(vetorB[i].x - ponto_meio.x) < m) {
            S[n] = vetorB[i];
            n++;
        }
    }

    float q_menordistancia = m * m;
    for (int i = 0; i < n - 1; i++) {
        int j = i + 1;
        while (j < n && (S[j].y - S[i].y) * (S[j].y - S[i].y) < q_menordistancia) {
            q_menordistancia = menor((S[j].x - S[i].x) * (S[j].x - S[i].x) + (S[j].y - S[i].y) * (S[j].y - S[i].y), q_menordistancia);
            j++;
        }
    }
    return sqrt(q_menordistancia);
}
