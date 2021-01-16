#include <iostream>
#include <stdio.h>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;
int start[100000] = { 0 };
int End[100000] = { 0 };

void quickSort(int i, int j)
{
	if (i >= j) return;
	int pivot = End[(i + j) / 2];
	int left = i;
	int right = j;
	while (left <= right)
	{
		while (End[left] < pivot) left++;
		while (End[right] > pivot) right--;
		if (left <= right)
		{
			swap(End[left], End[right]);
			swap(start[left], start[right]);
			left++; right--;
		}
	}
	quickSort(i, right);
	quickSort(left, j);
}
int main() {
	int n, count = 0, index = 0, start_value = -1, end_value;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &(start[i]), &(End[i]));
	quickSort(0, n - 1);

	while (index < n) {
		end_value = End[index];
		int flag = 0, same = 0;
		while (End[index] == end_value) {
			if (start_value <= start[index]) {
				if (end_value == start[index]) same += 1;
				else flag = 1;
			}
			index++;
		}
		if (flag > 0) {
			count += 1;
			start_value = end_value;
		}
		if (same > 0) {
			count += same;
			if (flag == 0) start_value = end_value;
		}
	}
	printf("%d", count);
	return 0;
}
