#include <stdio.h>

// Função para imprimir a sequência de funções diretamente
void imprimirSequencia(int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", (i + j) % n);
        }
        printf("\n");
    }
}

// Função principal
int main() {
    int n;

    // Lê o valor de n do arquivo de entrada "input"
    FILE *file = fopen("input", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }
    fscanf(file, "%d", &n);
    fclose(file);

    // Gera e imprime a sequência de funções diretamente
    imprimirSequencia(n);

    return 0;
}

