#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Students {
	char * surname;
	char * name;
	int first, second, third;
}
students;

char * data () {
	int n = 0; 
	char * tmp = NULL;
	ch = getchar();
	while (ch != delimeter) {
		tmp = realloc(tmp, (n + 1) * sizeof(char));
		tmp[n] = ch;
		n++;
		ch = getchar();
	}
	tmp = realloc(tmp, (n + 1) * sizeof(char));
	tmp[n] = '\0';
	return tmp;
}

int main() {
	int n, i, k;
	students vmk[1000];
	char ch, delimeter = ' ';
	scanf("%d", &k);
	for (i = 1; i <= k; i++) {
		vmk[i].surname = data();
		vmk[i].name = data();
		scanf("%d %d %d\n", &vmk[i].first, &vmk[i].second, &vmk[i].third);
	}
	float cur_val, min;
	min = (vmk[1].first + vmk[1].second + vmk[1].third) / 3.0;
	float cur_deviat, max = min;
	float deviat_min = fabs(min - vmk[1].first) + fabs(min - vmk[1].second) + fabs(min - vmk[1].third);
	float deviat_max = deviat_min;
	int poz_min = 1, poz_max = 1, dev_min_poz = 1, dev_max_poz = 1;
	for (i = 2; i <= k; i++) {
		cur_val = (vmk[i].first + vmk[i].second + vmk[i].third) / 3.0;
		if (cur_val < min) {
			min = cur_val;
			poz_min = i;
        }
		if (cur_val > max) {
			max = cur_val;
			poz_max = i;
		}
		cur_deviat = fabs(cur_val - vmk[i].first) + fabs(cur_val - vmk[i].second) + fabs(vmk[i].third - cur_val);
		if (cur_deviat < deviat_min) {
			deviat_min = cur_deviat;
			dev_min_poz = i;
		}
		if (cur_deviat > deviat_max) {
			deviat_max = cur_deviat;
			dev_max_poz = i;
		}
	}
	printf("%s %.2f ", vmk[poz_min].surname, min);
	printf("%s %.2f\n", vmk[poz_max].surname, max);
	printf("%s %.2f %s %.2f", vmk[dev_min_poz].name, deviat_min, vmk[dev_max_poz].name, deviat_max);
	return 0;
}
