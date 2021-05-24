#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int where_point(float ax, float ay, float bx, float by, float px, float py) {
    float s;
    s = (bx - ax) * (py - ay) - (by - ay) * (px - ax);
    if (s > 0) {
        return 1;
    } else if (s != 0) {
        return -1;
    }
    return 0;
}

int point_triangle(float ax, float ay, float bx, float by,
                    float cx, float cy, float px, float py) {
    int s1, s2, s3;
    s1 = where_point(ax, ay, bx, by, px, py);
    s2 = where_point(bx, by, cx, cy, px, py);
    if (s2 * s1 <= 0) {
        return 0;
    }
    s3 = where_point(cx, cy, ax, ay, px, py);
    if (s3 * s2 <= 0) {
        return 0;
    }
    return 1;
}

int main(void) {
    int ax, ay, bx, by, cx, cy, px, py;
    float f_ax, f_ay, f_bx, f_by, f_cx, f_cy, f_px, f_py;
    scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);
    scanf("%d %d", &px, &py);
    f_ax = (float) ax;
    f_ay = (float) ay;
    f_bx = (float) bx;
    f_by = (float) by;
    f_cx = (float) cx;
    f_cy = (float) cy;
    f_px = (float) px;
    f_py = (float) py;
    if (point_triangle(f_ax, f_ay, f_bx, f_by, f_cx, f_cy, f_px, f_py)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
