#include <stdio.h>
#include <string.h>

int main() {
	char str1[101], str2[101];
	int i, j, m, n;
	int d[101][101];
	fgets(str1, 100, stdin);
	fgets(str2, 100, stdin);
	m = strlen(str1);
	n = strlen(str2);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			d[i][j] = 0;
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (str1[i] == str2[j]) {
				if ((i - 1 >= 0) && (j - 1) >= 0) {
					d[i][j] = d[i - 1][j - 1] + 1;
				} else {
					d[i][j] = 1;
				}
			} else {
				d[i][j] = 0;
			}
		}
	}
	int max = -1;
	for (i = 0; i < (m - 1); i++) {
		for (j = 0; j < (n - 1); j++) {
			if (d[i][j] > max) {
				max = d[i][j];
			}
		}
	}
	printf("%d", max);
	return 0;
}
