#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
#pragma warning(disable:4996) 

int main() {
    
    int r, c, temp;
    vector<int> square[50];

    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++) {
        for (int k = 0; k < c; k++) {
            scanf("%1d", &temp);
            square[i].push_back(temp);
        }
    }

    int max = (r < c) ? r - 1 : c - 1;

    for (max; max >= 1; max--) {
        for (int i = 0; i + max < r; i++) {
            for (int k = 0; k + max < c; k++) {
                int value = square[i][k];
                if (value == square[i + max][k + max] && value == square[i + max][k] && value == square[i][k + max]) {
                    printf("%d", (max + 1) * (max + 1));
                    return 0;
                }
            }
        }
    }
    printf("1");
    return 0;
}