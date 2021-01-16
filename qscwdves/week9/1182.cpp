#include <iostream>
#include <stdio.h>
#pragma warning (disable: 4996)

int num_str[20] = { 0 }, ans = 0, N, S;
void subsequence(int order, int remainder) {
	remainder -=  num_str[order];
	if (remainder == 0) ans++;
	if (order < N - 1) {
		for (int i = order + 1; i < N; i++) subsequence(i, remainder);
	}
}
int main() {
	scanf("%d", &N);
	scanf("%d", &S);
	for (int i = 0; i < N; i++) scanf("%d", (num_str + i));       
	for (int i = 0; i < N; i++) subsequence(i, S);        
	printf("%d", ans);
	return 0;
}
