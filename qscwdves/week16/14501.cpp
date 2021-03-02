#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
#pragma warning(disable:4996) 

void brute_force(int money, int day, int *max);
vector<pair<int, int>> consulting;
int N;
int main() {
    int term, money, max = 0;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &term, &money);
        consulting.push_back(make_pair(term, money));
    }
    brute_force(0, 0, &max);
    printf("%d", max);
    return 0;
}
void brute_force(int money, int day, int *max) {
    if (day < N) {
        if (consulting[day].first + day <= N) {  // 현재 날짜에서 상담을 할 경우
            brute_force(money + consulting[day].second, consulting[day].first + day, max);
        }
        brute_force(money, day + 1, max);  // 현재 날짜에서 상담을 하지않는 경우
    }
    if (*max < money) *max = money;
}