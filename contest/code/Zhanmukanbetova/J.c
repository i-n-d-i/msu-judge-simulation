#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *dividers = NULL;
    int num, size, init = 0;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            size = (init + 1) * sizeof(int);
            dividers = realloc(dividers, size);
            dividers[init] = i;
            init++;
        }
    }
    for (int i = 0; i < init; i++) {
        printf("%d ", dividers[i]);
    }
    putchar('\n');
    free(dividers);
    return 0;
}
