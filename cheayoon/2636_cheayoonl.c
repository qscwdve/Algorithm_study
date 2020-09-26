#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#pragma warning (disable:4996)


using namespace std;

int a[101][101];	//n x m 배열
bool check[101][101];
int dist[101][101];

//상하좌우를 가기 위함
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int n, m;	//n x m
int counts = 0;
int day = 0;
queue<pair<int, int> > q;	//Pair선언 (Pair은 두개의 변수를 저장할 수 있는 구조)

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {	//값을 읽어서 n x m 배열 생성
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);		//한개의 digit을 받는다라는 뜻으로 %1d를 쓴다
		}
	}

	while (1) {
		//check 초기화
		for (int i = 0; i < n; i++) {	//값을 읽어서 n x m 배열 생성
			for (int j = 0; j < m; j++) {
				check[i][j] = false;
			}
		}

		q.push(make_pair(0, 0));	//0,0 push 해줌
		check[0][0] = true; //방문한 곳으로 처리
		dist[0][0] = 1;		//1번 길찾기 처리
		check[101][101] = { false };
		while (q.empty() == false) { //큐가 비지 않을 때 까지..
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				//상하좌우 비교..
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (a[nx][ny] == 0 && check[nx][ny] == false) {		//0,0부터 시작한 상태니까 만약 상하 좌우에 1이 있다면..
						q.push(make_pair(nx, ny));	//해당 위치의 좌표를 q에 push
						check[nx][ny] = true;	//방문한 곳으로 표시
					}
					if (a[nx][ny] == 1) {
						a[nx][ny] = 2;
						counts++;
					}
				}
			}



		}
		int h = 0;
		int hu = 0;
		for (int i = 0; i < n; i++) {	//값을 읽어서 n x m 배열 생성
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 2) {
					a[i][j] = 0;	//치즈가 녹은부분으로 만들어줍니다.
					h++;
				}
				if (a[i][j] == 1) {
					hu++;
				}
			}
		}
		//printf("%d\n", h);
		if (hu != 0) counts = 0;
		if (h == 0) break;	//치즈가 녹은 부분이 없다면 종료시켜줍니다.



		day++;

	}



	printf("%d\n", day);
	printf("%d", counts);

	getchar();
	getchar();
	return 0;
}
