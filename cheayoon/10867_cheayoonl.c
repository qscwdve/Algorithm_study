#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;


int num, h;
int a[1002];	//-1000~ 0까지의 수를 저장
int b[1001];	//1~ 1000까지의 수를 저장

int main() {

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &h);
		if (h <= 0) {	//a배열에 저장
			a[-1 * h] += 1;
		}
		else if (h > 0) {	//b배열에 저장
			b[h] += 1;
		}
	}


	for (int i = 1002; i >= 0; i--) {
		if (a[i] != 0) {
			printf("%d ", -(i));
		}

	}

	for (int i = 0; i < 1001; i++) {
		if (b[i] != 0) {
			printf("%d ", i);
		}

	}


	getchar();
	getchar();
	return 0;
}
​
