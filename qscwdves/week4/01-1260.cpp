#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#pragma warning (disable:4996)
using namespace std;

int main() {
	int n, m, start, check_D[1000] = { 0 }, check_B[1000] = { 0 };
	queue<int> Queue;
	stack<int> Stack;
	cin >> n >> m >> start;
	vector<int>* graph = new vector<int>[n];
    // 입력 받기
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u-1].push_back(v);
		graph[v-1].push_back(u);
	}
	//DFS
	Stack.push(start);
	while (!Stack.empty()) {
		int temp, size = 0, check[1000] = { 0 };  // check는 정렬
		temp = Stack.top();
		Stack.pop();
		if (check_D[temp - 1] == 0) {
			printf("%d ", temp);
			check_D[temp - 1] = 1;
		}
		for (int i = 0; i < graph[temp - 1].size(); i++) {
			if (check_D[graph[temp - 1][i] - 1] == 0) {
				check[size] = graph[temp - 1][i];
				size++;
			}
		}
		//정렬
		for (int i = 0; i < size; i++) {
			for (int k = i; k < size; k++) {
				if (check[i] < check[k]) {
					int num = check[i];
					check[i] = check[k];
					check[k] = num;
				}
			}
		}
		for (int i = 0; i < size; i++) {
			Stack.push(check[i]);
		}
	}
	printf("\n");
	//BFS   
	check_B[start - 1] = 1;
	printf("%d ", start);
	Queue.push(start);
	while (!Queue.empty()) {
		int size, temp,i = 0;
		temp = Queue.front(); 
		Queue.pop();
		size = graph[temp - 1].size();  
		while (i != size) {
			int min = -1, num;
			for (int k = 0; k < size; k++) {
				num = graph[temp - 1][k];
				if (check_B[num - 1] == 0) {
					if (min == -1) min = num;
					else if (min > num) min = num;
				}
			}
			if (min != -1) {
				i++;
				printf("%d ", min);
				check_B[min - 1] = 1;
				Queue.push(min);
			}
			else break;
		}
	}
	return 0;
}
