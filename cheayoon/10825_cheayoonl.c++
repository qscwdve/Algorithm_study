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
#pragma warning (disable:4996)

using namespace std;

int N;
string str;



typedef struct STU {   // 구조체 이름은 _Person
	string name;	//이름
	int kor,	//국어점수
		eng,	//영어점수
		math;	//수학점수
} STU;

bool cmp(STU a, STU b) {

	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math) {
				if (a.name.compare(b.name) < 0) {	//오름차순 표현
					return true;
				}
				else {
					return false;
				}
			}
			return a.math > b.math;	//내림차순 표현
		}
		return a.eng < b.eng;	//오름차순 표현

	}
	return a.kor > b.kor;	//내림차순 표현
}


int main() {


	scanf("%d", &N);	//반 학생의 수
	vector<STU> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].name;

		scanf("%d", &v[i].kor);
		scanf("%d", &v[i].eng);
		scanf("%d", &v[i].math);

	}

	sort(v.begin(), v.end(), cmp);


	for (int i = 0; i < N; i++) {
		printf("%s\n", v[i].name.c_str());
	}



	return 0;
}
