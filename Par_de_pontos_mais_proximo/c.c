#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DBL_MAX 1.7976931348623158e+308

typedef struct Point {
    int x, y;
} Point;

double dist(int aX, int aY, int bX, int bY) {
    float root, powerX, powerY, minusX, minusY, sum;
    minusX = aX - bX;
    minusY = aY - bY;
    powerX = pow(minusX, 2);
    powerY = pow(minusY, 2);
    sum = powerX + powerY;
    root = sqrt(sum);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    Point points[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    double min_dist = DBL_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = dist(points[i].x, points[i].y, points[j].x, points[j].y);
            if (d < min_dist) {
                min_dist = d;
            }
        }
    }

    printf("%.4f\n", min_dist);
    return 0;
}
