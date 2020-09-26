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


int N;
int h[1000000];
int counts;
int main() {
	
	scanf("%d", &N);
	if (N == 1) {
		printf("%d", 0);
		getchar();
		getchar();
		return 0;
	}

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

	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (h[i] != 0) {

				if (h[i] == N) counts++;
				if (h[i] >= N) break;

			

				h[i] += h[i + j];
			}


		}
	}

	printf("%d", counts);


	getchar();
	getchar();

	return 0;
}

​
