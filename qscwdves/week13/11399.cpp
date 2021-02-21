#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int num[1000] = { 0 };
int main() {
	int N, sum = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &(num[i]));
    
	sort(num, num + N);
	for (int i = 0; i < N; i++) sum += num[i] * (N - i);
	printf("%d", sum);
    
	return 0;
}