#include <iostream>
#include <vector>
#include <stack>
#pragma warning (disable:4996)
using namespace std;

void White_worm(int X, int Y, int num);

int main() {
	int T, X, Y, num;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d", &X, &Y, &num);
		White_worm(X,Y,num);
	}
	return 0;
}
void White_worm(int X,int Y, int num) {
	vector<int>* graph = new vector<int>[num];
	int temp_x, temp_y, map[51][51] = { 0 }, count = 0;
	stack<int> xs, ys;
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &temp_x, &temp_y);
		graph[i].push_back(temp_x);
		graph[i].push_back(temp_y);
		map[temp_y][temp_x] = 1;
	}
	for (int i = 0; i < num; i++) {
		temp_x = graph[i][0];
		temp_y = graph[i][1];
		if (map[temp_y][temp_x] == 1) {
			xs.push(temp_x);
			ys.push(temp_y);
			map[temp_y][temp_x] = 0;
			count++;
		}
		while (!xs.empty()) {
			int x = xs.top(), y = ys.top();
			xs.pop();
			ys.pop();
			if (y - 1 >= 0 && map[y - 1][x] == 1) {
				map[y - 1][x] = 0;
				xs.push(x);
				ys.push(y - 1);
			}
			if (y + 1 <= Y && map[y + 1][x] == 1) {
				map[y + 1][x] = 0;
				xs.push(x);
				ys.push(y + 1);
			}
			if (x - 1 >= 0 && map[y][x - 1] == 1) {
				map[y][x - 1] = 0;
				xs.push(x - 1);
				ys.push(y);
			}
			if (x + 1 <= X && map[y][x + 1] == 1) { 
				map[y][x + 1] = 0;
				xs.push(x + 1);
				ys.push(y);
			}
		}
	}
	printf("%d\n", count);
}
