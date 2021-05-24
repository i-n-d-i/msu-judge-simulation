#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	double a1, a2, b1, b2, c1, c2, d1, d2, ab, ad, ac, bc, bd, cd, p, s1, s2, s3, sabc;
	scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a1, &a2, &b1, &b2, &c1, &c2, &d1, &d2);
	ab = pow(pow((b1 - a1), 2) + pow((b2 - a2), 2), (1.0 / 2));
	ad = pow(pow((d1 - a1), 2) + pow((d2 - a2), 2), (1.0 / 2));
	ac = pow(pow((c1 - a1), 2) + pow((c2 - a2), 2), (1.0 / 2));
	bc = pow(pow((c1 - b1), 2) + pow((c2 - b2), 2), (1.0 / 2));
	bd = pow(pow((d1 - b1), 2) + pow((d2 - b2), 2), (1.0 / 2));
	cd = pow(pow((d1 - c1), 2) + pow((d2 - c2), 2), (1.0 / 2));
	p = (ab + bc + ac) / 2;
	sabc = pow((p * (p - ab) * (p - ad) * (p - ac)), (1.0 / 2));
	p = (ab + ad + bd) / 2;
	s1 = pow((p * (p - ab) * (p - ad) * (p - bd)), (1.0 / 2));
	p = (ad + ac + cd) / 2;
	s2 = pow((p * (p - ad) * (p - ac) * (p - cd)), (1.0 / 2));
	p = (bd + bc + cd) / 2;
	s3 = pow((p * (p - bd) * (p - bc) * (p - cd)), (1.0 / 2));
	if ((s1 + s2 + s3) > sabc) {
		puts("NO");
	}
	else {
		puts("YES");
	}
	return 0;
}
