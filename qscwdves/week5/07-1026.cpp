#include <iostream>
#pragma warning (disable:4996)
using namespace std;

int main() {
	int n, check_B[101] = { 0 }, temp, check_A[101] = { 0 };
	int count_A = 0, count_B = 100, count_n = 0, ans = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		check_A[temp]++;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		check_B[temp]++;
	}
	while (count_n != n) {   
		while (check_B[count_B] == 0) count_B--;
		while (check_A[count_A] == 0) count_A++;

		ans = ans + count_A * count_B;
		check_B[count_B]--;
		check_A[count_A]--;
		count_n++;
	}
	printf("%d", ans);
	return 0;
}
