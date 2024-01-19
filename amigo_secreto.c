#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar as escolhas dos funcionários
typedef struct {
    int funcionario;
    int escolha;
} Escolha;

// Função de comparação para ordenar as escolhas por número de funcionário
int compararFuncionario(const void *a, const void *b) {
    return ((Escolha *)a)->funcionario - ((Escolha *)b)->funcionario;
}

// Função de comparação para ordenar as escolhas por número de escolha
int compararEscolha(const void *a, const void *b) {
    return ((Escolha *)a)->escolha - ((Escolha *)b)->escolha;
}

int main() {
    int n;
    scanf("%d", &n);

    // Alocar espaço para armazenar as escolhas dos funcionários
    Escolha *escolhas = malloc(n * sizeof(Escolha));

    // Ler as escolhas dos funcionários
    for (int i = 0; i < n; i++) {
        escolhas[i].funcionario = i + 1;
        scanf("%d", &escolhas[i].escolha);
    }

    // Ordenar as escolhas por número de escolha
    qsort(escolhas, n, sizeof(Escolha), compararEscolha);

    // Inicializar o conjunto de funcionários que dá e recebe um presente
    int *conjunto = malloc(n * sizeof(int));
    int tamanhoConjunto = 0;

    // Iterar sobre as escolhas e encontrar o maior conjunto
    for (int i = 0; i < n; i++) {
        int escolhaAtual = escolhas[i].escolha;
        if (escolhaAtual == i + 1) {
            // Verificar se o presente foi recebido por alguém
            if (i + 1 < n && escolhas[i + 1].escolha == escolhaAtual) {
                conjunto[tamanhoConjunto++] = escolhas[i].funcionario;
            }
        }
    }

    // Ordenar o conjunto por número de funcionário
    qsort(conjunto, tamanhoConjunto, sizeof(int), compararFuncionario);

    // Imprimir o conjunto
    for (int i = 0; i < tamanhoConjunto; i++) {
        printf("%d\n", conjunto[i]);
    }

    // Liberar a memória alocada
    free(escolhas);
    free(conjunto);

    return 0;
}
