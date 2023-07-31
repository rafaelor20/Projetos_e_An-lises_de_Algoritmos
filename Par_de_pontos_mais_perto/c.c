#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INF 1e20

typedef struct {
    double x, y;
} point;

/* Compara a ordenação das coordenadas x */
int cmp_x(const void* a, const void* b) {
    point* p1 = (point*) a;
    point* p2 = (point*) b;
    return (p1->x > p2->x) ? 1 : ((p1->x < p2->x) ? -1 : 0);
}

/* Compara a ordenação das coordenadas y */
int cmp_y(const void* a, const void* b) {
    point* p1 = (point*) a;
    point* p2 = (point*) b;
    return (p1->y > p2->y) ? 1 : ((p1->y < p2->y) ? -1 : 0);
}

/* Calcula a distância entre dois pontos */
double dist(point p1, point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

/* Encontra a menor distância entre dois pontos em um conjunto */
double closest_pair(point* P, int n) {
    if (n <= 1) {
        return INF;
    } else if (n == 2) {
        return dist(P[0], P[1]);
    }

    /* Dividir */
    int mid = n / 2;
    point mid_point = P[mid];
    double d_left = closest_pair(P, mid);
    double d_right = closest_pair(P + mid, n - mid);
    double d = fmin(d_left, d_right);

    /* Conquistar */
    point* S = (point*) malloc(n * sizeof(point));
    int i, j, k = 0;
    for (i = 0; i < n; i++) {
        if (fabs(P[i].x - mid_point.x) < d) {
            S[k++] = P[i];
        }
    }

    /* Ordenar por coordenadas y */
    qsort(S, k, sizeof(point), cmp_y);

    /* Encontrar pontos mais próximos em faixa */
    for (i = 0; i < k; i++) {
        for (j = i + 1; j < k && (S[j].y - S[i].y) < d; j++) {
            double dij = dist(S[i], S[j]);
            d = fmin(d, dij);
        }
    }

    free(S);
    return d;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n > 0) {
        point* P = (point*) malloc(n * sizeof(point));
        int i;
        for (i = 0; i < n; i++) {
            scanf("%lf %lf", &P[i].x, &P[i].y);
        }

        /* Ordenar por coordenadas x */
        qsort(P, n, sizeof(point), cmp_x);

        /* Encontrar a menor distância entre dois pontos */
        double d = closest_pair(P, n);
        if (d < 10000) {
            printf("%.4lf\n", d);
        } else {
            printf("INFINITY\n");
        }

        free(P);
    }
    return 0;
}

