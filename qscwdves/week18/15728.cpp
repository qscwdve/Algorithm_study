#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdio.h>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int N, K, team_minus = 100000, team_plus = -100000;
int share_card[101] = { 0 }, shared_flag[101] = { 0 };
int main() {
	priority_queue<pair<int, int>> Queue;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp < team_minus) team_minus = temp;
		if (temp > team_plus) team_plus = temp;
	}
	for (int i = 1; i <= N; i++) scanf("%d", (share_card + i));

	for (int i = 1; i <= N; i++) {
		int number = share_card[i];
		int max_value = (team_minus * number > team_plus * number) ? (team_minus * number):(team_plus * number);
		Queue.push(make_pair(max_value, i));
	}
	for (int i = 1; i <= K; i++) {
		shared_flag[Queue.top().second] = 1;
		Queue.pop();
	}

	int answer = -100000000;
	for (int i = 1; i <= N; i++) {
		if (shared_flag[i] == 0) {
			int number = share_card[i];
			int max_value = (team_minus * number > team_plus * number) ? (team_minus * number) : (team_plus * number);
			if (max_value > answer) answer = max_value;
		}
	}
	printf("%d", answer);
	return 0;
}
