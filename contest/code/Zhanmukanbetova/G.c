#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Student {
    char name[10], surname[10];
    int number1, number2, number3;
    float middle, disp;
};

int min_middle(struct Student *student, int size) {
    int min_pos = 0;
    float min = student[0].middle;
    for (int i = 1; i < size; i++) {
        if (student[i].middle < min) {
            min = student[i].middle;
            min_pos = i;
        }
    }
    return min_pos;
}

int max_middle(struct Student *student, int size) {
    int max_pos = 0;
    float max = student[0].middle;
    for (int i = 1; i < size; i++) {
        if (student[i].middle > max) {
            max = student[i].middle;
            max_pos = i;
        }
    }
    return max_pos;
}

int min_disp(struct Student *student, int size) {
    int min_pos = 0;
    float min = student[0].disp;
    for (int i = 1; i < size; i++) {
        if (student[i].disp < min) {
            min = student[i].disp;
            min_pos = i;
        }
    }
    return min_pos;
}

int max_disp(struct Student *student, int size) {
    int max_pos = 0;
    float max = student[0].disp;
    for (int i = 1; i < size; i++) {
        if (student[i].disp > max) {
            max = student[i].disp;
            max_pos = i;
        }
    }
    return max_pos;
}

int main(void) {
    struct Student *student;
    int size;
    scanf("%d", &size);
    student = (struct Student *)malloc(size * sizeof(struct Student));
    for (int i = 0; i < size; i++) {
        scanf("%s", student[i].surname);
        scanf("%s", student[i].name);
        scanf("%d %d %d", &student[i].number1, &student[i].number2, &student[i].number3);
        student[i].middle = (student[i].number1 + student[i].number2 + student[i].number3) / 3.0;
        float disp1 = (float)fabs(student[i].middle - (float)student[i].number1);
        float disp2 = (float)fabs(student[i].middle - (float)student[i].number2);
        float disp3 = (float)fabs(student[i].middle - (float)student[i].number3);
        student[i].disp = disp1 + disp2 + disp3;
    }
    int min_pos = min_middle(student, size);
    int max_pos = max_middle(student, size);
    printf("%s ", student[min_pos].surname);
    printf("%.2f ", student[min_pos].middle);
    printf("%s ", student[max_pos].surname);
    printf("%.2f\n", student[max_pos].middle);
    min_pos = min_disp(student, size);
    max_pos = max_disp(student, size);
    printf("%s ", student[min_pos].name);
    printf("%.2f ", student[min_pos].disp);
    printf("%s ", student[max_pos].name);
    printf("%.2f\n", student[max_pos].disp);
    free(student);
    return 0;
}
