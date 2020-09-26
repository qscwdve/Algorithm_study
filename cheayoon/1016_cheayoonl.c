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
#pragma warning (disable:4996)

using namespace std;

int mins, maxs;
int a[1000000];	//max와 min사이의 개수는 최대 1000000개
int results = 0;

int main() {
	scanf("%d %d", &mins, &maxs);

	int p = 0;
	int q = 0;

	for (int i = 0; i <= maxs - mins; i++) {
		a[i] = mins + i;
	}

	p = 2;

	q = p * p;
	for (int i = 0; i < maxs - mins; i++) {
		if (i >= q && q % i == 0) {
			a[i] = 0;
			q += p * p;
		}
		if (q > maxs) {
			p++;
			q = p * p;
		}
	}

	for (int i = mins; i < maxs + 1; i++) {
		if (a[i] != 0) results++;
	}

	printf("%d", results);

	getchar();
	getchar();
	return 0;
}
