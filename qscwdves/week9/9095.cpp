#include <iostream>
#include <stdio.h>
#pragma warning (disable: 4996)
using namespace std;

int Factorial[11] = { 0 };
int same_permutation(int one, int two, int three);
int method(int num);

int main() {
	int T, n;
	scanf("%d", &T);

	Factorial[0] = 1;
	for (int i = 1; i <= 10; i++) Factorial[i] = Factorial[i - 1] * i;

	while (T-- > 0) {
		scanf("%d", &n);
		printf("%d\n", method(n));
	}
	
	return 0;
}
int method(int num) {
	int sum = 0;
	for (int three = 0; three <= num / 3; three++) {
		int remainder = num - 3 * three;
		for (int two = 0; two <= remainder / 2; two++) {
			sum += same_permutation(remainder - 2 * two, two, three);
		}
	}
	return sum;
}
int same_permutation(int one, int two, int three) {
	return Factorial[one + two + three] / (Factorial[one] * Factorial[two] * Factorial[three]);
}
