#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <tuple>
#include <time.h>
#include <math.h>
#include<utility>
#pragma warning (disable:4996)

using namespace std;


int N;	//회의의 수
int a, b;	//회의 시작시간, 끝나는 시간
int re;
int counts = 1;


int main() {
	scanf("%d", &N);

	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++) {

		scanf("%d %d", &a, &b);
		v.push_back(pair<int, int>(b, a));
	}
	sort(v.begin(), v.end());	//오름차순 
	re = v[0].first;



	
	for (int i = 1; i < N; i++) {
		if (re <= v[i].second) {
			counts++;
			re = v[i].first;
		}
	}


	printf("%d", counts);


	getchar();
	getchar();
	return 0;
}
