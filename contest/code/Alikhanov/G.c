#include <stdio.h>
#include <math.h>

struct Students {
    char name[100], lastname[100];
    float num_1, num_2, num_3, mid, divr_mid;
};

int main(void) {
    struct Students group[100];
    int in, i, max_pos = 0, min_pos = 0;
    float mid_min, mid_max;
    scanf("%d", &in);
    for (i = 0; i < in; i++) {
        scanf("%s", group[i].name);
        scanf("%s", group[i].lastname);
        scanf("%f %f %f", &group[i].num_1, &group[i].num_2, &group[i].num_3);
        group[i].mid = (group[i].num_1 + group[i].num_2 + group[i].num_3) / 3;
        group[i].divr_mid = fabs(group[i].mid - group[i].num_1) + fabs(group[i].mid - group[i].num_2) + fabs(group[i].mid - group[i].num_3);
    }
    mid_min = group[0].mid;
    mid_max = group[0].mid;
    for (i = 0; i < in; i++) {
        if (group[i].mid < mid_min) {
            mid_min = group[i].mid;
            min_pos = i;
        }
        if(group[i].mid > mid_max) {
            mid_max = group[i].mid;
            max_pos = i;
        }
    }
    printf("%s %.2f ", group[min_pos].name, mid_min);
    printf("%s %.2f\n", group[max_pos].name, mid_max);
    mid_min = group[0].divr_mid;
    mid_max = group[0].divr_mid;
    min_pos = 0;
    max_pos = 0;
    for (i = 0; i < in; i++) {
        if (group[i].divr_mid > mid_max) {
            mid_max = group[i].divr_mid;
            max_pos = i;
        }
        if(group[i].divr_mid < mid_min) {
            mid_min = group[i].divr_mid;
            min_pos = i;
        }
    }
    printf("%s %.2f ", group[min_pos].lastname, mid_min);
    printf("%s %.2f\n", group[max_pos].lastname, mid_max);
    return 0;
}
