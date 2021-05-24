#include <stdio.h>

int gcm(int a, int b) {
    if (!b) {
        return a;
    }
    else{
        return gcm(b, a % b);
    }
}

void function(int num_1, int num_2) {
    int gcm_val = gcm(num_1, num_2);
    printf("%d/%d ", num_1 / gcm_val, num_2 / gcm_val);
}

int main(void) {
    int nom_1, denom_1, nom_2, denom_2, denom_com;
    scanf("%d/%d %d/%d", &nom_1, &denom_1, &nom_2, &denom_2);
    denom_com = denom_1 * denom_2;
    function(denom_2 * nom_1 + nom_2 * denom_1, denom_com);
    function(nom_1 * nom_2, denom_com);
    putchar('\n');
    return 0;
}
