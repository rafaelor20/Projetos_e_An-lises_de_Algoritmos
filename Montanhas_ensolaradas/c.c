#include <stdio.h>
#include <math.h>

#define MAX_N 100

typedef struct {
    int x, y;
} Coordenada;

double distancia(Coordenada c1, Coordenada c2) {
    double dx = c1.x - c2.x;
    double dy = c1.y - c2.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    int C, N, i;
    Coordenada coords[MAX_N], prev_coord;
    double total_length;

    scanf("%d", &C);

    while (C--) {
        scanf("%d", &N);

        scanf("%d %d", &prev_coord.x, &prev_coord.y);
        total_length = 0;

        for (i = 1; i < N; i++) {
            scanf("%d %d", &coords[i].x, &coords[i].y);
            total_length += distancia(coords[i], prev_coord);
            prev_coord = coords[i];
        }
        total_length += distancia(coords[1], prev_coord); // adiciona a distância entre a primeira e a última coordenada
        printf("%.2lf\n", total_length);
    }

    return 0;
}



