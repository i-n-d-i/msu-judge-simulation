#include <stdio.h>
#include <stdlib.h>

typedef struct Line {
    char second_name[10];
    char first_name[10];
    float average;
    float deviation;
} line;
typedef line* list;

list scanline(void) {
    list person = malloc(sizeof(line));
    if (!person) {
        return NULL;
    }
    char c;
    char *ptr;
    c = 0;
    ptr = person -> second_name;
    for (int i = 0; c != ' ' && i < 10; i++) {
        c = getchar();
        ptr[i] = c;
    }
    c = 0;
    ptr = person -> first_name;
    for (int i = 0; c != ' ' && i < 10; i++) {
        c = getchar();
        ptr[i] = c;
    }
    int r1, r2, r3;
    float r_av, d1, d2, d3;
    scanf("%d %d %d", &r1, &r2, &r3);
    getchar();
    r_av = (float) (r1 + r2 + r3);
    r_av *= (1.0 / 3);
    d1 = r1 - r_av;
    if (d1 < 0) {
        d1 *= -1;
    }
    d2 = r2 - r_av;
    if (d2 < 0) {
        d2 *= -1;
    }
    d3 = r3 - r_av;
    if (d3 < 0) {
        d3 *= -1;
    }
    person -> average = r_av;
    person -> deviation = d1 + d2 + d3;
    return person;
}

void printline_av(list person) {
    char *ptr;
    ptr = person -> second_name;
    for (int i = 0; ptr[i] != ' ' && i < 10; i++) {
        putchar(ptr[i]);
    }
    printf(" %.2f ", person -> average);
}

void printline_dev(list person) {
    char *ptr;
    ptr = person -> second_name;
    for (int i = 0; ptr[i] != ' ' && i < 10; i++) {
        putchar(ptr[i]);
    }
    printf(" %.2f ", person -> deviation);
}

int main(void) {
    int n;
    float min = 10, max = 0, min_dev = 10, max_dev = 0;
    scanf("%d", &n);
    getchar();
    list *students = NULL;
    for (int i = 0; i < n; i++) {
        students = realloc(students, (i + 1) * sizeof(list));
        students[i] = scanline();
        if (students[i] -> average < min) {
            min = students[i] -> average;
        }
        if (students[i] -> average > max) {
            max = students[i] -> average;
        }
        if (students[i] -> deviation < min_dev) {
            min_dev = students[i] -> deviation;
        }
        if (students[i] -> deviation > max_dev) {
            max_dev = students[i] -> deviation;
        }
    }
    for (int i = 0; i < n; i++) {
        if (students[i] -> average == min) {
            printline_av(students[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (students[i] -> average == max) {
            printline_av(students[i]);
        }
    }
    putchar('\n');
    for (int i = 0; i < n; i++) {
        if (students[i] -> deviation == min_dev) {
            printline_dev(students[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (students[i] -> deviation == max_dev) {
            printline_dev(students[i]);
        }
        free(students[i]);
    }
    free(students);
    putchar('\n');
    return 0;
}
