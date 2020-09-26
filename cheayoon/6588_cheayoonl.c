#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <tuple>
#include <time.h>
#pragma warning (disable:4996)

using namespace std;

int a;
int N;
int h[1000000];
int counts;
int p, q;
int c = 0, checks = 0;
int main() {
		//배열 초기화
	for (int i = 2; i < 1000000; i++) {
		h[i] = i;
	}

	

	while (1) {
		scanf("%d", &N);
		if (N == 0) {
			break;

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
		//2를 제외하면 모두 홀수인 소수이다.

		for (int i = 3; i < N + 1; i++) {
			for (int j = 3; j < N + 1; j++) {
				if (h[i] != 0) {
					c = h[i] + h[j];

					if (c == N) {
						counts++;
						p = h[i];
						q = h[j];
						i = N + 1;
						checks = 1;
						break;
						
					}
					else {
						c = 0;
					}



					
				}


			}
		}
		
		if (checks == 1) {
			printf("%d = %d + %d\n", N, p, q);
			checks = 0;
		}
		else {
			printf("Goldbach's conjecture is wrong.");
		}

	}


	getchar();
	getchar();

	return 0;
}
