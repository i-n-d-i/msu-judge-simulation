#include <stdio.h>

int formula(void) {
    int sum = 0;
    char ch;
	ch = getchar();
	if (ch == '\n') {
        return sum;
    }
    if (ch == '(') {
        sum = formula();
        ch = getchar();
    }
    if (ch >= '0' && ch <= '9') {
        sum = ch - '0';
        ch = getchar();
        if(ch == '-') {
            sum -= formula();
            return sum;
        }
        if(ch == '+') {
            sum += formula();
            return sum;
        }
        if(ch == '*') {
            sum *= formula();
            return sum;
        }
        return sum;
    }
    if (ch == '-') {
        sum -= formula();
    }
    if (ch == '+') {
        sum += formula();
    }
    if (ch == '*') {
        sum *= formula();
    }
    if (ch == ')') {
        return sum;
    }
    return sum;
}

int main(void) {
    printf("%d\n", formula());
    return 0;
}
