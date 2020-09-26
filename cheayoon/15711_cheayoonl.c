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

int T;	//테스트 케이스의 수
int A, B;	//끈의 길이를 나타내는 정수
int total;	//total은 최대 4*10^12
int h[4000000] = { 0 };

int isnumber(int n) {

	if (n <= 4000000) {
		for (int i = 2; i < n + 1; i++) {
			if (h[i] == n) {
				return 1;
			}
		}
		return 0;
	}
	else if (n > 4000000) {
		for (int i = 2; i < 4000000; i++) {
			
			if (h[i] != 0 && (n % h[i]) == 0) { //n을 h[i]로 나누었을때 나머지가 0이면

				return 0; //소수가 아니므로 0반환(h[i]가 약수이므로 n은 소수가 아님)
			}
		}

		
		return 1;
	}
}


int main() {
	
	scanf("%d", &T);
	int totals;

	//배열 초기화
	for (int i = 2; i < 4000000; i++) {
		h[i] = i;
	}

	for (int i = 2; i < 4000000; i++) {
		if (h[i] == 0) {
			continue;
		}
		for (int j = i + i; j < 4000000; j += i) { // i를 제외한 i의 배수들은 0으로 체크
												 //2배수, 3배수.. 제거
			h[j] = 0;

		}


	}



	for (int i = 0; i < T; i++) {
		scanf("%d %d", &A, &B);

		total = A + B;
		totals = total - 2;

		if (total >= 4 && total % 2 == 0) {	//4이상, 짝수
			printf("YES\n");
		}
		else if (total >= 4 && isnumber(totals)) {	//홀수면 total - 2 한 값이 소수이면
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}


	getchar();
	getchar();

	return 0;
}
