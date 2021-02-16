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
#include <cmath>
#include <string>
#include <cstdlib>

#pragma warning (disable:4996)

using namespace std;

int n, k;

bool cmp(pair<int, int> a, pair<int, int> b) {

	return a.first > b.first;	//내림차순 표현
}


int main() {

	scanf("%d %d", &n, &k);

	vector<int> a(n);
	vector<pair<int, int>> g(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i != 0) {
			g[i].first = a[i] - a[i - 1];	//각 수의 차를 저장 (현재 - 전)
			g[i].second = i;	//몇 번째 수의 차인지 저장 (i, i - 1)
		}
	}

	//키 차이를 기준으로 내림차순 정렬
	sort(g.begin(), g.end(), cmp);
	/*
	for (int i = 0; i < n; i++) {
		cout << i << endl;
		cout << g[i].first << endl;
		cout << g[i].second << endl;
	}
	*/

	int ans = 0;
	int tmp = 0;

	vector<int> t(k - 1);
	
	for (int i = 0; i < k - 1; i++) {
		t[i] = g[i].second; // 구간을 나눌 지점을 저장
	}
	
	sort(t.begin(), t.end()); // 오름차순으로 정렬
	t.push_back(n); // 마지막 인덱스 추가
	for (int i = 0; i < t.size(); i++) {
		ans += (a[t[i] - 1] - a[tmp]); // 각 구간의 차를 누적
		tmp = t[i];
		
	}
	cout << ans << endl;

	
	return 0;
}
