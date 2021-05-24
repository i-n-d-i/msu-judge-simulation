#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, *arr, k = 0;
    scanf("%d", &n);
    arr = NULL;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            arr = realloc(arr, (k + 1) * sizeof(int));
            if (!arr) {
                printf("ERROR\n");
                return 0;
            }
            arr[k] = i;
            k++;
        }
    }
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    printf("\n");
    return 0;
}
