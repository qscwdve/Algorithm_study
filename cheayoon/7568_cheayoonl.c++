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

int T, tmp = 0;

struct STU {
	int weight,	//몸무게
		tall,	//키
		order,	//순서
		results;//결과
};

bool cmp(STU a, STU b) {
	if (a.weight == b.weight) {
		return a.tall > b.tall;
	}
	return a.weight > b.weight;	//내림차순 표현
}

bool cmp2(STU a, STU b) {

	return a.order < b.order;	//오름차순 표현
}


int main() {

	scanf("%d", &T);
	vector<STU> v(T);


	for (int i = 0; i < T; i++) {
		cin >> v[i].weight; 
		cin >> v[i].tall;
		v[i].order = i;
	}

	sort(v.begin(), v.end(), cmp);
	v[0].results = 1;
	for (int i = 1; i < T; i++) {
		//cout << i << endl;
		/*
		if (v[i].weight == v[i - 1].weight) {
			if (v[i].tall < v[i - 1].tall) {
				a[i] = i + 1;
			}
			else {
				a[i] = a[i - 1];
			}
		}
		*/

		
		if (v[i].tall >= v[i - 1].tall) {
			v[i].results = v[i - 1].results;
		}
		else {
			v[i].results = i + 1;
		}
		

	}

	sort(v.begin(), v.end(), cmp2);
	for (int i = 0; i < T; i++) {
		printf("%d ", v[i].results);
	
	}

	return 0;
}
