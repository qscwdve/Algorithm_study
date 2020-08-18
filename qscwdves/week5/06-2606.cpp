#include <iostream>
#include <queue>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

int main() {
	int n, m, check[101] = { 0 }, now = 1, count = 0;
	queue<int> Queue;
	scanf("%d", &n);
	vector<int>* graph = new vector<int>[n+1];
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	check[1] = 1;

	while (1) {
		int size = graph[now].size();
		vector<int> temp = graph[now];
	
		for (int i = 0; i < size; i++) {
			if (check[temp[i]] == 0) {
				count++;
				Queue.push(temp[i]);
				check[temp[i]] = 1;
			}
		}
		if (Queue.empty()) {
			printf("%d", count);
			break;
		}
		else {
			now = Queue.front();
			Queue.pop();
		}
	}
	return 0;
}
