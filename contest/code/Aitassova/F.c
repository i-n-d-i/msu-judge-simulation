#include <stdio.h>

int nd(int a, int b) {
    if (!b) {
        return a;
    }
    else{
        return nd(b, a % b);
    }
}

void function(int num_1, int num_2) {
    int nd_val = nd(num_1, num_2);
    printf("%d/%d ", num_1 / nd_val, num_2 / nd_val);
}

int main(void) {
    int ch_1, z_1, ch_2, z_2, z_com;
    scanf("%d/%d %d/%d", &ch_1, &z_1, &ch_2, &z_2);
    z_com = z_1 * z_2;
    function(z_2 * ch_1 + ch_2 * z_1, z_com);
    function(ch_1 * ch_2, z_com);
    putchar('\n');
    return 0;
}
