#include <stdio.h>
#include <stdlib.h>


int *answer;
int k;

void printAnswer() {
    for (int i = 0; i < k; i++) {
        printf("%d ", *(answer+i));
    }
    printf("\n");
}

void makesum(int sum, int number, int* answer){
    //if (number == 0) return;
    if (sum == 0 && number == 0) {
        printAnswer();
        return;
    }
    for(int i = 1; i <= sum; i++){
        *answer = i;
        makesum(sum - i, number-1, answer + 1);
    }
}

int main(void){
    int n;
    scanf("%d %d", &n, &k);
    answer = malloc(2 * k * sizeof(int));
    makesum(n, k, answer);
    return 0;
}
