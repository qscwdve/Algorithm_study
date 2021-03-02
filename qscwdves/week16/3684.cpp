#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
#pragma warning(disable:4996) 

vector<int> test;
int T, num;
int main() {
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &num);
        test.push_back(num);
    }
    if (T == 1) printf("%d", test[0]);   // a = 1, b = 0 인 경우로 고정
    else {
        for (int b = 0; b < 10001; b++) {
            for (int a = 0; a < 10001; a++) {
                int flag = 0;
                for (int v = 1; v < T; v++) {
                    int result1 = ((test[v - 1] * a + b) % 10001 * a + b) % 10001;
                    if (result1 != test[v]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    for (int i = 0; i < T; i++) {
                        printf("%d\n", (test[i] * a + b) % 10001);
                    }
                    return 0;
                }
            }
        }
    }
    return 0;
}
​