#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#pragma warning (disable:4996)
using namespace std;

int total[100000] = { 0 };
void quickSort(int i, int j);
char name[100000][11] = { 0 };
int main() {
	int N;
	scanf("%d", &N); getchar();
	for (int i = 0; i < N; i++) {
		scanf("%s", name[i]);
		int m, E, K;
		scanf("%d", &K); scanf("%d", &E); scanf("%d", &m);
		total[i] += m + (K + 1)*10000 + (101 - E)*100;
		getchar();
	}
	quickSort(0, N - 1);
	for (int i = 0; i < N; i++) printf("%s\n", name[i]);
	
	return 0;
}
void quickSort(int i, int j){
	if (i >= j) return;
	int pivot = total[(i + j) / 2];
	char pivot_name[11] = { 0 };
	strcpy(pivot_name, name[(i + j) / 2]);
	int left = i;
	int right = j;
	while (left <= right){
		while (total[left] > pivot || (total[left] == pivot && strcmp(name[left], pivot_name) < 0)) left++;
		while (total[right] < pivot || (total[right] == pivot && strcmp(name[right], pivot_name) > 0)) right--;
		if (left <= right){
			swap(total[left], total[right]);
			swap(name[left], name[right]);
			left++; right--;
		}
	}
	quickSort(i, right);
	quickSort(left, j);
}