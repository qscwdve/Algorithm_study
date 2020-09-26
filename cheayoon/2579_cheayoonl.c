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

int n;	//계단의 개수
int a[300];	//계단
int maxs[300];	//최댓값



int main() {
	scanf("%d",&n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	
	maxs[0] = a[0];
	maxs[1] = max(a[1],a[0] + a[1]);	//둘중 어느것이 더 max값인지..
	maxs[2] = max(a[0] + a[2], a[1] + a[2]);
	
	for (int i = 3; i < n; i++) {
		maxs[i] = max(a[i] + maxs[i - 2], a[i] + a[i - 1] + maxs[i - 3]);	//두칸 건너뜀, 한칸 건너뜀 비교

	}

	printf("%d", maxs[n - 1]);
	

	getchar();
	getchar();
	return 0;
}
​
