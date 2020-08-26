#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#pragma warning (disable:4996)


using namespace std;



int b[10001];


int num, h;




int main() {

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &h);
		b[h - 1] += 1;	//a에 있는 수에 해당하는 b의 배열 수를 늘린다.
	}





	for (int i = 0; i < 10000; i++) {
		while (b[i] != 0) {
			printf("%d\n", i + 1);
			b[i]--;
		}

	}





	getchar();
	getchar();
	return 0;
}
