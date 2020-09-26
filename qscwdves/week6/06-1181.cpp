#include <iostream>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

vector<int>* graph;
vector<int> str_num[51];
void order(int n);
int main() {
	int num;
	char ch;
	scanf("%d", &num);
	getchar();
	graph = new vector<int>[num];
	for (int i = 0; i < num; i++) {
		for (int k = 0; k < 51; k++) {
			scanf("%c", &ch);
			if (ch == '\n') {
				str_num[k].push_back(i);
				break;
			}
			graph[i].push_back(ch);
		}
	}
	for (int i = 0; i < 51; i++) {
		if (str_num[i].size() != 0) order(i);
	}
	return 0;
}
void order(int n) {
	int size = str_num[n].size(), order_num[20000] = { 0 };

	for (int i = 0; i < size; i++) {
		order_num[i] = str_num[n][i];
	}
	for (int i = 0; i < size; i++) {
		if (order_num[i] == -1) continue;
		for (int k = i + 1; k < size; k++) {
			int j = 0;
			if (order_num[k] == -1) continue;
			for (j = 0; j < n; j++) {
				if (graph[order_num[i]][j] != graph[order_num[k]][j]) {
					if (graph[order_num[i]][j] > graph[order_num[k]][j]) { // swap
						int temp = order_num[i];
						order_num[i] = order_num[k];
						order_num[k] = temp;
					}
					break;
				}
			}
			if (j >= n) order_num[k] = -1;
		}
	}
	
	for (int i = 0; i < size; i++) {
		if (order_num[i] == -1) continue;
		for (int k = 0; k < n; k++) printf("%c", graph[order_num[i]][k]);
		printf("\n");
	}
	
}
