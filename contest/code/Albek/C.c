#include <stdio.h>

int formula() {
	char ch;
	int val;
	ch = getchar();
	if (ch == '(') {
		val = formula();
	}
	if (ch >= '0' && ch <= '9') {
		return ch - '0';
	}
	ch = getchar();
	if (ch == '+') {
		val = val + formula();
	}
	if (ch == '-') {
		val = val - formula();
	}
	if (ch == '*') {
		val = val * formula();
	}
	getchar();
	return val;
}

int main() {
	printf("%d", formula());
	return 0;
}
