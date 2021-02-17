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
#include <string>
#include <cstdlib>

#pragma warning (disable:4996)

using namespace std;

int N, results = 0;

int main() {

	scanf("%d", &N);

	vector<int> v(N + 2);
	
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < N; i++) {
		if (v[i] == 1) {
			results++;
			if (v[i + 1] == 1) {
				v[i + 1] = 0;
			}
			else {
				v[i + 1] = 1;
			}

			if (v[i + 2] == 1) {
				v[i + 2] = 0;
			}
			else {
				v[i + 2] = 1;
			}
		}
	}

	cout << results << endl;



	
	return 0;
}
