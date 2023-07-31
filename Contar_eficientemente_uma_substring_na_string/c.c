#include <stdio.h>
#include <string.h>

#define MAX_N 7000000
#define MAX_M 1000000

char s[MAX_N + 1], p[MAX_M + 1];
int pi[MAX_M];

int main() {
    scanf("%s%s", s, p);

    int n = strlen(s), m = strlen(p);
    if (m > n) {
        printf("-1\n");
        return 0;
    }

    // calcula a função de prefixo de p
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
        }
        pi[i] = j;
    }

    // procura p em s usando a função de prefixo de p
    int j = 0, found = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]) {
            j = pi[j - 1];
        }
        if (s[i] == p[j]) {
            j++;
        }
        if (j == m) {
            printf("%d\n", i - m + 1);
            j = pi[j - 1];
            found = 1;
        }
    }

    // se p não foi encontrado em s, imprime -1
    if (!found) {
        printf("-1\n");
    }

    return 0;
}
