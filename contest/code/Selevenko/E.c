#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point p1;
    Point p2;
    Point p3;
} Triangle;

double distance(Point p1, Point p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

double perimeter(Triangle t) {
    return (distance(t.p1, t.p2) + distance(t.p1, t.p3) + distance(t.p2, t.p3)) / 2;
}

double area(Triangle t) {
    double p = perimeter(t);
    double edge1 = distance(t.p1, t.p2);
    double edge2 = distance(t.p1, t.p3);
    double edge3 = distance(t.p2, t.p3);

    return sqrt(p * (p - edge1) * (p - edge2) * (p - edge3));
}

Triangle makeTriangle(Point a, Point b, Point c) {
    Triangle t;
    t.p1 = a;
    t.p2 = b;
    t.p3 = c;
    return t;
}

int main(void) {
    Point a, b, c, d;
    scanf("%d %d %d %d %d %d", &a.x, &a.y , &b.x, &b.y, &c.x, &c.y);
    scanf("%d %d", &d.x, &d.y);
    Triangle t = makeTriangle(a, b, c);
    Triangle t1 = makeTriangle(d, a, b);
    Triangle t2 = makeTriangle(d, b, c);
    Triangle t3 = makeTriangle(d, a, c);
    if (area(t) < area(t1) + area(t2) + area(t3)) {
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }

    return 0;
}