#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>

#pragma warning (disable:4996)


using namespace std;

int N;
int map[25][25] = { 0 };
bool visited[25][25];

//상하좌우를 확인하기 위한 좌표
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int bfs(int x, int y) {
	visited[x][y] = true;	//방문한 것으로 바꿈
	int count = 0;
	for (int i = 0; i < 4; i++) {	//상하좌우를 확인
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx >= 0 && yy >= 0 && xx < N && yy < N && map[xx][yy] == 1 && !visited[xx][yy]) {
			visited[xx][yy] = true;	//방문한 것으로 바꿈
			count++;
			count += bfs(xx, yy);
		}
	}
	return count;
}
int main(void) {
	scanf("%d", &N);

	//입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);	//%1d를 쓰면 입력받은 정수도 문자 단위로 나누어서 처리가 가능하다.
		}
	}

	//수행
	vector<int> answer;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !visited[i][j]) answer.push_back(bfs(i, j));	//수행한 값을 answer에 넣는다
		}
	}

	//출력
	sort(answer.begin(), answer.end());	//오름차순 정렬부분
	int size = 0;
	size = answer.size();
	printf("%d\n", size);	//answer의 크기 출력. (총 단지수 출력)
	for (int v = 0; v < size; v++) {
		printf("%d\n", answer[v]+1);
	}

	getchar();
	getchar();
	return 0;
}
