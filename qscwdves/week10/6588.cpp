#include <iostream>
#include <stdio.h>
#include <math.h>
#pragma warning (disable:4996)
using namespace std;
void prime(int N);
int a[1000001] = { 0 };
void find(int N);
int main() {
	int N = 1;

	prime(1000000);
	scanf("%d", &N);

	while (N != 0) {
		find(N);
		scanf("%d", &N);
	}

	return 0;
}
void prime(int N) {
	for (int i = 2; i <= N; i++) {
		if (a[i] == 1) continue;
		for (int j = i + i; j <= N; j += i) {
			a[j] = 1;
		}
	}
}
void find(int N) {
	int max = (int)(N / 2) - 1;
	for (int i = N-3; i > max; i -= 2) {
		if (a[i] == 0 && a[N - i] == 0) {
			printf("%d = %d + %d\n", N, N - i, i);
			return;
		}
	}
	printf("Goldbach's conjecture is wrong\n");
	return;
}
