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


int N, S;
int num[20];
int counts = 0;

void cal(int p, int q) {
	q += num[p];	//숫자를 더한다


	if (p >= N) {
		return;	//함수를 종료한다
	}

	if (q == S) {
		counts++;
	}

	//지금의 숫자를 더할경우
	cal(p + 1, q);
	//지금의 숫자를 더하지 않을 경우
	cal(p + 1, q - num[p]);
}

int main() {
	scanf("%d %d", &N, &S);	//정수의 개수N과 정수S

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}


	cal(0, 0);

	printf("%d", counts);



	getchar();
	getchar();
	return 0;
}
​
