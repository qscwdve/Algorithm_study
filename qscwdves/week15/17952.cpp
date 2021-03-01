#include <stdio.h>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning(disable:4996) 

int main() {
    int minute, score, sec, flag, credit = 0;
    stack<pair<int, int>> Stack;
    scanf("%d", &minute);

    while (minute-- > 0) {
        scanf("%d", &flag);
        if (flag) {
            scanf("%d %d", &score, &sec);
            Stack.push(make_pair(score, sec - 1));
        }
        else {
            if (!Stack.empty()) {
                sec = Stack.top().second - 1;
                score = Stack.top().first;
                Stack.pop(); Stack.push(make_pair(score, sec));
            }
        }
        if (!Stack.empty() && Stack.top().second == 0) {
            credit += Stack.top().first;
            Stack.pop();
        }
    }
    printf("%d", credit);
    return 0;
}