#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
#pragma warning(disable:4996) 

int main() {
    int T;
    scanf("%d", &T);
    
    if (T == 1) printf("A");
    else {
        int sum = 3;
        stack<int> route, ans;

        // Ideal String이 될 수 있는지 판단 - 탐색
        ans.push(1);
        ans.push(2);
        while (sum != T) {
            if (sum < T) {
                for (int i = 1; i <= ans.top(); i++) {
                    route.push(ans.top() + i);
                }
            }
            else {
                // sum > T 이므로 가망 없는 뒷부분을 고려하지 않고 다른 경우의 수를 생각한다.
                if (route.empty()) {
                    printf("-1");
                    return 0;
                }
                // 이제 가망이 없으므로 이전 경우로 되돌린다.
                do {
                    sum -= ans.top();
                    ans.pop();
                } while (ans.top() > route.top());
            }
            ans.push(route.top());
            sum += route.top();
            route.pop();
        }

        // Ideal String 만들기
        int start = 'A' + ans.size() - 1;
        char ideal_string[101] = { 0 };
        stack<int> str;

        while (!ans.empty()) {
            for (int i = ans.top(); i > 1; i--) {
                str.push(start);
            }
            ideal_string[ans.top() - 1] = start;
            start--;
            ans.pop();
        }

        for (int i = 0; i < T; i++) {
            if (ideal_string[i] != 0) continue;
            ideal_string[i] = str.top();
            str.pop();
        }
        printf("%s", ideal_string);
    }

    return 0;
}