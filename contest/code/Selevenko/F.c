#include <stdio.h>
#include <stdlib.h>

int Evklid(int a, int b){
    if (b == 0){
        return a;
    }
    else{
        return Evklid(b, a % b);
    }
}

int main(void){
    int nominator1, denominator1, nominator2, denominator2;
    int nominator_mul_result, nominator_sum_result, denominator_sum_result,
    denominator_mul_result;
    scanf("%d/%d %d/%d", &nominator1, &denominator1, 
    &nominator2, &denominator2);
    nominator_mul_result = nominator1 * nominator2;
    denominator_mul_result = denominator1 * denominator2;
    int nod = 1;
    nominator_sum_result = denominator2 * nominator1 
    + nominator2 * denominator1;
    denominator_sum_result = denominator1 * denominator2;
    nod = Evklid(nominator_sum_result,  denominator_sum_result);
    printf("%d/%d ", (int)nominator_sum_result / nod, 
    (int)denominator_sum_result / nod);
    nod = Evklid(nominator_mul_result, denominator_mul_result);
    printf("%d/%d\n", (int)nominator_mul_result / nod, 
    (int)denominator_mul_result / nod);

    return 0;
}
