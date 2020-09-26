#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;


int num;	//테스트 개수
int a, b, c;	//가로길이, 세로길이, 심어져있는 위치의 개수
int x, y;	//배추의 위치 x, y

int nu[50][50] = { 0 };	//n x m 배열
bool check[50][50];

//상하좌우를 가기 위함
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int> > q;	//Pair선언 (Pair은 두개의 변수를 저장할 수 있는 구조)

int counts = 0;

int main() {

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d %d", &a, &b, &c);	//가로길이, 세로길이, 심어져있는 위치의 개수
		for (int j = 0; j < c; j++) {	//심어져있는 위치의 개수만큼 값을 입력받는다.
			scanf("%d %d", &x, &y);
			nu[y][x] = 1;
		}

		//check 초기화
		for (int i = 0; i < b; i++) {	//값을 읽어서 n x m 배열 생성
			for (int j = 0; j < a; j++) {
				check[i][j] = false;
			}
		}

		for (int i = 0; i < b; i++) {
			for (int j = 0; j < a; j++) {
				if (nu[i][j] == 1) {	//배추가 심어져 있다면..

					q.push(make_pair(i, j));	//push 해줌
					nu[i][j] = 0;

					while (q.empty() == false) { //큐가 비지 않을 때 까지..
						int xi = q.front().first;
						int yi = q.front().second;
						q.pop();
						for (int i = 0; i < 4; i++) {
							//상하좌우 비교..
							int nx = xi + dx[i];
							int ny = yi + dy[i];
							if (nx >= 0 && nx < b && ny >= 0 && ny < a) {
								if (nu[nx][ny] == 1 && check[nx][ny] == false) {
									q.push(make_pair(nx, ny));	//해당 위치의 좌표를 q에 push
									nu[nx][ny] = 0;
									c--;
								}
							}
						}
					}
					counts++;
				}
				
			}
		}
		printf("%d\n", counts);
		counts = 0;

	}


			

		
	
	


	getchar();
	getchar();
	return 0;
}
