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


int M, a;
int N, b;
int c;

int main() {
	scanf("%d", &M);
	scanf("%d", &N);

	a = M;
	b = N;

	//최대공약수 (첫째줄)
	//유클리드호제법


	while (N != 0) {
		c = M % N;
		M = N;
		N = c;
	}

	printf("%d\n", M);

	//최소공배수 (둘째줄)

	c = (a * b) / M;
	printf("%d", c);



	getchar();
	getchar();
	return 0;
}
​
