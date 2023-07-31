#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, p[100000], inv, i, j;
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        inv = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            for (j = 0; j < i; j++) {
                if (p[j] > p[i]) {
                    inv++;
                }
            }
        }
        if (inv % 2 == 0) {
            printf("Carlos\n");
        } else {
            printf("Marcelo\n");
        }
    }
    return 0;
}
