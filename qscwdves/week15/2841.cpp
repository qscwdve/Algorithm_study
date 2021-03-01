#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#pragma warning(disable:4996) 

vector<int> giter[500001];
int main() {
    int N, P, n, p, move = 0, size;
    
    scanf("%d %d", &N, &P);
    while (N-- > 0) {
        scanf("%d %d", &n, &p);
        size = giter[n].size();
        if (size == 0) {
            giter[n].push_back(p);
            move++;
        }
        else {
            size--;
            while (!giter[n].empty() && giter[n][size] > p) {
                giter[n].pop_back();
                size--; move++;
            }
            if (giter[n].empty() || giter[n][size] < p) {
                move++;
                giter[n].push_back(p);
            }
        }
    }
    printf("%d", move);
    return 0;
}