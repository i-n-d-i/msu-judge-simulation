#include <stdio.h>

int main(){
	int a, b, c, d, s, p, f;
	char ch;
	scanf("%d%c%d %d%c%d", &a, &ch, &b, &c, &ch, &d);
	s = (a * d + c * b);
	p = (a * c);
	f = b * d;
	while (f > s){
		f = f - s;
	}
	printf("%d%c%d ", (s / f), '/', (b * d) / f);
	f = b * d;
	while (f > p) {
		f -= p;
	}
	printf("%d%c%d", (p / f), '/', (b * d) / f);
	return 0;
}
