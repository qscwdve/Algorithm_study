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
	int dd,			//생일 (일)
		mm,			//생일 (월)
		yyyy;		//생일 (연도)
} STU;

bool cmp(STU a, STU b) {
	if (a.yyyy == b.yyyy) {
		if (a.mm == b.mm) {
			return a.dd < b.dd;
		}
		return a.mm < b.mm;
	}
	return a.yyyy < b.yyyy;
}




int main() {
	scanf("%d", &N);
	vector<STU> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].name;

		scanf("%d", &v[i].dd);
		scanf("%d", &v[i].mm);
		scanf("%d", &v[i].yyyy);
	}

	
	sort(v.begin(), v.end(), cmp);


	//첫째 줄에 가장 나이가 적은 사람의 이름 
	printf("%s\n", v[N-1].name.c_str());
	
    //둘째 줄에 가장 나이가 많은 사람 이름을 출력
	printf("%s\n", v[0].name.c_str());
	
	
	

	return 0;
}
