#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "sample.h"

int gcd(int x, int y) {
    int g = y;
    while (x > 0) {
        g = x;
        x = y % x;
        y = g;
    }
    return g;
}

Point* new_point(int x, int y) {
    Point *p = (Point *)malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}

double distance(Point *p1, Point *p2) {
    printf("p1 addr: %lX, (%lf, %lf), p2 addr: %lX, (%lf, %lf)\n", \
            p1, p1->x, p1->y, p2, p2->x, p2->y);
    double d = hypot(p1->x - p2->x, p1->y - p2->y);
    printf("dis = %lf\n", d);
    return 0;
}
