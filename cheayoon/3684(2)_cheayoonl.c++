#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <tuple>
#include <time.h>
#include <math.h>
#include <cmath>
#include <string>
#include <cstdlib>

#pragma warning (disable:4996)

using namespace std;


int T;
int arr[202];

int main() {

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d", &arr[i]);
	}

	if (T == 1) {
		printf("%d", &arr[0]);	// a = 1, b = 0 인 경우로 고정
	}
	else {
		for (int b = 0; b < 10001; b++) {
			for (int a = 0; a < 10001; a++) {
				int flag = 0;
				for (int v = 1; v < T; v++) {
					int result1 = ((arr[v - 1] * a + b) % 10001 * a + b) % 10001;
					if (result1 != arr[v]) {
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					for (int i = 0; i < T; i++) {
						printf("%d\n", (arr[i] * a + b) % 10001);
					}
					return 0;
				}

			}
		}
	}



	return 0;
}
