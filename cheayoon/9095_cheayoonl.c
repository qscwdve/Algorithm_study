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



int T, N;	//테스트의 개수T, 정수n (양수, 11보다 작음)
int result;
int c[11];


int cal(void) {	//n이하의 m이하인 자연수로 분할
	c[1] = 1;	//1
	c[2] = 2;	//1 + 1, 2
	c[3] = 4;	//1 + 1 + 1, 1 + 2, 2 + 1, 3

	for (int i = 4; i <= N; i++) {
		c[i] = c[i - 1] + c[i - 2] + c[i - 3];
	}
	return c[N];

}

int main() {
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &N);


		result = cal();

		printf("%d\n", result);
	}





	getchar();
	getchar();
	return 0;
}
​
