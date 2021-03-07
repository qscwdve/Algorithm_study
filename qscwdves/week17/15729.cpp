#include <stdio.h>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
#pragma warning(disable:4996) 

vector<int> check;
stack<int> S;

int main() {
    int T, ans = 0, t;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &t);
        if (t == 1) check.push_back(i);
    }
    for (int i = check.size() - 1; i >= 0; i--) {
        S.push(check[i]);
    }

    while (!S.empty()) {
        int index = S.top();
        S.pop();
        ans++;
        if (index + 1 < T) {
            if (S.empty()) {
                if (index + 2 < T) S.push(index + 2);
                S.push(index + 1);
            }
            else if (index + 1 == S.top()) {
                S.pop();
                if (index + 2 < T) {
                    if (S.empty() || index + 2 != S.top()) {
                        S.push(index + 2);
                    }
                    else if (index + 2 == S.top()) {
                        S.pop();
                    }
                }
            }
            else {
                if (index + 2 < T) {
                    if (S.empty() || index + 2 != S.top()) {
                        S.push(index + 2);
                    }
                    else if (index + 2 == S.top()) {
                        S.pop();
                    }
                    S.push(index + 1);
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}