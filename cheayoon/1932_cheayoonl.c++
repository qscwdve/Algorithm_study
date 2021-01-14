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

int n, a;
int num[501][501];
int j;
int maxs = 0;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (j = 0 ; j <= i ; j++) {
			
			scanf("%d", &a);
			num[i][j] = a;
		}
		
	}
	for (int i = 1; i < n; i++) {
		for (j = 0; j <= i; j++) {
			if (i == 0) {	//맨 왼쪽 줄이라면
				num[i][j] = num[i - 1][j] + num[i][j];
			}
			else if (i == j) {	//맨 오른쪽 줄이라면
				num[i][j] = num[i - 1][j - 1] + num[i][j];
			}
			else {	//중간부분
				num[i][j] = max(num[i - 1][j - 1], num[i - 1][j]) + num[i][j];
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (maxs < num[n - 1][i]) {
			maxs = num[n - 1][i];
		}
	}

	printf("%d", maxs);

	getchar();
	getchar();
	return 0;
}
