#include <iostream>
#pragma warning (disable:4996)
using namespace std;

int main() {
	int n, num[1000] = { 0 }, temp;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		num[i] = temp;
	}
	for (int i = 0; i < n; i++) {
		for (int k = i + 1; k < n; k++) {
			if (num[i] > num[k]) {
				int temp2 = num[i];
				num[i] = num[k];
				num[k] = temp2;
			}
		}
		printf("%d\n", num[i]);
	}
	return 0;
}
