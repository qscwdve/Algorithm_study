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

struct STU {
	double a;
};

int N;

bool cmp(STU a, STU b) {

	return a.a < b.a;	//오름차순 표현
}


int main() {

	scanf("%d", &N);
	vector<STU> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].a;
	}

	sort(v.begin(), v.end(), cmp);


	for (int i = 0; i < 7; i++) {
		printf("%.3f\n", v[i].a);
	}



	
	return 0;
}
