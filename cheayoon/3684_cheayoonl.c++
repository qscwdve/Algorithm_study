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


int T, x1, a, b;
int arr[202];

int main() {

	scanf("%d", &T);

	// a, b에 랜덤수 생성
	a = rand() % 10000;
	b = rand() % 10000;
	for (int i = 1; i < (2 * T) + 1; i = i + 2) {
		scanf("%d", &arr[i]);
	}
	for (int i = 2; i < (2 * T) + 1; i = i + 2) {
		
		// xi = (a·xi-1 + b) mod 10001

		arr[i] = ((a * arr[i - 1]) + b) % 10001;
		if ((i / 2) * 2 == i) {
			cout << arr[i] << endl;
		}
	}




	return 0;
}
