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
queue<pair<int, int> > q;	//Pair선언 (Pair은 두개의 변수를 저장할 수 있는 구조)

int main() { 
	
	scanf("%d %d", &n, &m); 

	for (int i = 0; i < n; i++) {	//값을 읽어서 n x m 배열 생성
		for (int j = 0; j < m; j++) { 
			scanf("%1d", &a[i][j]);		//한개의 digit을 받는다라는 뜻으로 %1d를 쓴다
		} 
	} 

	
	q.push(make_pair(0, 0));	//0,0 push 해줌
	check[0][0] = true; //방문한 곳으로 처리
	dist[0][0] = 1;		//1번 길찾기 처리
	while (q.empty() == false) { //큐가 비지 않을 때 까지..
		int x = q.front().first; 
		int y = q.front().second; 
		q.pop(); 
		for (int i = 0; i < 4; i++) { 
			//상하좌우 비교..
			int nx = x + dx[i]; 
			int ny = y + dy[i]; 
			if (nx >= 0 && nx < 100 && ny >= 0 && ny < 100) { 
				if (a[nx][ny] == 1 && check[nx][ny] == false) {		//a배열이 1로 되어있으며, 방문하지 않았다면..
					q.push(make_pair(nx, ny));	//해당 위치의 좌표를 q에 push
					dist[nx][ny] = dist[x][y] + 1;	//길찾기 처리 수 늘리기
					check[nx][ny] = true;	//방문한 곳으로 표시
				} 
			} 
		} 
	} 
	printf("%d\n", dist[n - 1][m - 1]); //길찾기 처리한 수 출력


getchar();
getchar();
return 0; 
}
