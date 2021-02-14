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

struct JUN {
	int a, b;
};



int N, h = 1, results = 0;
int dp[20];

int main() {

	scanf("%d", &N);
	vector<JUN> v(N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &v[i].a);
		scanf("%d", &v[i].b);
	}

	for (int i = 1; i <= N + 1; i++) {
		int time = v[i].a;
		int price = v[i].b;
		int end = time + i;

		if (i + time > N + 1) continue;

		for (int j = end; j <= N + 1; j++) {
			dp[j] = max(dp[i] + v[i].b, dp[j]);
		}
	}

	printf("%d\n", dp[N + 1]);


	
	return 0;
}
