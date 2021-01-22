#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <tuple>
#include <time.h>
#pragma warning (disable:4996)

using namespace std;
struct shark {
	int x, y;
};



int arr[50][50];
int check[50][50];	//방문 했는지 안했는지 확인

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int n, m, ans = 0;

queue<shark> q;


void bfs() {
	
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y; 
		q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (!arr[nx][ny]) {
				q.push({ nx, ny });
				arr[nx][ny] = arr[x][y] + 1;
			}
		}
	}



}


int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j]) q.push({ i, j });
		}
	}

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans < arr[i][j]) ans = arr[i][j];
		}
	}
	printf("%d\n", ans - 1);



	getchar();

	return 0;
}
