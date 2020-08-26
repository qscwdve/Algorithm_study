#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;


int num, h, u;


int main() {
	vector<pair<int, int>> p;



	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &h, &u);
		p.push_back(make_pair(h, u));

	}
	sort(p.begin(), p.end());

	for (int i = 0; i < num; i++) {
		printf("%d %d\n", p[i].first, p[i].second);

	}

	getchar();
	getchar();
	return 0;
}
