#include <iostream>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int MAP[100][100] = { 0 };
struct node {
	int x = 0, y = 0;
};
int main() {
	int N, M;
	char ch;
	queue<node> Queue;
	node start;
	node now, temp;
	int X, Y, count=-1, count_chee = 0;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			scanf(" %c", &ch);
			if (ch == '1') {
				MAP[i][k] = -1;
				count_chee++;
			}
		}
	}
	
	while (1) {
		int temp_cheese = 0;
		count++;
		Queue.push(start);
		MAP[start.y][start.x] = count + 1;
		while (!Queue.empty()) {
			now = Queue.front();
			X = now.x;
			Y = now.y;
			Queue.pop();
			if (Y < N - 1) {
				temp.x = X;
				temp.y = Y + 1;
				if (MAP[Y + 1][X] == -1) {
					temp_cheese++;
					MAP[Y + 1][X] = count + 1;
				}
				else if (MAP[Y + 1][X] <= count) {
					Queue.push(temp);
					MAP[Y + 1][X] = count + 1;
				}
			}
			if (X < M - 1) {
				temp.x = X + 1;
				temp.y = Y;
				if (MAP[Y][X + 1] == -1) {
					temp_cheese++;
					MAP[Y][X + 1] = count + 1;
				}
				else if (MAP[Y][X + 1] <= count) {
					Queue.push(temp);
					MAP[Y][X + 1] = count + 1;
				}
			}
			if (Y > 0) {
				temp.x = X;
				temp.y = Y - 1;
				if (MAP[Y - 1][X] == -1) {
					temp_cheese++;
					MAP[Y - 1][X] = count + 1;
				}
				else if (MAP[Y - 1][X] <= count) {
					Queue.push(temp);
					MAP[Y - 1][X] = count + 1;
				}
			}
			if (X > 0) {
				temp.x = X - 1;
				temp.y = Y;
				if (MAP[Y][X - 1] == -1) {
					temp_cheese++;
					MAP[Y][X - 1] = count + 1;
				}
				else if (MAP[Y][X - 1] <= count) {
					Queue.push(temp);
					MAP[Y][X - 1] = count + 1;
				}
			}
		}
		count_chee = count_chee - temp_cheese;
		if (count_chee == 0) {
			printf("%d\n%d", count + 1, temp_cheese);
			break;
		}
	}
	return 0;
}
