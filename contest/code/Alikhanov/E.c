#include <stdio.h>
#include <math.h>

typedef struct point Point;
typedef struct triangle Triangle;

struct point{
    int x, y;
};

struct triangle{
    Point p1;
    Point p2;
    Point p3;
};

Triangle create(Point a, Point b, Point c) {
    Triangle t;
    t.p1 = a;
    t.p2 = b;
    t.p3 = c;
    return t;
}

int is_inside_trgl(Triangle trl, Point d) {
    int val1 = (trl.p1.x - d.x) * (trl.p2.y - trl.p1.y) - (trl.p2.x - trl.p1.x) * (trl.p1.y - d.y);
    int val2 = (trl.p2.x - d.x) * (trl.p3.y - trl.p2.y) - (trl.p3.x - trl.p2.x) * (trl.p2.y - d.y);
    int val3 = (trl.p3.x - d.x) * (trl.p1.y - trl.p3.y) - (trl.p1.x - trl.p3.x) * (trl.p3.y - d.y);
    if ((val1 > 0 && val2 > 0 && val3 > 0) || (val1 < 0 && val2 < 0 && val3 < 0)) {
        return 1;
    }
    return 0;
}

int main(void) {
    Point a, b, c, d;
    scanf("%d %d %d %d %d %d %d %d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
    Triangle trgl = create(a, b, c);
    if (is_inside_trgl(trgl, d)) {
        printf("YES\n");
    } else{
        printf("NO\n");
    }
    return 0;
}
