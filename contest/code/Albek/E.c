#include <stdio.h>

typedef struct Point {
	int x;
	int y;
}
point;

int cross(point A, point B) {
	return A.x * B.y - A.y * B.x;
}

int orient(point A, point B, point C) {
	return cross(A, B) + cross(B, C) + cross(C, A);
}

int main() {
	point A, B, C, D;
	scanf("%d %d %d %d %d %d", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
	scanf("%d %d", &D.x, &D.y);
	int sor = orient(A, B, C);
	int cond1 = sor * orient(A, B, D);
	int cond2 = sor * orient(A, D, C);
	int cond3 = sor * orient(D, B, C);
	if (cond1 >= 0 && cond2 >= 0 && cond3 >= 0) {
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}
