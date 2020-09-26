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


int num;	//테스트 개수
int h;
int nums[41];	//N은 40보다 작거나 같은 자연수 또는 0이다.

int fibonacci(int n) {
	if (n == 0) {
		nums[0] = 0;
		return 0;
	}
	else if (n == 1) {
		nums[1] = 1;
		return 1;
	}
	if (nums[n] != 0) {
		return nums[n];
	}
	else {
		return nums[n] = fibonacci(n - 1) + fibonacci(n - 2);

	}
}

int main() {
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &h);



		if (h == 0) {
			printf("%d %d\n", 1, 0);
		}
		else if (h == 1) {
			printf("%d %d\n", 0, 1);
		}
		else {	//h - 1과 h - 2를 생성해서 그것들을 다시 진행시킨다.
			fibonacci(h);
			printf("%d %d\n", nums[h - 1], nums[h]);	//왼쪽은 0이 출력되는 횟수, 오른쪽은 1이 출력되는 횟수
		}







	}

	

	getchar();
	getchar();
	return 0;
}
​
