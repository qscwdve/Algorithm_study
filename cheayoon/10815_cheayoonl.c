#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)


using namespace std;



int a[500001];


int num, nums, h;




int main() {

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &h);
		a[i] = h;	//a에 있는 수에 해당하는 b의 배열 수를 늘린다.
	}
	int nu = 0;
	scanf("%d", &nums);
	for (int i = 0; i < nums; i++) {
		scanf("%d", &h);
		//입력한 수에 맞춰..
		for (int j = 0; j < num; j++) {
			if (a[j] == h) {
				printf("%d ", 1);
				nu = 1;
			}
		}
		if (nu == 0) printf("%d ", 0);
		nu = 0;
	}










	getchar();
	getchar();
	return 0;
}
