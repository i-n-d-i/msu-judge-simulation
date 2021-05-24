#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    char name[100], surname[100];
    int number1, number2, number3;
    float mid, diverge_mid;
};

int main(void){
    struct Node a[100];
    int n;
    scanf("%d", &n);
    char ch;
    int j;
    for(int i = 0; i < n; i++){
        ch = getchar();
        j = 0;
        while(ch != ' '){
            a[i].name[j] = ch;
            j++;
            ch = getchar();
        }
        j = 0;
        ch = getchar();
        while(ch != ' '){
            a[i].surname[j] = ch;
            j++;
            ch = getchar();
        }
        scanf("%d %d %d", &a[i].number1, &a[i].number2, &a[i].number3);
        ch = getchar();
    }
    int max_pos = 0;
    int min_pos = 0;
    float mid_min = (float)(a[0].number1 + a[0].number2 + a[0].number3) / 3;
    float mid_max = (float)(a[0].number1 + a[0].number2 + a[0].number3) / 3;
    float mid;
    for(int i = 0; i < n; i++){
        a[i].mid = (float)(a[i].number1 + a[i].number2 + a[i].number3) / 3;
        mid = (float)(a[i].number1 + a[i].number2 + a[i].number3) / 3;
        if (mid < mid_min){
            mid_min = mid;
            min_pos = i;
        }
        if(mid > mid_max){
            mid_max = mid;
            max_pos = i;
        }
    }
    for(int i = 0; i < n; i++){
        a[i].diverge_mid = (float)fabs((float)a[i].mid - (float)a[i].number1) + (float)fabs((float)a[i].mid -(float)a[i].number2) + (float)fabs((float)a[i].mid - (float)a[i].number3);
    }
    puts(a[min_pos].name);
    printf("%f\n", mid_min);
    puts(a[max_pos].name);
    printf("%f\n",mid_max);
    mid_max = a[0].diverge_mid;
    min_pos = 0;
    max_pos = 0;
    mid_min = a[0].diverge_mid;
    for(int i = 0; i < n; i++){
        if (a[i].diverge_mid > mid_max){
            mid_max = a[i].diverge_mid;
            max_pos = i;
        }
        if(a[i].diverge_mid < mid_min){
            mid_min = a[i].diverge_mid;
            min_pos = i;
        }
    }
    puts(a[min_pos].surname);
    printf("%f\n", mid_min);
    puts(a[max_pos].surname);
    printf("%f\n", mid_max);
    return 0;
}
