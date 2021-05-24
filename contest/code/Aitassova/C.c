#include <stdio.h>

int formula(void) {
    int answer = 0;
    char ch;
	ch = getchar();
	if (ch == '\n') {
        return answer;
    }
    if (ch == '(') {
        answer = formula();
        ch = getchar();
    }
    if (ch >= '0' && ch <= '9') {
        answer = ch - '0';
        ch = getchar();
        if(ch == '-') {
            answer -= formula();
            return answer;
        }
        if(ch == '+') {
            answer += formula();
            return answer;
        }
        if(ch == '*') {
            answer *= formula();
            return answer;
        }
        return answer;
    }
    if (ch == '-') {
        answer -= formula();
    }
    if (ch == '+') {
        answer += formula();
    }
    if (ch == '*') {
        answer *= formula();
    }
    if (ch == ')') {
        return answer;
    }
    return answer;
}

int main(void) {
    printf("%d\n", formula());
    return 0;
}
