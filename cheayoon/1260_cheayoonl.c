#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;

// stack에 들어가면 방문한거로 판단
// 해당 위치를 true로 해준다.
void dfs(int v, vector<int> graph[], bool check[]) {

	std::stack<int> s;
	s.push(v);
	check[v] = true;
	printf("%d ", v);

	while (!s.empty()) {

		int current_node = s.top();
		s.pop();
		for (int i = 0; i < graph[current_node].size(); i++) {

			int next_node = graph[current_node][i];

			if (check[next_node] == false) {
				printf("%d ", next_node);
				check[next_node] = true;
				// pop()을 했었기 때문에 현재 current_node도 넣어줘야한다.
				s.push(current_node);
				s.push(next_node);
				break;
			}
		}
	}

}

void bfs(int v, vector<int> graph[], bool checks[]) {
	std::queue<int> q;

	q.push(v);
	checks[v] = true;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		printf("%d ", tmp);
		for (int i = 0; i<graph[tmp].size(); i++) {

			// 방문하지 않았다면
			if (checks[graph[tmp][i]] == false) {
				// 큐에 넣어주고 방문했음을 표시한다.
				q.push(graph[tmp][i]);
				checks[graph[tmp][i]] = true;
			}
		}
	}

}

int main() {

	//첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 
	int n, m, v;
	cin >> n >> m >> v;

	vector<int> * graph = new vector<int>[n + 1];

	bool *check = new bool[n + 1]();

	//벡터의 시작점부터 연속된 범위를 어떤 값이나 객체로 모두 지정하고 싶을 때 사용하는 함수
	fill(check, check + n + 1, false);

	//다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다.
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);	//양방향 연결
	}

	// Sorting은 왜 한거지?
	// 나중에 하나의 정점에서 다음을 탐색할 때 node 값에 순차적으로 접근해야하기 때문
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	//dfs
	dfs(v, graph, check);
	printf("\n");

	bool *checks = new bool[n + 1]();
	fill(checks, checks + n + 1, false);

	//bfs
	bfs(v, graph, checks);
	printf("\n");

	return 0;
}
