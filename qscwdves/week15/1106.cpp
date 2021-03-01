#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
#pragma warning(disable:4996) 

int d[2001] = { 0 };
int main() {
    int C, N, money, people, max_people = 0;
    vector<pair<int, int>> list;
    scanf("%d %d", &C, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &money, &people);
        list.push_back(make_pair(money, people));
        if (max_people < people) max_people = people;
    }

    for (int i = 1; i <= C; i++) {
        int min = -1;
        for (int k = 0; k < list.size(); k++) {
            money = list[k].first;
            people = list[k].second;
            if (i < people || d[i - people] == -1) continue;
            if (d[i - people] + money < min || min == -1) {
                min = d[i - people] + money;
            }
        }
        d[i] = min;
    }
    int answer = d[C];
    for (int i = C + 1; i <= C + max_people; i++) {
        int min = -1;
        for (int k = 0; k < list.size(); k++) {
            money = list[k].first;
            people = list[k].second;
            if (i < people || d[i - people] == -1) continue;
            if (d[i - people] + money < min || min == -1) {
                min = d[i - people] + money;
            }
        }
        d[i] = min;
        if (min != -1 && (answer > min || answer == -1)) answer = min;
    }
    printf("%d", answer);
    return 0;
}