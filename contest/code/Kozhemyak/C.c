#include <stdio.h>
#include <stdlib.h>
#define empty 10

int formula() {
	char ch;
	int res, one, two, n;
	ch = getchar();
	if (ch >= '0' && ch <= '9') {
		n = (ch - '0');
		return n;
	}
	if (ch == '(') {
		one = formula();
		if (one == empty) {
			return empty;
		}
	}
	else {
		return empty;
	}
	ch = getchar();
	if (ch == '*' || ch == '+' || ch == '-') {
		two = formula();
		if (two == empty) {
			return empty;
		}
		if (ch == '-') {
			res = one - two;
		} else if (ch == '*') {
			res = one * two;
		}
		else {
			res = one + two;
		}
	}
	else {
		return empty;
	}
	ch = getchar();
	if (ch != ')') {
		return empty;
	}
	return res;
}

int main() {
	int k;
	k = formula();
	if (k == empty) {
		return 0;
	}
	printf("%d\n", k);
	return 0;
}
