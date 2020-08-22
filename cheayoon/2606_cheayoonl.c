#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int a[1000001];
int n, m;


void dfs(int v, vector<int> graph[], bool check[]) {

	std::stack<int> s;
	s.push(v);
	check[v] = true;


	while (!s.empty()) {

		int current_node = s.top();
		s.pop();
		for (int i = 0; i < graph[current_node].size(); i++) {

			int next_node = graph[current_node][i];

			if (check[next_node] == false) {
				v++;
				check[next_node] = true;
				// pop()을 했었기 때문에 현재 current_node도 넣어줘야한다.
				s.push(current_node);
				s.push(next_node);
				break;
			}
		}
	}
	printf("%d ", v - 1);

}


int main() { 
	scanf("%d", &n);	//컴퓨터 수
	scanf("%d", &m);	//네트워크 상에서 직접 연결되어 있는 컴퓨터의 쌍의 수

	vector<int> * graph = new vector<int>[n + 1];
	bool *check = new bool[n + 1]();

	//벡터의 시작점부터 연속된 범위를 어떤 값이나 객체로 모두 지정하고 싶을 때 사용하는 함수, 초기화함수
	fill(check, check + n + 1, false);




	for (int i = 0; i < m; i++) {
		int p, q;
		scanf("%d %d", &p, &q);	//컴퓨터쌍 연결

		graph[q].push_back(p);
		graph[p].push_back(q);	//양방향 연결


	}
	// Sorting은 왜 한거지?
	// 나중에 하나의 정점에서 다음을 탐색할 때 node 값에 순차적으로 접근해야하기 때문

	
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	//dfs
	dfs(1, graph, check);
	printf("\n");
	







getchar();
getchar();
return 0; 
}
