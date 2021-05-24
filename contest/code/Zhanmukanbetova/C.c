#include <stdio.h>

int formula(void) {
    int ans = 0;
    char ch;
    ch = getchar();
    if (ch == '\n') {
        return ans;
    }
    if (ch == '(') {
        ans = formula();
        ch = getchar();
    }
    if (ch >= '0' && ch <= '9') {
        ans = ch - '0';
        ch = getchar();
        if(ch == '-') {
            ans -= formula();
            return ans;
        }
        if(ch == '+') {
            ans += formula();
            return ans;
        }
        if(ch == '*') {
            ans *= formula();
            return ans;
        }
        return ans;
    }
    if (ch == '-') {
        ans -= formula();
    }
    if (ch == '+') {
        ans += formula();
    }
    if (ch == '*') {
        ans *= formula();
    }
    if (ch == ')') {
        return ans;
    }
    return ans;
}

int main(void) {
    int ans = formula();
    printf("%d\n", ans);
    return 0;
}
