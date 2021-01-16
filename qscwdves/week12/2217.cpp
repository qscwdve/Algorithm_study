#include <iostream>
#include <stdio.h>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int loop[100000] = { 0 };
int main() {
	int N, max = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &(loop[i]));
	sort(loop, loop + N);

	for (int i = N; i > 0; i--) if (max < loop[N - i] * i) max = loop[N - i] * i;
	
	printf("%d", max);
	return 0;
}
