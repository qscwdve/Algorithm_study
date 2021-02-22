#include <iostream>
#include <stdio.h>
#pragma warning (disable:4996)
using namespace std;

int map[50][50] = { 0 }, M, N;
int main() {
    int left, top, bottom, right, ans = 0, start, end;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            scanf("%d", &(map[i][k]));
        }
    }
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            if (map[i][k] == 1) continue;
            int count = 1, flag = 0;
            while (1) {
                left = (k - count >= 0) ? k - count : -1;
                right = (k + count < M) ? k + count : -1;
                top = (i - count >= 0) ? i - count : -1;
                bottom = (i + count < N) ? i + count : -1;
                start = (left < 0) ? 0 : left;
                end = (right < 0) ? M - 1 : right;
                if (top != -1) {
                    for (int j = start; j <= end; j++) {
                        if (map[top][j] == 1) {
                            flag = 1; break;
                        }
                    }
                    if (flag == 1) break;
                }
                if (bottom != -1) {
                    for (int j = start; j <= end; j++) {
                        if (map[bottom][j] == 1) {
                            flag = 1; break;
                        }
                    }
                    if (flag == 1) break;
                }
                start = (top < 0) ? 0 : top;
                end = (bottom < 0) ? N - 1 : bottom;
                if (left != -1) {
                    for (int j = start; j <= end; j++) {
                        if (map[j][left] == 1) {
                            flag = 1; break;
                        }
                    }
                    if (flag == 1) break;
                }
                if (right != -1) {
                    for (int j = start; j <= end; j++) {
                        if (map[j][right] == 1) {
                            flag = 1; break;
                        }
                    }
                    if (flag == 1) break;
                }
                count++;
            }
            if (ans < count) ans = count;
        }
    }
    printf("%d", ans);
    return 0;
}