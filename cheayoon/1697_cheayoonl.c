#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#pragma warning (disable:4996)


using namespace std;

int n = 0, k = 0;	//수빈위치와 동생위치
int visited[100001] = { 0 };	//방문 체크
queue<int> q;

int bfs() {
	q.push(n);	//큐에 수빈의 위치를 넣는다.
	visited[n] = 1;	//개수 세는 것.

	while (q.empty() == false) {
		//큐를 꺼내고, 수빈이가 동생 위치에 도달했는지 확인
		int p = q.front();	//q의 제일 앞에 있는 원소값을 p에 저장하고..
		q.pop();	//꺼냄
		if (p == k) {	//만약 도달했다면..
			return visited[p] - 1;
			
		}

		// -1
		if (p - 1 >= 0 && visited[p - 1] == 0) {
			visited[p - 1] = visited[p] + 1;	//전 부분에 방문한 것 추가 기록.
			q.push(p - 1);	//-1한 값 추가
		}

		// +1
		if (p + 1 <= 100000 && visited[p + 1] == 0) {
			visited[p + 1] = visited[p] + 1;	//다음 부분에 방문한 것 추가기록.
			q.push(p + 1);	// +1한 값 추가
		}

		// *2
		if (p * 2 <= 100000 && visited[p * 2] == 0) {
			visited[p * 2] = visited[p] + 1;	//두배 부분에 방문한 것 추가기록.
			q.push(2 * p);	// *2한 값 추가
		}
	}
}

int main() {
	int results;

	scanf("%d %d", &n, &k);	//수빈이가 있는 위치 N과 동생이 있는 위치 K
	
	results = bfs();

	printf("%d", results);


	getchar();
	getchar();
	return 0;
}
