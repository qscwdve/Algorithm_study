#include <iostream>
#include <stdio.h>
#include <stack>
#pragma warning (disable:4996)
using namespace std;
typedef struct maze {
    int num = 0, count = 0, click = 0;
    char map[10] = { 0 };
}M;
// shape : 맵에서 타일을 클릭하는 순간 영향을 받는 주변 타일의 index 저장, -1은 실제로 사용하지 않음
int shape[9][5] =
{
    {0, 1, 3, -1, -1}, {0, 1, 2, 4, -1}, {1, 2, 5, -1, -1},
    {0, 3, 4, 6, -1}, {1, 3, 4, 5, 7}, {2, 4, 5, 8, -1},
    {3, 6, 7, -1, -1}, {4, 6, 7, 8, -1}, {5, 7, 8, -1, -1}
};
int main() {
    int T, index;
    scanf("%d", &T); getchar();
    while (T-- > 0) {
        M ch;
        stack<M> S;
        for (int i = 0; i < 9; i++) {
            scanf("%c", (ch.map + i));
            if (ch.map[i] == '*') ch.num++;
            if ((i + 1) % 3 == 0) getchar();
        }
        if (ch.num == 0) {
            printf("0\n"); continue;
        }
 // 브루트 포스 알고리즘 - 전체 탐색 기법
        for (int i = 0; i < 9; i++) {
            ch.click = i;
            S.push(ch);
        }
        while (!S.empty()) {
            M t = S.top(); S.pop();
            
            for (int k = 0; k < 5; k++) {
                index = shape[t.click][k];
                if (index == -1) break;
                if (t.map[index] == '*') {
                    t.num--; t.map[index] = '.';
                }
                else {
                    t.num++; t.map[index] = '*';
                }
            }
            t.count++;
            if (t.num == 0) {
                printf("%d\n", t.count);
                break;
            }
            for (int i = t.click + 1; i < 9; i++) {
                t.click = i;
                S.push(t);
            }
        }
    }

    return 0;
}