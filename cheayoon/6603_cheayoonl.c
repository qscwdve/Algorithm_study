#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <tuple>
#pragma warning (disable:4996)

using namespace std;

int n;	//첫번째 입력하는 수
int m;
int lotto[13];
int combi[13];

//깊이우선탐색
void dfs(int start, int depth) {

	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			printf("%d ", combi[i]);
		}
		printf("\n");
		return;
	}

	
	for (int i = start; i < n; i++) {
		combi[depth] = lotto[i];
		dfs(i + 1, depth + 1);
	}

}

int main() {
	
	
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d", &lotto[i]);
		}

		dfs(0, 0);
		printf("\n");
		
	}

	getchar();
	getchar();

	return 0;
}

​
