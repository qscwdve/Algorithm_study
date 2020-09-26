#include <iostream>
#include <stdio.h>
#pragma warning (disable:4996)
using namespace std;

void Euclidean(int a,int b);
void least_common_multiple(int a, int b);

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	Euclidean(N, M);
	least_common_multiple(N,M);
	return 0;
}
void least_common_multiple(int N, int M) {
	int a_count = 1, b_count = 1, a = 1, b = 2;
	while (a != b) {
		if (a < b) a = N*a_count++;
		else b = M*b_count++;
	}
	printf("%d\n", a);
}
void Euclidean(int a, int b) {
	int r_3, r_2, r_1;
	r_1 = a;
	r_2 = b;
	do {
		r_3 = r_1 % r_2;
		r_1 = r_2;
		r_2 = r_3;
	} while (r_3 != 0);
	printf("%d\n", r_1);
}
