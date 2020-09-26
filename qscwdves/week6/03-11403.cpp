#include <iostream>
#include <vector>
#include <queue>
#pragma warning (disable:4996)
using namespace std;
void row_quest(int r);
int num;
vector<int>* graph;

int main() {
	int temp;
	scanf("%d", &num);
	graph = new vector<int>[num];

	for (int i = 0; i < num; i++) {
		for (int k = 0; k < num; k++) {
			scanf("%d", &temp);
			if (temp == 1) graph[i].push_back(k);
		}
	}
	for (int i = 0; i < num; i++) row_quest(i);

	return 0;
}
void row_quest(int r) {
	queue<int> Queue;
	int vertex[100] = { 0 };

	Queue.push(r);

	while (!Queue.empty()) {
		int now = Queue.front(), size, temp;
		Queue.pop();
		size = graph[now].size();
		for (int i = 0; i < size; i++) {
			temp = graph[now][i];
			if (vertex[temp] == 0) {
				Queue.push(temp);
				vertex[temp] = 1;
			}
		}
	}
	for (int i = 0; i < num; i++) {
		printf("%d ", vertex[i]);
	}
	printf("\n");
	return;
}
