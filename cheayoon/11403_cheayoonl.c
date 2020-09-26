#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;


int num, h;	//테스트 개수
int a[100][100] = { 0 };	//input
int b[100][100] = { 0 };	//output

stack<pair<int, int> > s;	//(Pair은 두개의 변수를 저장할 수 있는 구조)



int main() {

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			scanf("%d", &h);
			if (h == 1) a[i][j] = 1;
		}
	}


	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (a[i][j] == 1) {
				a[i][j] = 0;	//방문한거로 표시
				s.push(make_pair(i, j));	//스택에 넣어줍니다.

				while (!s.empty()) {

				}

			}
		}
	}


	getchar();
	getchar();
	return 0;
}
