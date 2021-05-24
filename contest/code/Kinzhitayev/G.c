#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Student {
    char name[10], surname[10];
    int deg_1, deg_2, deg_3;
    float r, d;
} student;

int main(void) {
    student* students;
    int input_n;
    float r, d, rmin = 10.0, rmax = 0.0, dmax = 0.0, dmin = 30.00;
    scanf("%d", &input_n);
    students = (student*)malloc(sizeof(student) * input_n);
    for (int i = 0; i < input_n; i++) {
        scanf("%s %s %d %d %d", students[i].surname, students[i].name, &students[i].deg_1, &students[i].deg_2, &students[i].deg_3);
        r = (float)((students[i].deg_1 + students[i].deg_2 + students[i].deg_3)) / 3;
        d = fabs((float)(students[i].deg_1) - r) + fabs((float)(students[i].deg_2) - r) + fabs((float)(students[i].deg_3) - r);
        students[i].r = r;
        students[i].d = d;
//        printf("%.2f %.2f\n", r, d);
        if (rmin >= r) {
            rmin = r;
        }
        if (rmax <= r) {
            rmax = r;
        }
        if (dmin >= d) {
            dmin = d;
        }
        if (dmax <= d) {
            dmax = d;
        }
    }
    for (int i = 0; i < input_n; i++) {
        if (students[i].r == rmin) {
            printf("%s %.2f ", students[i].surname, rmin);
            break;
        }
    }
    for (int i = 0; i < input_n; i++) {
        if (students[i].r == rmax) {
            printf("%s %.2f", students[i].surname, rmax);
            break;
        }
    }
    puts("");
    for (int i = 0; i < input_n; i++) {
        if (students[i].d == dmin) {
            printf("%s %.2f ", students[i].name, dmin);
            break;
        }
    }
    for (int i = 0; i < input_n; i++) {
        if (students[i].d == dmax) {
            printf("%s %.2f", students[i].name, dmax);
            break;
        }
    }
    puts("");
    free(students);
    return 0;
}
