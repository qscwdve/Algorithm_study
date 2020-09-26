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


int tree[100001];
int t[100001];
int n, ans;
int cmp = 100000001;
int m = 100000001;
int a;
int gcd(int a, int b)
{
	if (b == 0) { 
		return a; 
	}

	return gcd(b, a%b);
}
int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n ; i++) {

		scanf("%d", &a);
		tree[i] = a;

		if (i >= 2) {
			t[i] = tree[i] - tree[i - 1]; //가로수 사이의 거리를 저장
			cmp = gcd(t[i], t[i - 1]);

		}
		if (m > cmp)
		m = cmp;
	}
	for (int i = 2; i <= n; i++) {
		ans += (t[i] / m) - 1;
	}
	printf("%d", ans);


	getchar();
	getchar();

	return 0;
}
