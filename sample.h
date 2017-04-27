#ifndef SAMPLE_H_
#define SAMPLE_H_

extern int gcd(int, int);

typedef struct Point_s {
    double x, y;
} Point;

extern double distance(Point *p1, Point *p2);

#endif // SAMPLE_H_
