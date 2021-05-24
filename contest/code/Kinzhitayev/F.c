#include <stdio.h>

typedef struct drob {
    int p;
    int q;
} drob;

int NOD(int num_1, int num_2) {
    if (num_1 == 0 || num_2 == 0) {
        return num_1 + num_2;
    } else {
        return NOD(num_2, num_1 % num_2);
    }
}

drob compos(drob a, drob b) {
    int nod = NOD(a.p * b.p, a.q * b.q);
    drob output;
    output.p = a.p * b.p / nod;
    output.q = a.q * b.q / nod;
    return output;
}

drob summ(drob a, drob b) {
    int nod;
    drob output;
    output.p = a.p * b.q + b.p * a.q;
    output.q = a.q * b.q;
    nod = NOD(output.p, output.q);
    output.p /= nod;
    output.q /= nod;
    return output;
}

int main(void) {
    drob input_1, input_2, output_comp, output_sum;
    scanf("%d/%d %d/%d", &input_1.p, &input_1.q, &input_2.p, &input_2.q);
    output_sum = summ(input_1, input_2);
    output_comp = compos(input_1, input_2);
    printf("%d/%d %d/%d\n", output_sum.p, output_sum.q, output_comp.p, output_comp.q);
    return 0;
}
