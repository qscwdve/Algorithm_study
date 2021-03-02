#include <stdio.h>
#include <stack>
#include <iostream>
using namespace std;
#pragma warning(disable:4996) 

int main() {
    int n, m, T;
    scanf("%d", &T);

    while (T-- > 0) {
        int ans = 1, end;
        stack<int> remain;
        scanf("%d %d", &n, &m);

        end = (n < m - n) ? n : m - n;
        for (int i = 1; i <= end; i++) {
            ans *= (m - i + 1);
            remain.push(i);
            while (!remain.empty() && ans % remain.top() == 0) {
                ans /= remain.top();
                remain.pop();
            }    
        }
        printf("%d\n", ans);
    }
    return 0;
}