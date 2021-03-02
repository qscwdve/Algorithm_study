#include <stdio.h>
#pragma warning(disable:4996) 

void colored_paper(int x, int y, int num);
int check(int y, int x, int num);
int map[128][128] = { 0 }, white = 0, blue = 0;
int main() {
    int T, value = 0;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        for (int k = 0; k < T; k++) {
            scanf("%d", &map[i][k]);
            value += map[i][k];
        }
    }
    if (value == 0) printf("1\n0");            // 전부 하얀색일 경우
    else if (value == T * T) printf("0\n1");   // 전부 파란색일 경우
    else {
        colored_paper(0, 0, T);
        printf("%d\n%d", white, blue);
    }
    return 0;
}
void colored_paper(int x, int y, int n) {
    int num = n / 2;
    
    if (check(y, x, num)) colored_paper(x, y, num);                 
    if (check(y, x + num, num))colored_paper(x + num, y, num );
    if (check(y + num, x, num)) colored_paper(x, y + num, num );
    if (check(y + num, x + num, num)) colored_paper(x + num, y + num, num );
}
int check(int y, int x, int num) {
    int value = map[y][x];
    for (int i = y; i < y + num; i++) {
        for (int k = x; k < x + num; k++) {
            if (value != map[i][k]) return 1;
        }
    }
    if (value == 0) white++;
    else blue++;
    return 0;
}