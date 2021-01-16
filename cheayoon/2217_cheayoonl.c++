#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <tuple>
#include <time.h>
#include <math.h>
#include <utility>
#pragma warning (disable:4996)

using namespace std;


bool desc(int a, int b) {
	return a > b;
}

int max_arr(int arr[], int arr_len) {
	int max, i;

	max = arr[0];

	for (i = 1; i < arr_len; i++) {
		if (max < arr[i])
			max = arr[i];
	}

	return max;
}

int main() {

	int N;
	int a;
	int arr[100001];
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		arr[i] = a;
	}

    //내림차순으로 정렬
	sort(arr, arr + N, desc);

	
	for (int i = 0; i < N; i++) {
		arr[i] = arr[i] * (i + 1);
	}

	printf("%d\n", max_arr(arr, N));



	return 0;
}
