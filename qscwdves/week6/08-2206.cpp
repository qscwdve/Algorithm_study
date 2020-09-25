#include <iostream>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int MAP[2][1000][1000] = { 0 };
struct node {
	int x = 0, y = 0;
	int count = 1, wall = 0;
};
int main() {
	int N, M;
	char ch;
	queue<node> queue;
	node start;
	node now, temp;
	int X, Y, count, WALL;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			scanf(" %c", &ch);
			if (ch == '1') {
				MAP[0][i][k] = 1;
				MAP[1][i][k] = 1;
			}
		}
	}
	queue.push(start);
	MAP[0][0][0] = -1;
	while (!queue.empty()) {
		now = queue.front();
		X = now.x;
		Y = now.y;
		count = now.count;
		WALL = now.wall;
		queue.pop();
		if (X == M - 1 && Y == N - 1) {
			printf("%d\n", count);
			return 0;
		}
		if (Y < N - 1) {
			if (MAP[WALL][Y + 1][X] == 0) {
				temp.y = Y + 1;
				temp.x = X;
				temp.wall = WALL;
				temp.count = count + 1;
				queue.push(temp);
				MAP[WALL][Y + 1][X] = -1;
			}
			else if (MAP[WALL][Y + 1][X] == 1 && WALL == 0) {
				temp.y = Y + 1;
				temp.x = X;
				temp.count = count + 1;
				temp.wall = 1;
				queue.push(temp);
				MAP[WALL][Y + 1][X] = -1;
			}
		}
		if (X < M - 1) {
			if (MAP[WALL][Y][X + 1] == 0) {
				temp.x = X + 1;
				temp.y = Y;
				temp.wall = WALL;
				temp.count = count + 1;
				queue.push(temp);
				MAP[WALL][Y][X + 1] = -1;
			}
			else if (MAP[WALL][Y][X + 1] == 1 && WALL == 0) {
				temp.x = X + 1;
				temp.y = Y;
				temp.count = count + 1;
				temp.wall = 1;
				queue.push(temp);
				MAP[WALL][Y][X + 1] = -1;
			}
		}
		if (Y > 0) {
			if (MAP[WALL][Y - 1][X] == 0) {
				temp.y = Y - 1;
				temp.x = X;
				temp.wall = WALL;
				temp.count = count + 1;
				queue.push(temp);
				MAP[WALL][Y - 1][X] = -1;
			}
			else if (MAP[WALL][Y - 1][X] == 1 && WALL == 0) {
				temp.y = Y - 1;
				temp.x = X;
				temp.count = count + 1;
				temp.wall = 1;
				queue.push(temp);
				MAP[WALL][Y - 1][X] = -1;
			}
		}
		if (X > 0) {
			if (MAP[WALL][Y][X - 1] == 0) {
				temp.x = X - 1;
				temp.y = Y;
				temp.wall = WALL;
				temp.count = count + 1;
				queue.push(temp);
				MAP[WALL][Y][X - 1] = -1;
			}
			else if (MAP[WALL][Y][X - 1] == 1 && WALL == 0) {
				temp.x = X - 1;
				temp.y = Y;
				temp.count = count + 1;
				temp.wall = 1;
				queue.push(temp);
				MAP[WALL][Y][X - 1] = -1;
			}
		}
	}
	printf("-1\n");
	return 0;
}
