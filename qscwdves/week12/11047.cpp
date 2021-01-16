#include <iostream>
#include <stdio.h>
#pragma warning (disable:4996)
using namespace std;

int N[10] = { 0 };

int main() {
	int k, num, count = 0, div;

	scanf("%d %d", &num, &k);

	for (int i = 0; i < num; i++) scanf("%d", &(N[i]));

	for (int i = num - 1; i >= 0; i--) {
	  if (N[i] <= k) {
		  div = int(k / N[i]);
			count += div;
			k -= div * N[i];
		}
		if (k == 0) break;
	}
	printf("%d", count);
	return 0;
}
