#include <stdio.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x, y;
} Point;

double dist(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

double angle(Point p1, Point p2, Point p3) {
    double a = dist(p1, p2);
    double b = dist(p2, p3);
    double c = dist(p1, p3);
    return acos((a*a + b*b - c*c) / (2*a*b));
}

int main() {
    int n, i, j, k, l, m;
    Point points[MAX_POINTS];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    int found = 0;
    for (i = 0; i < n && !found; i++) {
        for (j = i+1; j < n && !found; j++) {
            for (k = j+1; k < n && !found; k++) {
                for (l = k+1; l < n && !found; l++) {
                    for (m = l+1; m < n && !found; m++) {
                        Point p1 = points[i], p2 = points[j], p3 = points[k], p4 = points[l], p5 = points[m];
                        double a1 = angle(p1, p2, p3), a2 = angle(p2, p3, p4), a3 = angle(p3, p4, p5);
                        double a4 = angle(p4, p5, p1), a5 = angle(p5, p1, p2);
                        if (a1 < M_PI && a2 < M_PI && a3 < M_PI && a4 < M_PI && a5 < M_PI) {
                            found = 1;
                            printf("pentagono magico!\n");
                        }
                    }
                }
            }
        }
    }

    if (!found) {
        printf("cade a magia?\n");
    }

    return 0;
}
