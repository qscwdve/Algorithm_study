#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#pragma warning (disable:4996)
using namespace std;

vector<int> relation[10001];

int main() {
	priority_queue<pair<int, int>> Queue;
	int N, M;

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		relation[B].push_back(A);
	}

	for (int i = 1; i <= N; i++) {
		stack<int> s;
		int flag[10001] = { 0 }, num = 0;
		flag[i] = 1; s.push(i);
		do {
			vector<int> hacker = relation[s.top()]; s.pop();
			for (int k = 0; k < hacker.size(); k++) {
				if (flag[hacker[k]] == 0) {
					s.push(hacker[k]);
					flag[hacker[k]] = 1;
					num++;
				}
			}
		} while (!s.empty());
		Queue.push(make_pair(num, -i));
	}

	int max_number = Queue.top().first;
	while (!Queue.empty() && max_number == Queue.top().first) {
		printf("%d ", -(Queue.top().second));
		Queue.pop();
	}
	return 0;
}
