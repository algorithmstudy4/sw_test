#include <stdio.h>

void check(int a[][10], int d[5]){
    for (int i = 2; i <= 4; i++) {
        d[i - 1] = 0;
        if (a[i - 1][3] != a[i][7]) d[i-1] = 1;
    }
}

void rotate(int a[][10], int num, int dir) {
    if (dir == 1) {
        for (int i = 8; i >= 1; i--) {
            a[num][i + 1] = a[num][i];
        }
        a[num][1] = a[num][9];
    }

    if (dir == -1) {
        for (int i = 1; i <= 8; i++) {
            a[num][i - 1] = a[num][i];
        }
        a[num][8] = a[num][0];
    }
}

void left(int a[][10], int d[5], int dir, int num){
    if (d[num] == 1) {
        rotate(a, num, dir*-1);
        if (num != 1)	left(a, d, dir*-1, num - 1);
    }
}

void right(int a[][10], int d[5], int dir, int num){
    if (d[num - 1] == 1) {
        rotate(a, num, dir*-1);
        if (num != 4)	right(a, d, dir*-1, num + 1);
    }
}
int main(){
    int K;
    int a[5][10];
    int d[5] = { 0, };
    int num[101], dir[101];
    int score = 0;

    for (int i = 1; i <= 4; i++) {
        scanf("%1d%1d%1d%1d%1d%1d%1d%1d", &a[i][1], &a[i][2], &a[i][3], &a[i][4], &a[i][5], &a[i][6], &a[i][7], &a[i][8]);
    }

    scanf("%d", &K);
    for (int i = 1; i <= K; i++) {
        scanf("%d %d", &num[i], &dir[i]);
    }


    for (int i = 1; i <= K; i++) {
        check(a, d);
        rotate(a, num[i], dir[i]);
        if(num[i] != 1) left(a, d, dir[i], num[i]-1);
        if(num[i] != 4) right(a, d, dir[i], num[i]+1);
    }

    if (a[1][1] == 1) score += 1;
    if (a[2][1] == 1) score += 2;
    if (a[3][1] == 1) score += 4;
    if (a[4][1] == 1) score += 8;

    printf("%d\n", score);
}

