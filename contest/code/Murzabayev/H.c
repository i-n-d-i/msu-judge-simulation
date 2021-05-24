#include <stdio.h>
#include <stdlib.h>

void putword(char *ptr) {
    for (int i = 0; ptr[i] != ' ' && ptr[i] != '\n'; i++) {
        putchar(ptr[i]);
    }
    putchar(' ');
}

char *getword(char *ptr, int *size_ptr) {
    int k = 0;
    while (1) {
        ptr = realloc(ptr, (k + 1) * sizeof(char));
        if (!ptr) {
            printf("Error :)\n");
            return NULL;
        }
        ptr[k] = getchar();
        if (ptr[k] == ' ' || ptr[k] == '\n') {
            *size_ptr = k;
            return ptr;
        }
        k++;
    }
}

int main(void) {
    char *ptr;
    int *size_ptr;
    size_ptr = malloc(sizeof(int));
    while (1) {
        ptr = NULL;
        ptr = getword(ptr, size_ptr);
        if (*size_ptr == 3) {
            putword(ptr);
        }
        if (ptr[*size_ptr] == '\n')
            break;
        free(ptr);
    }
    free(ptr);
    free(size_ptr);
    putchar('\n');
    return 0;
}
