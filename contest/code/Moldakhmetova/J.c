#include <stdio.h>
#include <stdlib.h>

int main() {
    int *answer = NULL;
    int input, m = 0, size;
    scanf("%d", &input);
    for (int i = 1; i <= input; i++) {
        if (input % i == 0) {
            size = (m + 1) * sizeof(int);
            answer = realloc (answer, size);
            answer[m] = i;
            m++;
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%d ", answer[i]);
    }
    putchar('\n');
    if(answer != NULL) {
        free (answer);        
    }
    return 0;
}
