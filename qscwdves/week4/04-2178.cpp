#include <iostream>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int MAP[100][100] = { 0 };
struct node {
	int x = 0, y = 0;
	int count = 1;
};
int main() {
	int N, M;
	char ch;
	queue<node> queue;
	node start;
	node now , temp;
	int X, Y, count;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			scanf(" %c", &ch);
			if (ch == '1') MAP[i][k] = 1;
		}
	}
	queue.push(start);
	while (!queue.empty()) {
		now = queue.front();
		X = now.x;
		Y = now.y;
		count = now.count;
		MAP[Y][X] = 0;
		queue.pop();
		if (X == M - 1 && Y == N - 1) {
			printf("%d", count);
			break;
		}
		if (Y < N - 1 && MAP[Y + 1][X] == 1) {
			temp.y = Y + 1;
			temp.x = X;
			temp.count = count + 1;
			queue.push(temp);
			MAP[Y+1][X] = 0;
		}
		if (X < M - 1 && MAP[Y][X + 1] == 1) {
			temp.x = X + 1;
			temp.y = Y;
			temp.count = count + 1;
			queue.push(temp);
			MAP[Y][X + 1] = 0;
		}
		if (Y > 0 && MAP[Y - 1][X] == 1) {
			temp.y = Y - 1;
			temp.x = X;
			temp.count = count + 1;
			queue.push(temp);
			MAP[Y - 1][X] = 0;
		}
		if (X > 0 && MAP[Y][X - 1] == 1) {
			temp.x = X - 1;
			temp.y = Y;
			temp.count = count + 1;
			queue.push(temp);
			MAP[Y][X - 1] = 0;
		}
	}
	return 0;
}
