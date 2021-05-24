#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char s1[100], s2[100];
    fgets(s1, 100, stdin);
    fgets(s2, 100, stdin);
    int d[100][100];
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    for(int i = 0; i < length1; i++){
        for(int j = 0; j < length2; j++){
            if (s1[i] == s2[j]) {
                int prev = 0;
                if (i > 0 && j > 0) {
                    prev = d[i-1][j-1];
                }
                d[i][j] = prev + 1;
            }
        }
    }
    int max = d[0][0];
    for (int i = 0; i< length1; i++){
        for(int j = 0; j < length2; j++){
//            printf("%d ", d[i][j]);
           if (max < d[i][j]){
                max = d[i][j];
            }
        }
//        printf("\n");
    }
    printf("%d\n", max);
    return 0;
}
