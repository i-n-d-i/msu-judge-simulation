#include <stdio.h>
#include <stdlib.h>
#define infinity 2000000000

int read_count() {
    char c;
    int k;
    c = getchar();
    if (c >= '0' && c <= '9') {
        k = (int) (c - '0');
        return k;
    }
    int result, first, second;
    if (c == '(') {
        first = read_count();
        if (first == infinity) {
            return infinity;
        }
    } else {
        return infinity;
    }
    c = getchar();
    if (c == '+' || c == '-' || c == '*') {
        second = read_count();
        if (second == infinity) {
            return infinity;
        }
        if (c == '+') {
            result = first + second;
        } else if (c == '-') {
            result = first - second;
        } else {
            result = first * second;
        }
    } else {
        return infinity;
    }
    c = getchar();
    if (c != ')') {
        return infinity;
    }
    return result;
}

int main(void) {
    int a;
    a = read_count();
    if (a == infinity) {
        printf("Something went wrong :(\n");
        return 0;
    }
    printf("%d\n", a);
    return 0;
}
