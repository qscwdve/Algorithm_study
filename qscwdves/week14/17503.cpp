#include <iostream>
#include <stdio.h>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int main() {
    int N, M, k, pre, lev, temp;
    priority_queue<pair<int, int>> relation;
    priority_queue<int> pick;

    scanf("%d %d %d", &N, &M, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &pre, &lev);
        relation.push(make_pair(-lev, pre));  
    }
    // pre : 선호도 , lev : 도수 레벨
    pre = 0; lev = 0;
    for (int i = 0; i < N; i++) {
        temp = relation.top().second;
        lev = relation.top().first;
        pick.push(-temp);
        pre += temp;
        relation.pop();
    }
    
    while (pre < M) {
        if (relation.empty()) {
            printf("-1");   
            return 0;
        }
        if (-pick.top() < relation.top().second) {
            pre += pick.top();
            pre += relation.top().second;
            lev = relation.top().first;
            pick.pop();
            pick.push(-relation.top().second);
        }
        relation.pop();
    }
    printf("%d", -lev);
    return 0;
}