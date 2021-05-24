#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){
    char a[100], b[100];
    int i = 0;
    char ch;
    scanf("%c", &ch);
    while(ch != '\n'){
        a[i] = tolower(ch);
        scanf("%c", &ch);
        i++;
    }
    i = 0;
    scanf("%c", &ch);
    while(ch != '\n'){
        b[i] = tolower(ch);
        scanf("%c", &ch);
        i++;
    }
    b[i] = '\0';
    int y = strcmp(b, a);
    if (y < 0){
        printf("-1");
    } else if (y > 0){
        printf("1");
            }
    else{
        printf("0");
    }
    putchar('\n');
    return 0;
}
