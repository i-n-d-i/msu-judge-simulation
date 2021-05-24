#include <stdio.h>
#include <stdlib.h>

float square(int x_1, int y_1, int x_2, int y_2, int x_3, int y_3) {
    float square = abs((x_2 - x_1) * (y_3 - y_1) - (x_3 - x_1) * (y_2 - y_1));
    return square;
}

int main() {
    int x_a, y_a, x_b, y_b, x_c, y_c, x_d, y_d;
    scanf("%d %d %d %d %d %d", &x_a, &y_a, &x_b, &y_b, &x_c, &y_c);
    scanf("%d %d", &x_d, &y_d);
    float square_ADB = square(x_a, y_a, x_d, y_d, x_b, y_b) / 2;
    float square_ADC = square(x_a, y_a, x_d, y_d, x_c, y_c) / 2;
    float square_BDC = square(x_b, y_b, x_d, y_d, x_c, y_c) / 2;
    float square_ABC = square(x_a, y_a, x_b, y_b, x_c, y_c) / 2;
    if (square_ADB + square_ADC + square_BDC == square_ABC) {
        if (square_ADB != 0 && square_ADC != 0 && square_BDC != 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    else {
        printf("NO\n");
    }
    return 0;
}
