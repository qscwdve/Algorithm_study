#include <iostream>
#include <stdio.h>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int main() {
    int T, s, e;
    priority_queue<pair<int,int>> pq;
    priority_queue<int> check;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &s, &e);
        pq.push(make_pair(-s,-e));
    }
    check.push(pq.top().second); pq.pop();
    for (int k = 1; k < T; k++) {
        if (-check.top() <= -pq.top().first) {
            check.pop();
        }
        check.push(pq.top().second);
        pq.pop();
    }
    printf("%d", check.size());
    return 0;
}