#include <stdio.h>
#include <stack>
#include <iostream>
using namespace std;
#pragma warning(disable:4996) 

int main() {
    int T , good = 0;
    char ch;
    scanf("%d", &T);
    getchar();

    while (T-- > 0) {
        stack<char> S;
        scanf("%c", &ch);
        while (ch != '\n') {
            if (!S.empty() && S.top() == ch) S.pop();
            else S.push(ch);
            scanf("%c", &ch);
        }
        if (S.empty()) good++;
    }
    printf("%d", good);
    return 0;
}