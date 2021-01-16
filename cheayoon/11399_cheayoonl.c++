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
#include <cmath>
#pragma warning (disable:4996)

using namespace std;

int N;
int arr[1000];
int results;

void quickSort(int i, int j) {
	if (i >= j) return;
	int pivot = arr[(i + j) / 2];
	int left = i;
	int right = j;

	while (left <= right) {
		while (arr[left] < pivot) left++;
		while (arr[right] > pivot) right--;
		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
	quickSort(i, right);
	quickSort(left, j);
}


int main() {


	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	quickSort(0, N - 1);
	results = arr[0];
	for (int i = 1; i < N; i++) {
		arr[i] += arr[i - 1];
		results += arr[i];
	}

	cout << results << endl;



	getchar();
	return 0;
}
​
