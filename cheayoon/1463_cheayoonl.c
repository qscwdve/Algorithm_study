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


int num;
int counts = 0;


int main() {
	scanf("%d", &num);

	while (num != 1) {
		if ((num - 1) % 3 == 0) {
			num = num - 1;
			counts++;
		}
		else if (num % 3 == 0) {
			num = num / 3;
			counts++;
		}
		else if (num % 2 == 0) {
			num = num / 2;
			counts++;
		}
	}

	printf("%d", counts);


	getchar();
	getchar();
	return 0;
}
