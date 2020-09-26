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


//M이상 N이하의 소수를 모두 출력

int M;
int N;
int h[1000000];
int main() {
	scanf("%d", &M);
	scanf("%d", &N);



	//배열 초기화
	for (int i = 2; i < 1000000; i++) {
		h[i] = i;
	}


	for (int i = 2; i < 1000000; i++) {
		if (h[i] == 0) {
			continue;
		}
		for (int j = i + i; j < N + 1; j += i) { // i를 제외한 i의 배수들은 0으로 체크
												 //2배수, 3배수.. 제거
			h[j] = 0;

		}


	}

	for (int i = M; i < N + 1; i++) {
		if (h[i] != 0) {
			printf("%d\n", i);
		}
	}




	getchar();
	getchar();
	return 0;
}
