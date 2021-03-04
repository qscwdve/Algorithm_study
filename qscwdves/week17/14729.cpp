#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;
#pragma warning(disable:4996) 

int num[100001] = { 0 };

int main() {
    int T, grade, grade_f;
    priority_queue<int> Queue;

    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d", &grade);
        getchar();
        scanf("%d", &grade_f);
        int value = grade * 1000 + grade_f;
        if (num[value] == 0) {
            Queue.push(-value);
        }
        num[value]++;
    }
    int n = 0;
    while (n < 7) {
        float ans = (-Queue.top()) * 0.001;
        for (int i = 0; i < num[-Queue.top()]; i++) {
            printf("%.3f\n", ans);
            n++;
            if (n == 7) break;
        }
        Queue.pop();
    }
    return 0;
}