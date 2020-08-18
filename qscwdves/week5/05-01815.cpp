#include <iostream>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

void Binaray_Search(int num);
int num_N[500000] = { 0 }, num_M[500000] = { 0 };
int N, M;
int main() {
	int temp;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		num_N[i] = temp;
	}
	sort(num_N, num_N + N );
	
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &temp);
		num_M[i] = temp;
	}

	for (int i = 0; i < M; i++) {
		if (num_M[i] >= num_N[0] && num_M[i] <= num_N[N-1]) Binaray_Search(num_M[i]);
		else printf("0 ");
	}

	return 0;
}
void Binaray_Search(int num) {   
	int middle = N / 2, left = 0, right = N - 1;

	while (left <= right) {
		if (num_N[middle] == num) {
			printf("1 ");
			return;
		}
		else {
			if(num_N[middle] < num) left = middle + 1;
			else right = middle - 1;
			middle = (left + right) / 2;
		}
	}
	printf("0 ");
	return;
}
