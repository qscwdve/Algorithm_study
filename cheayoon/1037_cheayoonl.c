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


int num;	//N의 진짜 약수의 개수
int nums;	//N의 진짜 약수
int h[1000000];	//진짜 약수를 담는 곳
int p, q;	//곱할 숫자
int main() {
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &nums);
		if ((nums * num) % num == 0) {	
			h[nums] = 1;
		}
	}


	for (int j = 0; j < 1000000; j++) {
		if (h[j] == 1) {
			p = j;
			break;
		}
	}

	for (int j = 1000000; j > 0; j--) {
		if (h[j] == 1) {
			q = j;
			break;
		}
	}
	printf("%d", p * q);

	getchar();
	getchar();
	return 0;
}
​
