#include <stdio.h>
#include <stdlib.h>

int formula() {
    char ch;
    int value, value_1, value_2;
    ch = getchar();
    if (ch >= '0' && ch <= '9') {
        value = (ch - '0');
        return value;
    }
    if (ch == '(') {
        value_1 = formula();
    }
    ch = getchar();
    value_2 = formula();
    if (ch == '+') {
        value = value_1 + value_2;
    } else if (ch == '-') {
        value = value_1 - value_2;
    } else {
        value = value_1 * value_2;
    }
    ch = getchar();
    return value;
}

int main(void) {
    int output;
    output = formula();
    printf("%d\n", output);
    return 0;
}
