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
#pragma warning (disable:4996)

using namespace std;

int N, K;	//동전의 총 종류N, 그 가치의 합K
int a[11];
int counts = 0;


int main() {
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = N - 1; i >= 0; i--) {
		while (a[i] <= K) {
			K = K - a[i];
			counts++;

		}
	}

	printf("%d", counts);



	getchar();
	getchar();
	return 0;
}
​
