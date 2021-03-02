#include <stdio.h>
#pragma warning(disable:4996) 

int check(int x, int y, int d);
void paper(int x, int y, int n);
int map[2188][2188] = { 0 }, one = 0, zero = 0, one_minus = 0;
int main() {
    int T, value = 0, zero_num = 0;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        for (int k = 0; k < T; k++) {
            scanf("%d", &map[i][k]);
            value += map[i][k];
            if (map[i][k] == 0) zero_num++;
        }
    }
    if (zero_num == T * T) printf("0\n1\n0");
    else if (value == T * T) printf("0\n0\n1");
    else if (value + T * T == 0) printf("1\n0\n0");
    else {
        paper(0, 0, T);
        printf("%d\n%d\n%d", one_minus, zero, one);
    }
    return 0;
}
void paper(int x, int y, int n) {
    for (int i = 0; i < n; i += n / 3) {
        for (int k = 0; k < n; k += n / 3) {
            if (check(x + k, y + i, n / 3)) {
                paper(x + k, y + i, n / 3);
            }
        }
    }
}
int check(int x, int y, int d) {
    int value = map[y][x];
    for (int i = 0; i < d; i++) {
        for (int k = 0; k < d; k++) {
            if (map[i + y][k + x] != value) return 1;
        }
    }
    if (value == 0) zero++;
    else if (value == 1) one++;
    else one_minus++;
    return 0;
}