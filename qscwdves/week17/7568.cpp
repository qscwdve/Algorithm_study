#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
#pragma warning(disable:4996) 

int main() {
    int T, weight, inch;
    vector<pair<int, int>> people;

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &weight, &inch);
        people.push_back(make_pair(weight, inch));
    }

    for (int i = 0; i < T; i++) {
        int t_weight = people[i].first, t_inch = people[i].second;
        int num = 0;
        for (int k = 0; k < T; k++) {
            if (k == i) continue;
            if (people[k].first > t_weight && people[k].second > t_inch) {
                num++;
            }
        }
        printf("%d ", num + 1);
    }
    return 0;
}
​