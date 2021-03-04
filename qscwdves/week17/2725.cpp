#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
#pragma warning(disable:4996) 

int num[1001] = { 0 };
int S[1001] = { 0 };

int main() {
    num[1] = 3;
    S[1] = 3;

    for (int i = 2; i < 1001; i++) {
        int new_point = 2 * i + 1;
        int sum = num[1], p;
        for (p = 2; p < sqrt(i); p++) {
            if (i % p == 0) {
                sum += S[p] + S[i / p];
            }
        }
        if (p * p == i) sum += S[p];
        S[i] = new_point - sum;
        num[i] = num[i - 1] + S[i];
    }
    int T, n;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d", &n);
        printf("%d\n", num[n]);
    }

    return 0;
}